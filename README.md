# QT Application for Microstructural Analysis

**University of Passo Fundo (UPF)**<br>
**Student:** Yeun Haur Kang (193593)<br>
**Professor:** Dr. Marcos José Brusso<br>
**Course:** Programming Lab III

# Description

This application was developed to perform microstructural analysis of low- and medium-carbon steels (dual-phase carbon steels). To support this, a deep learning model based on convolutional neural networks was trained to perform semantic segmentation of the microstructure. At runtime, this trained model is loaded and exposed through a back-end API. A Qt6 C++ front-end sends an image to this endpoint to run inference, and receives the results that includes the segmented mask and the estimated fractions of ferrite and pearlite, which correspond to the material phases.

# Model Environment Configuration

To run this application, you must first start the server that exposes the model API endpoint. For this, you’ll need the following versions to load the model:

- Anaconda3
- Python (>3.9 <=3.11)
- TensorFlow (=2.15.1)
- NumPy (=1.26.4)
- {...}

Simply use the requirements.txt file to install all required libraries automatically. Follow the steps below:

```bash
$ conda create -n env "python<3.12" -y
$ conda activate env
$ python -m pip install -r requirements.txt
```

To start the server, run the Python script while the Anaconda virtual environment is active:

```bash
$ python server.py
```

**NOTE:** the environment was configured using Ubuntu 22.04.5 LTS distro.

# Run QT Application

To run the Qt application, you’ll need Qt Creator. You can install it with the following commands in the terminal:

```bash
$ sudo apt update && sudo apt upgrade -y
$ sudo apt install qtcreator cmake qt6-base-dev -y
```

Then, start Qt Creator:

```bash
$ qtcreator
```

Inside the application, go to Projects and click Open.<br>
Navigate to the folder where the project’s .pro file is located and select it.<br>
After that, simply run the project (Ctrl + R).

---