#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->aboutOkPushButton->setIcon(QIcon(":/images/ok_icon.png"));
    setFixedSize(425, 300);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
