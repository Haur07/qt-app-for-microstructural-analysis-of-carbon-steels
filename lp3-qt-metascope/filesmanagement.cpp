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
        qInfo() << "Something went wrong. Couldn`t create save directory.";
        return;
    }
}

void FilesManagement::saveFile(const QPixmap &pix)
{
    qDebug() << "!!! DEBUG LINE => pix:" << pix;

    if (pix.isNull())
    {
        QMessageBox::warning(parent_, "Warning", "There is no image to save.");
        return;
    }

    const QString basePath = QDir::current().filePath(dirPath_);
    QDir baseDir(basePath);

    qDebug() << "!!! DEBUG LINE => basePath:" << basePath;
    qDebug() << "!!! DEBUG LINE => baseDir:" << baseDir;

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

    qDebug() << "!!! DEBUG LINE => targetPath:" << targetPath;

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
        QMessageBox::critical(parent_, "Error", "Coudln`t create the target directory.");
        return;
    }

    const QString imagePath = QDir(targetPath).filePath("original_image.png");

    qDebug() << "!!! DEBUG LINE => imagePath:" << imagePath;

    if (!pix.save(imagePath, "PNG"))
    {
        QMessageBox::critical(parent_, "Error", "Couldn`t save the image file.");
        return;
    }

    QJsonObject json;
    json["image_path"] = imagePath;
    json["save_time"] = QDateTime::currentDateTime().toString(Qt::ISODate);

    const QJsonDocument doc(json);
    const QString jsonPath = QDir(targetPath).filePath("results.json");

    qDebug() << "!!! DEBUG LINE => jsonPath:" << jsonPath;

    QFile f(jsonPath);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::critical(parent_, "Error", "Couldn`t write the JSON file.");
        return;
    }

    f.write(doc.toJson(QJsonDocument::Indented));
    f.close();

    QMessageBox::information(parent_, "Saved", "The file was successfully saved.");
}

void FilesManagement::loadFile(ImageProcessing &imgp)
{
    const QString basePath = QDir::current().filePath(dirPath_);
    QDir baseDir(basePath);

    qDebug() << "!!! DEBUG LINE => basePath:" << basePath;
    qDebug() << "!!! DEBUG LINE => baseDir:" << baseDir;

    if (!baseDir.exists())
    {
        QMessageBox::warning(parent_, "Warning", "No result directory found.");
        return;
    }

    const QString jsonPath = QFileDialog::getOpenFileName(parent_, "Open results", basePath, "Results (results.json);;JSON (*.json)");

    qDebug() << "!!! DEBUG LINE => jsonPath" << jsonPath;

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
    const QString saveTime = jsonObj.value("save_time").toString();

    if (imagePath.isEmpty())
    {
        QMessageBox::critical(parent_, "Error", "Missing 'image_path' in JSON file.");
        return;
    }

    if (!QFileInfo::exists(imagePath))
    {
        QMessageBox::critical(parent_, "Error", "Image file not found.");
        return;
    }

    if (!imgp.loadFromFile(imagePath))
    {
        QMessageBox::critical(parent_, "Error", "Couldn't load from saved image.");
        return;
    }

    const QString dirName = QFileInfo(jsonPath).dir().dirName();
    const QString info = saveTime.isEmpty()
            ? QString("Loaded results from '%1'.").arg(dirName)
            : QString("Loaded results from '%1' (saved at %2).").arg(dirName, saveTime);

    QMessageBox::information(parent_, "Loaded", info);
}
