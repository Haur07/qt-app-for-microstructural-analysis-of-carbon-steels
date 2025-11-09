/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *aboutMainVerticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *aboutTitleIconLabel;
    QLabel *aboutTitleLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *aboutDescriptionLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *aboutOkPushButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(425, 300);
        AboutDialog->setMinimumSize(QSize(425, 300));
        AboutDialog->setMaximumSize(QSize(425, 300));
        verticalLayoutWidget = new QWidget(AboutDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 402, 281));
        aboutMainVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        aboutMainVerticalLayout->setObjectName(QString::fromUtf8("aboutMainVerticalLayout"));
        aboutMainVerticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        aboutTitleIconLabel = new QLabel(verticalLayoutWidget);
        aboutTitleIconLabel->setObjectName(QString::fromUtf8("aboutTitleIconLabel"));
        aboutTitleIconLabel->setMinimumSize(QSize(32, 32));
        aboutTitleIconLabel->setMaximumSize(QSize(32, 32));
        aboutTitleIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/img_files/info_icon.png")));
        aboutTitleIconLabel->setScaledContents(true);
        aboutTitleIconLabel->setAlignment(Qt::AlignCenter);
        aboutTitleIconLabel->setWordWrap(false);

        horizontalLayout->addWidget(aboutTitleIconLabel);

        aboutTitleLabel = new QLabel(verticalLayoutWidget);
        aboutTitleLabel->setObjectName(QString::fromUtf8("aboutTitleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        aboutTitleLabel->setFont(font);

        horizontalLayout->addWidget(aboutTitleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        aboutMainVerticalLayout->addLayout(horizontalLayout);

        aboutDescriptionLabel = new QLabel(verticalLayoutWidget);
        aboutDescriptionLabel->setObjectName(QString::fromUtf8("aboutDescriptionLabel"));
        aboutDescriptionLabel->setMinimumSize(QSize(400, 123));
        aboutDescriptionLabel->setMaximumSize(QSize(400, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font1.setPointSize(12);
        aboutDescriptionLabel->setFont(font1);
        aboutDescriptionLabel->setAlignment(Qt::AlignCenter);
        aboutDescriptionLabel->setWordWrap(true);

        aboutMainVerticalLayout->addWidget(aboutDescriptionLabel, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        aboutMainVerticalLayout->addItem(verticalSpacer);

        aboutOkPushButton = new QPushButton(verticalLayoutWidget);
        aboutOkPushButton->setObjectName(QString::fromUtf8("aboutOkPushButton"));
        aboutOkPushButton->setMinimumSize(QSize(120, 20));
        aboutOkPushButton->setMaximumSize(QSize(120, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        aboutOkPushButton->setFont(font2);
        aboutOkPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        aboutOkPushButton->setFocusPolicy(Qt::WheelFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img_files/ok_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutOkPushButton->setIcon(icon);

        aboutMainVerticalLayout->addWidget(aboutOkPushButton, 0, Qt::AlignHCenter);


        retranslateUi(AboutDialog);
        QObject::connect(aboutOkPushButton, SIGNAL(clicked()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "About", nullptr));
        aboutTitleIconLabel->setText(QString());
        aboutTitleLabel->setText(QCoreApplication::translate("AboutDialog", "About this program", nullptr));
        aboutDescriptionLabel->setText(QCoreApplication::translate("AboutDialog", "This program is designed to perform microstructural analysis of carbon steels, specifically the SAE 1020 and SAE 1045 types, also known as dual-phase steels, with low and medium carbon content respectively. The software uses a trained machine learning model to perform image segmentation, returning results such as the total area fractions of pearlite and ferrite. These values are important in metallographic procedures to determine material quality and to verify whether the material meets the required specifications.", nullptr));
        aboutOkPushButton->setText(QCoreApplication::translate("AboutDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
