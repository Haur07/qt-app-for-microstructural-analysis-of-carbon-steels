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

    connect(&api_, &APIConnection::predictionFinished, this, &MainWindow::onPredictionReady);
    connect(&api_, &APIConnection::networkError, this, &MainWindow::onNetworkError);

    api_.setEndpoint(QUrl(QStringLiteral("http://127.0.0.1:8080/predict")));
    api_.setTimeoutMs(60000);
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

    ui->leftImagePlaceholderLabel->setText(QString());
    ui->processImagePushButton->setEnabled(true);
}

void MainWindow::on_saveResultsPushButton_clicked()
{
    fm_.createDir(QDir::current());
    const QPixmap maskPix = ui->rightMaskLabel->pixmap(Qt::ReturnByValue);
    fm_.saveFile(imgp_.pixmap(), maskPix, ferrite_, pearlite_);
}


void MainWindow::on_loadResultsPushButton_clicked()
{
    QPixmap mask;
    double ferrite;
    double pearlite;

    fm_.loadFile(imgp_, mask, ferrite, pearlite);
    ui->leftImagePlaceholderLabel->setText(QString());

    if (!mask.isNull())
    {
        ui->rightMaskLabel->setPixmap(mask);
        ui->rightMaskPlaceholderLabel->setText(QString());
    }

    ui->phasesResultsLabel->setText(
        QString("[ Ferrite: %1% ][ Pearlite: %2% ]")
            .arg(ferrite, 0, 'f', 5)
            .arg(pearlite, 0, 'f', 5)
    );
}


void MainWindow::on_processImagePushButton_clicked()
{
    setCursor(Qt::BusyCursor);
    ui->saveResultsPushButton->setEnabled(false);
    ui->processImagePushButton->setEnabled(false);
    api_.predict(imgp_.pixmap());
}

void MainWindow::onPredictionReady(const QImage &mask, double ferrite, double pearlite)
{
    unsetCursor();
    ui->processImagePushButton->setEnabled(true);

    ferrite_ = ferrite;
    pearlite_ = pearlite;

    ui->rightMaskLabel->setPixmap(QPixmap::fromImage(mask));
    ui->rightMaskPlaceholderLabel->setText(QString());
    ui->leftImagePlaceholderLabel->setText(QString());
    ui->phasesResultsLabel->setText(
        QString("[ Ferrite: %1% ][ Pearlite: %2% ]")
            .arg(ferrite, 0, 'f', 5)
            .arg(pearlite, 0, 'f', 5)
    );
    ui->saveResultsPushButton->setEnabled(true);
}

void MainWindow::onNetworkError(const QString &msg)
{
    unsetCursor();
    ui->processImagePushButton->setEnabled(true);
    QMessageBox::critical(this, "Prediction error", msg);
}
