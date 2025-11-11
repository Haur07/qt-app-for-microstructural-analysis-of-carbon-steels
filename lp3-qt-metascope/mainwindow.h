#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imageprocessing.h"
#include "filesmanagement.h"
#include "apiconnection.h"

#include <QMainWindow>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsOpacityEffect>

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
    void on_saveResultsPushButton_clicked();
    void on_loadResultsPushButton_clicked();
    void on_processImagePushButton_clicked();

    void onPredictionReady(const QImage &mask, double ferrite, double pearlite);
    void onNetworkError(const QString &message);

private:
    Ui::MainWindow *ui;
    ImageProcessing imgp_;
    FilesManagement fm_;
    APIConnection api_;

    double ferrite_ = 0.0;
    double pearlite_ = 0.0;
};
#endif // MAINWINDOW_H
