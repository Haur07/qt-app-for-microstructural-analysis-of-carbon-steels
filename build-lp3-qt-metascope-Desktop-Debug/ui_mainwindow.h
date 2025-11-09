/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *iconTitleHorizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *titleIconLabel;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *descriptionLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectImagePushButton;
    QPushButton *processImagePushButton;
    QHBoxLayout *innerMainHorizontalLayout;
    QFrame *leftImageFrame;
    QLabel *leftImageLabel;
    QLabel *leftImagePlaceholderLabel;
    QFrame *rightMaskFrame;
    QLabel *rightMaskLabel;
    QLabel *rightMaskPlaceholderLabel;
    QHBoxLayout *innerMainTextHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *phasesResultsLabel;
    QHBoxLayout *lowerButtonsHorizontalLayout;
    QPushButton *saveResultsPushButton;
    QPushButton *loadResultsPushButton;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(944, 710);
        MainWindow->setMinimumSize(QSize(944, 710));
        MainWindow->setMaximumSize(QSize(944, 710));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img_files/info_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        actionAbout->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 924, 641));
        mainVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(0, 0, 0, 0);
        iconTitleHorizontalLayout = new QHBoxLayout();
        iconTitleHorizontalLayout->setObjectName(QString::fromUtf8("iconTitleHorizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        iconTitleHorizontalLayout->addItem(horizontalSpacer_2);

        titleIconLabel = new QLabel(verticalLayoutWidget);
        titleIconLabel->setObjectName(QString::fromUtf8("titleIconLabel"));
        titleIconLabel->setMinimumSize(QSize(48, 48));
        titleIconLabel->setMaximumSize(QSize(48, 48));
        titleIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/img_files/microscopy.png")));
        titleIconLabel->setScaledContents(true);

        iconTitleHorizontalLayout->addWidget(titleIconLabel, 0, Qt::AlignRight);

        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        titleLabel->setFont(font1);

        iconTitleHorizontalLayout->addWidget(titleLabel, 0, Qt::AlignHCenter);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        iconTitleHorizontalLayout->addItem(horizontalSpacer_3);


        mainVerticalLayout->addLayout(iconTitleHorizontalLayout);

        descriptionLabel = new QLabel(verticalLayoutWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font2.setPointSize(12);
        font2.setItalic(false);
        descriptionLabel->setFont(font2);

        mainVerticalLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        selectImagePushButton = new QPushButton(verticalLayoutWidget);
        selectImagePushButton->setObjectName(QString::fromUtf8("selectImagePushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        selectImagePushButton->setFont(font3);
        selectImagePushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/img_files/browse_file_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectImagePushButton->setIcon(icon1);

        horizontalLayout->addWidget(selectImagePushButton);

        processImagePushButton = new QPushButton(verticalLayoutWidget);
        processImagePushButton->setObjectName(QString::fromUtf8("processImagePushButton"));
        processImagePushButton->setFont(font3);
        processImagePushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/img_files/gear_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        processImagePushButton->setIcon(icon2);

        horizontalLayout->addWidget(processImagePushButton);


        mainVerticalLayout->addLayout(horizontalLayout);

        innerMainHorizontalLayout = new QHBoxLayout();
        innerMainHorizontalLayout->setSpacing(5);
        innerMainHorizontalLayout->setObjectName(QString::fromUtf8("innerMainHorizontalLayout"));
        innerMainHorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        innerMainHorizontalLayout->setContentsMargins(-1, 0, -1, -1);
        leftImageFrame = new QFrame(verticalLayoutWidget);
        leftImageFrame->setObjectName(QString::fromUtf8("leftImageFrame"));
        leftImageFrame->setMinimumSize(QSize(450, 450));
        leftImageFrame->setFrameShape(QFrame::Box);
        leftImageFrame->setFrameShadow(QFrame::Raised);
        leftImageFrame->setLineWidth(1);
        leftImageLabel = new QLabel(leftImageFrame);
        leftImageLabel->setObjectName(QString::fromUtf8("leftImageLabel"));
        leftImageLabel->setGeometry(QRect(0, 0, 460, 450));
        leftImageLabel->setMinimumSize(QSize(460, 450));
        leftImageLabel->setMaximumSize(QSize(460, 450));
        QPalette palette;
        QBrush brush(QColor(156, 156, 156, 128));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        leftImageLabel->setPalette(palette);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        leftImageLabel->setFont(font4);
        leftImageLabel->setFrameShape(QFrame::NoFrame);
        leftImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/img_files/image_placeholder.png")));
        leftImageLabel->setScaledContents(true);
        leftImageLabel->setAlignment(Qt::AlignCenter);
        leftImagePlaceholderLabel = new QLabel(leftImageFrame);
        leftImagePlaceholderLabel->setObjectName(QString::fromUtf8("leftImagePlaceholderLabel"));
        leftImagePlaceholderLabel->setGeometry(QRect(130, 60, 200, 20));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftImagePlaceholderLabel->sizePolicy().hasHeightForWidth());
        leftImagePlaceholderLabel->setSizePolicy(sizePolicy);
        leftImagePlaceholderLabel->setMinimumSize(QSize(200, 20));
        leftImagePlaceholderLabel->setMaximumSize(QSize(200, 20));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 40));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        leftImagePlaceholderLabel->setPalette(palette1);
        leftImagePlaceholderLabel->setFont(font4);
        leftImagePlaceholderLabel->setAlignment(Qt::AlignCenter);

        innerMainHorizontalLayout->addWidget(leftImageFrame);

        rightMaskFrame = new QFrame(verticalLayoutWidget);
        rightMaskFrame->setObjectName(QString::fromUtf8("rightMaskFrame"));
        rightMaskFrame->setMinimumSize(QSize(450, 450));
        rightMaskFrame->setFrameShape(QFrame::Box);
        rightMaskFrame->setFrameShadow(QFrame::Raised);
        rightMaskLabel = new QLabel(rightMaskFrame);
        rightMaskLabel->setObjectName(QString::fromUtf8("rightMaskLabel"));
        rightMaskLabel->setGeometry(QRect(0, 0, 460, 450));
        rightMaskLabel->setMinimumSize(QSize(460, 450));
        rightMaskLabel->setMaximumSize(QSize(460, 450));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        rightMaskLabel->setPalette(palette2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font5.setPointSize(15);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(75);
        font5.setStrikeOut(false);
        rightMaskLabel->setFont(font5);
        rightMaskLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/img_files/image_placeholder.png")));
        rightMaskLabel->setScaledContents(true);
        rightMaskLabel->setAlignment(Qt::AlignCenter);
        rightMaskPlaceholderLabel = new QLabel(rightMaskFrame);
        rightMaskPlaceholderLabel->setObjectName(QString::fromUtf8("rightMaskPlaceholderLabel"));
        rightMaskPlaceholderLabel->setGeometry(QRect(130, 60, 200, 20));
        sizePolicy.setHeightForWidth(rightMaskPlaceholderLabel->sizePolicy().hasHeightForWidth());
        rightMaskPlaceholderLabel->setSizePolicy(sizePolicy);
        rightMaskPlaceholderLabel->setMinimumSize(QSize(200, 20));
        rightMaskPlaceholderLabel->setMaximumSize(QSize(200, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        rightMaskPlaceholderLabel->setPalette(palette3);
        rightMaskPlaceholderLabel->setFont(font4);
        rightMaskPlaceholderLabel->setAlignment(Qt::AlignCenter);

        innerMainHorizontalLayout->addWidget(rightMaskFrame);


        mainVerticalLayout->addLayout(innerMainHorizontalLayout);

        innerMainTextHorizontalLayout = new QHBoxLayout();
        innerMainTextHorizontalLayout->setObjectName(QString::fromUtf8("innerMainTextHorizontalLayout"));
        innerMainTextHorizontalLayout->setContentsMargins(0, 5, 0, 5);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        innerMainTextHorizontalLayout->addItem(horizontalSpacer);

        phasesResultsLabel = new QLabel(verticalLayoutWidget);
        phasesResultsLabel->setObjectName(QString::fromUtf8("phasesResultsLabel"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        phasesResultsLabel->setFont(font6);

        innerMainTextHorizontalLayout->addWidget(phasesResultsLabel, 0, Qt::AlignHCenter);


        mainVerticalLayout->addLayout(innerMainTextHorizontalLayout);

        lowerButtonsHorizontalLayout = new QHBoxLayout();
        lowerButtonsHorizontalLayout->setObjectName(QString::fromUtf8("lowerButtonsHorizontalLayout"));
        saveResultsPushButton = new QPushButton(verticalLayoutWidget);
        saveResultsPushButton->setObjectName(QString::fromUtf8("saveResultsPushButton"));
        saveResultsPushButton->setEnabled(true);
        saveResultsPushButton->setMaximumSize(QSize(16777215, 16777215));
        saveResultsPushButton->setFont(font3);
        saveResultsPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/img_files/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveResultsPushButton->setIcon(icon3);

        lowerButtonsHorizontalLayout->addWidget(saveResultsPushButton);

        loadResultsPushButton = new QPushButton(verticalLayoutWidget);
        loadResultsPushButton->setObjectName(QString::fromUtf8("loadResultsPushButton"));
        loadResultsPushButton->setFont(font3);
        loadResultsPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/img_files/file_upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadResultsPushButton->setIcon(icon4);

        lowerButtonsHorizontalLayout->addWidget(loadResultsPushButton);


        mainVerticalLayout->addLayout(lowerButtonsHorizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 20));
        menubar->setMinimumSize(QSize(944, 20));
        menubar->setMaximumSize(QSize(944, 20));
        menubar->setDefaultUp(false);
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuAbout->setFont(font6);
        menuAbout->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MetaScope", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        titleIconLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Carbon Steel Microstructure Analyzer", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "Image processing for characterization of SAE 1020 and SAE 1045 carbon steels.", nullptr));
        selectImagePushButton->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        processImagePushButton->setText(QCoreApplication::translate("MainWindow", "Process Image", nullptr));
        leftImageLabel->setText(QString());
        leftImagePlaceholderLabel->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        rightMaskLabel->setText(QString());
        rightMaskPlaceholderLabel->setText(QCoreApplication::translate("MainWindow", "Result Mask", nullptr));
        phasesResultsLabel->setText(QCoreApplication::translate("MainWindow", "[ Ferrite: 0.00000% ][ Pearlite: 0.00000% ]", nullptr));
        saveResultsPushButton->setText(QCoreApplication::translate("MainWindow", "Save Results", nullptr));
        loadResultsPushButton->setText(QCoreApplication::translate("MainWindow", "Load Results", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
