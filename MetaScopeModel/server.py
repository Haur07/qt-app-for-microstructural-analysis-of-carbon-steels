import io
import os
import cv2
import numpy as np

os.environ["TF_CPP_MIN_LOG_LEVEL"] = "2"
import tensorflow as tf

from pathlib import Path
from typing import TypeAlias
from fastapi import FastAPI, File, UploadFile, HTTPException
from fastapi.responses import StreamingResponse
from tensorflow.keras.models import load_model

Tensor: TypeAlias = tf.Tensor
Model: TypeAlias = tf.keras.models.Model
from numpy.typing import NDArray

app = FastAPI()

def iou_metric(y_true: Tensor, y_pred: Tensor, smooth: float = 1e-6) -> float:
    y_pred: Tensor = tf.cast(y_pred > 0.5, tf.float32)
    y_true: Tensor = tf.cast(y_true, tf.float32)
    
    intersection: Tensor = tf.reduce_sum(y_true * y_pred)
    union: Tensor = tf.reduce_sum(y_true) + tf.reduce_sum(y_pred) - intersection
    
    score = (intersection + smooth) / (union + smooth)
    return float(score.numpy())

CURRDIR: Path = Path.cwd()
MODEL_PATH: Path = CURRDIR / "model_file" / "unet_model_v1.keras"
MODEL: Model = load_model(MODEL_PATH, custom_objects={'iou_metric': iou_metric}, compile=False)

def preprocess_image(file: UploadFile) -> NDArray[np.uint8]:
    image_bytes = file.file.read()
    np_arr = np.frombuffer(image_bytes, np.uint8)
    image = cv2.imdecode(np_arr, cv2.IMREAD_GRAYSCALE)
    
    if image is None:
        raise ValueError("Invalid image.")

    image = cv2.resize(image, (256, 256))
    image = np.expand_dims(image, axis=(0, -1)).astype(np.float32) / 255.0
    return image

def predict(image_array: NDArray) -> tuple[float, float, NDArray[np.uint8]]:
    pred = MODEL.predict(image_array)
    pred = (pred > 0.5).astype(np.uint8)
    mask = np.squeeze(pred) * 255

    total_pixels = pred.size
    zeros = np.sum(pred == 0)
    pearlite = (zeros / total_pixels) * 100
    ferrite = 100 - pearlite

    return float(ferrite), float(pearlite), mask.astype(np.uint8)

@app.post("/predict", response_class=StreamingResponse)
async def prediction(file: UploadFile = File(...)) -> StreamingResponse:
    try:
        image_array = preprocess_image(file)
        ferrite, pearlite, mask = predict(image_array)

        success, buffer = cv2.imencode(".png", mask)
        if not success:
            raise ValueError("Coudn't code mask.")

        return StreamingResponse(
            content=io.BytesIO(buffer.tobytes()),
            media_type="image/png",
            headers={
                "ferrite": str(ferrite),
                "pearlite": str(pearlite)
            }
        )
    except Exception as e:
        raise HTTPException(status_code=400, detail=str(e))

if __name__ == "__main__":
    import uvicorn
    port: int = int(os.environ.get("PORT", 8080))
    uvicorn.run(app, host='0.0.0.0', port=port)
