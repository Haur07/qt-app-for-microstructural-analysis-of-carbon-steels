#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imageprocessing.h"

#include <QMainWindow>
#include <QIcon>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();
    void on_selectImagePushButton_clicked();

private:
    Ui::MainWindow *ui;
    ImageProcessing imgp_;
};
#endif // MAINWINDOW_H
