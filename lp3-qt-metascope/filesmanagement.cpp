#include "filesmanagement.h"
#include "imageprocessing.h"

#include <QInputDialog>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

FilesManagement::FilesManagement(QWidget *parent) : parent_(parent) {}

void FilesManagement::createDir(QDir root)
{
    if (root.exists(dirPath_))
    {
        QDir dir(dirPath_);
        qInfo() << "The directory already exists:" << dir.absolutePath();
        return;
    }

    if (root.mkdir(dirPath_))
    {
        QDir dir(dirPath_);
        qInfo() << "Save directory created:" << dir.absolutePath();
    }
    else
    {
        qInfo() << "Something went wrong. Couldn't create save directory.";
        return;
    }
}

void FilesManagement::saveFile(const QPixmap &pix, const QPixmap &mask, double ferrite, double pearlite)
{
    if (pix.isNull())
    {
        QMessageBox::warning(parent_, "Warning", "There is no image to save.");
        return;
    }

    const QString basePath = QDir::current().filePath(dirPath_);
    QDir baseDir(basePath);
    if (!baseDir.exists() && !QDir().mkpath(basePath))
    {
        QMessageBox::critical(parent_, "Error", "Coudn't create base save directory.");
        return;
    }

    const QString dirName = QInputDialog::getText(parent_, "Save Results", "Directory name:").trimmed();
    if (dirName.isEmpty())
    {
        QMessageBox::warning(parent_, "Warning", "Nothing was saved. Please, provide the directory name.");
        return;
    }

    const QString targetPath = baseDir.filePath(dirName);
    if (QDir(targetPath).exists())
    {
        QMessageBox::StandardButton reply = QMessageBox::question(
            parent_, "Overwrite?", QString("The directory '%1' already exists.\nDo you want to overwrite it?").arg(dirName),
            QMessageBox::Yes | QMessageBox::No
        );

        if (reply == QMessageBox::No) { return; }
    }

    if (!QDir().mkpath(targetPath))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't create the target directory.");
        return;
    }

    const QPixmap resizedPix = pix.scaled(256, 256, Qt::IgnoreAspectRatio);
    const QString imagePath = QDir(targetPath).filePath("original_image.png");
    if (!resizedPix.save(imagePath, "PNG"))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't save the image file.");
        return;
    }

    const QString maskPath = QDir(targetPath).filePath("result_mask.png");
    if (!mask.save(maskPath, "PNG"))
    {
        QMessageBox::warning(parent_, "Warning", "Couldn't save the mask file.");
        return;
    }

    QJsonObject json;
    json["image_path"] = imagePath;
    json["mask_path"] = maskPath;
    json["ferrite"] = QString::number(ferrite, 'f', 5);
    json["pearlite"] = QString::number(pearlite, 'f', 5);
    json["save_time"] = QDateTime::currentDateTime().toString(Qt::ISODate);

    const QJsonDocument doc(json);
    const QString jsonPath = QDir(targetPath).filePath("results.json");
    QFile f(jsonPath);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't write the JSON file.");
        return;
    }

    f.write(doc.toJson(QJsonDocument::Indented));
    f.close();

    QMessageBox::information(parent_, "Saved", "The file was successfully saved.");
}

void FilesManagement::loadFile(ImageProcessing &imgp, QPixmap &maskOut, double &ferriteOut, double &pearliteOut)
{
    const QString basePath = QDir::current().filePath(dirPath_);
    QDir baseDir(basePath);

    if (!baseDir.exists())
    {
        QMessageBox::warning(parent_, "Warning", "No result directory found.");
        return;
    }

    const QString jsonPath = QFileDialog::getOpenFileName(parent_, "Open results", basePath, "Results (results.json);;JSON (*.json)");
    if (jsonPath.isEmpty()) { return; }

    QFile f(jsonPath);
    if (!f.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't open the JSON file.");
        return;
    }

    const QByteArray data = f.readAll();
    f.close();

    const QJsonDocument json = QJsonDocument::fromJson(data);
    const QJsonObject jsonObj = json.object();

    const QString imagePath = jsonObj.value("image_path").toString();
    const QString maskPath = jsonObj.value("mask_path").toString();
    const QString saveTime = jsonObj.value("save_time").toString();

    bool okF = false;
    bool okP = false;
    ferriteOut = jsonObj.value("ferrite").toString().toDouble(&okF);
    pearliteOut = jsonObj.value("pearlite").toString().toDouble(&okP);

    if (!okF || !okP)
    {
        QMessageBox::critical(parent_, "Error", "Invalid 'ferrite' or 'pearlite' values in JSON file.");
        return;
    }

    if (imagePath.isEmpty())
    {
        QMessageBox::critical(parent_, "Error", "Missing 'image_path' in JSON file.");
        return;
    }

    if (maskPath.isEmpty())
    {
        QMessageBox::critical(parent_, "Error", "Missing 'mask_path' in JSON file.");
        return;
    }

    if (!QFileInfo::exists(imagePath))
    {
        QMessageBox::critical(parent_, "Error", "Image file not found.");
        return;
    }

    if (!QFileInfo::exists(maskPath))
    {
        QMessageBox::critical(parent_, "Error", "Mask file not found.");
        return;
    }

    if (!imgp.loadFromFile(imagePath))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't load saved image.");
        return;
    }

    QPixmap mask;
    if(!mask.load(maskPath))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't load saved mask.");
        return;
    }
    maskOut = mask;

    const QString dirName = QFileInfo(jsonPath).dir().dirName();
    const QString info = QString("Loaded results from '%1' (saved at %2).").arg(dirName, saveTime);

    QMessageBox::information(parent_, "Loaded", info);
}
