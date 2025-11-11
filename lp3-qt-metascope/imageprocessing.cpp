#include "imageprocessing.h"

#include <QObject>
#include <QFileDialog>
#include <QImageReader>
#include <QDir>
#include <QFileInfo>

#include <QDebug>

ImageProcessing::ImageProcessing(QLabel *previewLabel)
    : previewLabel_(previewLabel) {}

void ImageProcessing::setPreviewLabel(QLabel *label) { previewLabel_ = label; }
QString ImageProcessing::imageFilter() { return QObject::tr("Images (*.png *.jpg *.jpeg *.tif *.tiff)"); }

bool ImageProcessing::selectAndLoad(QWidget *parent)
{
    const QString caption = QObject::tr("Select an image");
    const QString startDir = lastDir_.isEmpty() ? QDir::homePath() : lastDir_;

    const QString file = QFileDialog::getOpenFileName(parent, caption, startDir, imageFilter());
    if (file.isEmpty())
        return false;
    if (!loadFromFile(file))
        return false;

    lastDir_ = QFileInfo(file).absolutePath();
    fitToLabel();
    return true;
}

bool ImageProcessing::loadFromFile(const QString &path)
{
    QImageReader reader(path);
    reader.setAutoTransform(true);
    const QImage image = reader.read();
    if (image.isNull())
        return false;

    pix_ = QPixmap::fromImage(image);
    if (!pix_.isNull())
        fitToLabel();

    return !pix_.isNull();
}

void ImageProcessing::fitToLabel()
{
    if (!previewLabel_)
        return;

    if (pix_.isNull()) {
        previewLabel_->setPixmap(QPixmap());
        return;
    }
    previewLabel_->setPixmap(pix_);
}
