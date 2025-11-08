#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionAbout->setIcon(QIcon(":/images/info_icon.png"));
    imgp_.setPreviewLabel(ui->leftImageLabel);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setFixedSize(944, 700);
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
