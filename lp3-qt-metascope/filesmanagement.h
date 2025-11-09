#ifndef FILESMANAGEMENT_H
#define FILESMANAGEMENT_H

#include <QMessageBox>
#include <QPixmap>
#include <QString>
#include <QDir>
#include <QDebug>

class ImageProcessing;

class FilesManagement
{
public:
    FilesManagement(QWidget *parent);

    void createDir(QDir root);
    void saveFile(const QPixmap &pix);
    void loadFile(ImageProcessing &imgp);

private:
    QWidget *parent_ = nullptr;
    const QString dirPath_ = "saved_results";
};
#endif // FILESMANAGEMENT_H
