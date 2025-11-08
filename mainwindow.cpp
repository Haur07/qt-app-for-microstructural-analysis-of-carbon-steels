#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setFixedSize(944, 650);
}

MainWindow::~MainWindow()
{
    delete ui;
}
