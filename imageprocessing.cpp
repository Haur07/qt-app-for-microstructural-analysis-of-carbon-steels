#include "imageprocessing.h"

#include <QObject>
#include <QFileDialog>
#include <QImageReader>
#include <QDir>
#include <QFileInfo>

#include <QDebug>

ImageProcessing::ImageProcessing(QLabel *previewLabel)
    : previewLabel_(previewLabel)
{
    setPreviewEmptyText();
}

void ImageProcessing::setPreviewLabel(QLabel *label)
{
    previewLabel_ = label;
    setPreviewEmptyText();

    qDebug() << "!!! DEBUG LINE => previewLabel:" << previewLabel_;
}

QString ImageProcessing::imageFilter()
{
    return QObject::tr("Images (*.png *.jpg *.jpeg *.tif *.tiff)");
}

bool ImageProcessing::selectAndLoad(QWidget *parent)
{
    const QString caption = QObject::tr("Select an image");
    const QString startDir = lastDir_.isEmpty() ? QDir::homePath() : lastDir_;

    qDebug() << "!!! DEBUG LINE => startDir:" << startDir;

    const QString file = QFileDialog::getOpenFileName(parent, caption, startDir, imageFilter());

    qDebug() << "!!! DEBUG LINE => file:" << file;

    if (file.isEmpty())
        return false;

    if (!loadFromFile(file))
        return false;

    lastDir_ = QFileInfo(file).absolutePath();

    qDebug() << "!!! DEBUG LINE => lastDir_:" << lastDir_;

    fitToLabel();
    return true;
}

bool ImageProcessing::loadFromFile(const QString &path)
{
    qDebug() << "!!! DEBUG LINE => path:" << path;

    QImageReader reader(path);
    reader.setAutoTransform(true);
    const QImage image = reader.read();
    if (image.isNull())
        return false;

    pix_ = QPixmap::fromImage(image);

    qDebug() << "pix_:" << pix_;

    if (!pix_.isNull())
        fitToLabel();

    return !pix_.isNull();
}

void ImageProcessing::fitToLabel()
{
    qDebug() << "!!! DEBUG LINE => previewLabel_:" << previewLabel_;

    if (!previewLabel_)
        return;

    if (pix_.isNull()) {
        setPreviewEmptyText();
        previewLabel_->setPixmap(QPixmap());
        return;
    }

    previewLabel_->setPixmap(pix_);
    previewLabel_->setText(QString());
}

void ImageProcessing::setPreviewEmptyText()
{
    if (previewLabel_) {
        previewLabel_->setAlignment(Qt::AlignCenter);
        previewLabel_->setText(QObject::tr("No image loaded"));
    }
}
