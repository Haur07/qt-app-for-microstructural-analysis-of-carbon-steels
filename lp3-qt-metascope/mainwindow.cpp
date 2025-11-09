#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fm_(this)
{
    ui->setupUi(this);

    ui->actionAbout->setIcon(QIcon(":/images/img_files/info_icon.png"));
    ui->selectImagePushButton->setIcon(QIcon(":/images/img_files/browse_file_icon.png"));
    ui->processImagePushButton->setIcon(QIcon(":/images/img_files/gear_icon.png"));
    ui->saveResultsPushButton->setIcon(QIcon(":/images/img_files/save_icon.png"));
    ui->loadResultsPushButton->setIcon(QIcon(":/images/img_files/file_upload.png"));

    ui->processImagePushButton->setEnabled(false);
    ui->saveResultsPushButton->setEnabled(false);

    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setFixedSize(944, 710);

    imgp_.setPreviewLabel(ui->leftImageLabel);
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
    bool status = imgp_.selectAndLoad(this);
    if (!status)
    {
        QMessageBox::critical(this, "Error", "The file couldn't be loaded.");
        return;
    }

    ui->processImagePushButton->setEnabled(true);
    ui->saveResultsPushButton->setEnabled(true);
}

void MainWindow::on_saveResultsPushButton_clicked()
{
    fm_.createDir(QDir::current());
    fm_.saveFile(imgp_.pixmap());
}


void MainWindow::on_loadResultsPushButton_clicked()
{
    fm_.loadFile(imgp_);
}


void MainWindow::on_processImagePushButton_clicked()
{
    QMessageBox::warning(this, "Warning", "There's no functionality for this button yet.");
    return;
}

