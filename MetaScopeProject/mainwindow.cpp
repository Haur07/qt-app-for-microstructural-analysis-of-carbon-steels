#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionAbout->setIcon(QIcon(":/images/img_files/info_icon.png"));
    ui->selectImagePushButton->setIcon(QIcon(":/images/img_files/browse_file_icon.png"));
    ui->processImagePushButton->setIcon(QIcon(":/images/img_files/gear_icon.png"));
    ui->saveResultsPushButton->setIcon(QIcon(":/images/img_files/save_icon.png"));
    ui->loadResultsPushButton->setIcon(QIcon(":/images/img_files/file_upload.png"));
    imgp_.setPreviewLabel(ui->leftImageLabel);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setFixedSize(944, 710);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog *about = new AboutDialog(this);
    about->setAttribute(Qt::WA_DeleteOnClose);
    about->setModal(true);
    about->show();
}

void MainWindow::on_selectImagePushButton_clicked()
{
    imgp_.selectAndLoad(this);
}
