#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QPixmap>
#include <QLabel>
#include <QString>

class QWidget;

class ImageProcessing
{
public:
    explicit ImageProcessing(QLabel *previewLabel = nullptr);

    void setPreviewLabel(QLabel *label);
    bool selectAndLoad(QWidget *parent = nullptr);
    bool loadFromFile(const QString &path);
    void fitToLabel();

    const QPixmap &pixmap() const { return pix_; }
    QString currentDirectory() const { return lastDir_; }

private:
    static QString imageFilter();
    void setPreviewEmptyText();

private:
    QPixmap pix_;
    QLabel *previewLabel_ = nullptr;
    QString lastDir_;
};
#endif // IMAGEPROCESSING_H
