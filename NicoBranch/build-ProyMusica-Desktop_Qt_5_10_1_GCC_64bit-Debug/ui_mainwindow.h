/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtIP;
    QLineEdit *txtPort;
    QPushButton *btnConnect;
    QPushButton *btnListen;
    QPlainTextEdit *txtReceive;
    QPlainTextEdit *txtSend;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnClear;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSend;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *BotonBombo;
    QPushButton *BotonHiHat;
    QGridLayout *gridLayout_4;
    QPushButton *BotonPlay;
    QSpinBox *BPSsb;
    QLabel *label;
    QPushButton *BotonCrash;
    QPushButton *BotonRedoblante;
    QGridLayout *gridLayout_5;
    QPushButton *BotonCorchea;
    QPushButton *BotonNegra;
    QPushButton *BotonBlanca;
    QPushButton *BotonSemiC;
    QLabel *label_2;
    QComboBox *CB_Tiempo_barrido;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *LE_Potencia_min;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(531, 483);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtIP = new QLineEdit(tab_4);
        txtIP->setObjectName(QStringLiteral("txtIP"));

        horizontalLayout_2->addWidget(txtIP);

        txtPort = new QLineEdit(tab_4);
        txtPort->setObjectName(QStringLiteral("txtPort"));

        horizontalLayout_2->addWidget(txtPort);

        btnConnect = new QPushButton(tab_4);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        horizontalLayout_2->addWidget(btnConnect);

        btnListen = new QPushButton(tab_4);
        btnListen->setObjectName(QStringLiteral("btnListen"));

        horizontalLayout_2->addWidget(btnListen);


        gridLayout_6->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        txtReceive = new QPlainTextEdit(tab_4);
        txtReceive->setObjectName(QStringLiteral("txtReceive"));
        txtReceive->setReadOnly(true);

        gridLayout_6->addWidget(txtReceive, 1, 0, 1, 1);

        txtSend = new QPlainTextEdit(tab_4);
        txtSend->setObjectName(QStringLiteral("txtSend"));
        txtSend->setMaximumSize(QSize(16777215, 150));

        gridLayout_6->addWidget(txtSend, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnClear = new QPushButton(tab_4);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout->addWidget(btnClear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSend = new QPushButton(tab_4);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setEnabled(false);

        horizontalLayout->addWidget(btnSend);


        gridLayout_6->addLayout(horizontalLayout, 3, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        BotonBombo = new QPushButton(tab_3);
        BotonBombo->setObjectName(QStringLiteral("BotonBombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BotonBombo->sizePolicy().hasHeightForWidth());
        BotonBombo->setSizePolicy(sizePolicy1);
        BotonBombo->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	background-color: rgb(114, 159, 207);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/kick-drum.png);\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"    min-width: 80px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(52, 101, 164);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_2->addWidget(BotonBombo, 0, 0, 1, 1);

        BotonHiHat = new QPushButton(tab_3);
        BotonHiHat->setObjectName(QStringLiteral("BotonHiHat"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BotonHiHat->sizePolicy().hasHeightForWidth());
        BotonHiHat->setSizePolicy(sizePolicy2);
        BotonHiHat->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(255, 245, 46);\n"
"	border: 2px solid #8f8f91;\n"
"	border-radius: 6px;\n"
"	\n"
"	image: url(:/iconos/hihat.png);\n"
"	/*background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"	min-width: 80px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 207, 60);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"	font-size: 20px;\n"
"}"));

        gridLayout_2->addWidget(BotonHiHat, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        BotonPlay = new QPushButton(tab_3);
        BotonPlay->setObjectName(QStringLiteral("BotonPlay"));
        sizePolicy.setHeightForWidth(BotonPlay->sizePolicy().hasHeightForWidth());
        BotonPlay->setSizePolicy(sizePolicy);
        BotonPlay->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(138, 226, 52);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	\n"
"	image: url(:/iconos/play.png);\n"
"    /*background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"    min-width: 80px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(115, 210, 22);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_4->addWidget(BotonPlay, 2, 0, 1, 1);

        BPSsb = new QSpinBox(tab_3);
        BPSsb->setObjectName(QStringLiteral("BPSsb"));
        BPSsb->setMinimum(60);
        BPSsb->setMaximum(180);

        gridLayout_4->addWidget(BPSsb, 1, 0, 1, 1);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 2, 2, 1);

        BotonCrash = new QPushButton(tab_3);
        BotonCrash->setObjectName(QStringLiteral("BotonCrash"));
        sizePolicy2.setHeightForWidth(BotonCrash->sizePolicy().hasHeightForWidth());
        BotonCrash->setSizePolicy(sizePolicy2);
        BotonCrash->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(239, 41, 41);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/crash2.png);\n"
"    /*background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"    min-width: 80px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(204, 0, 0);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_2->addWidget(BotonCrash, 1, 1, 1, 1);

        BotonRedoblante = new QPushButton(tab_3);
        BotonRedoblante->setObjectName(QStringLiteral("BotonRedoblante"));
        sizePolicy2.setHeightForWidth(BotonRedoblante->sizePolicy().hasHeightForWidth());
        BotonRedoblante->setSizePolicy(sizePolicy2);
        BotonRedoblante->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	background-color: rgb(173, 127, 168);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/snare-drum.png);\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"    min-width: 80px;\n"
"	font-size: 19px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(117, 80, 123);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_2->addWidget(BotonRedoblante, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        BotonCorchea = new QPushButton(tab_3);
        BotonCorchea->setObjectName(QStringLiteral("BotonCorchea"));
        sizePolicy.setHeightForWidth(BotonCorchea->sizePolicy().hasHeightForWidth());
        BotonCorchea->setSizePolicy(sizePolicy);
        BotonCorchea->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(252, 233, 79);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/corchea.png);\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(255, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_5->addWidget(BotonCorchea, 0, 2, 1, 1);

        BotonNegra = new QPushButton(tab_3);
        BotonNegra->setObjectName(QStringLiteral("BotonNegra"));
        sizePolicy.setHeightForWidth(BotonNegra->sizePolicy().hasHeightForWidth());
        BotonNegra->setSizePolicy(sizePolicy);
        BotonNegra->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(252, 233, 79);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/negra.png);\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(255, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_5->addWidget(BotonNegra, 0, 1, 1, 1);

        BotonBlanca = new QPushButton(tab_3);
        BotonBlanca->setObjectName(QStringLiteral("BotonBlanca"));
        sizePolicy.setHeightForWidth(BotonBlanca->sizePolicy().hasHeightForWidth());
        BotonBlanca->setSizePolicy(sizePolicy);
        BotonBlanca->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(252, 233, 79);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/blanca.png);\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(255, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_5->addWidget(BotonBlanca, 0, 0, 1, 1);

        BotonSemiC = new QPushButton(tab_3);
        BotonSemiC->setObjectName(QStringLiteral("BotonSemiC"));
        sizePolicy.setHeightForWidth(BotonSemiC->sizePolicy().hasHeightForWidth());
        BotonSemiC->setSizePolicy(sizePolicy);
        BotonSemiC->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(252, 233, 79);\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"	image: url(:/iconos/semicorchea.png);\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-color: rgb(255, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        gridLayout_5->addWidget(BotonSemiC, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 2, 0, 1, 3);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 5);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        CB_Tiempo_barrido = new QComboBox(tab_3);
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->addItem(QString());
        CB_Tiempo_barrido->setObjectName(QStringLiteral("CB_Tiempo_barrido"));
        CB_Tiempo_barrido->setEditable(false);

        gridLayout_3->addWidget(CB_Tiempo_barrido, 1, 1, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 3, 1, 1);

        LE_Potencia_min = new QLineEdit(tab_3);
        LE_Potencia_min->setObjectName(QStringLiteral("LE_Potencia_min"));

        gridLayout_3->addWidget(LE_Potencia_min, 1, 4, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        txtIP->setText(QApplication::translate("MainWindow", "localhost", nullptr));
        txtPort->setText(QApplication::translate("MainWindow", "3000", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        btnListen->setText(QApplication::translate("MainWindow", "Listen", nullptr));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        btnSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Conexi\303\263n", nullptr));
        BotonBombo->setText(QString());
        BotonHiHat->setText(QString());
        BotonPlay->setText(QString());
        label->setText(QApplication::translate("MainWindow", "BPS", nullptr));
        BotonCrash->setText(QString());
        BotonRedoblante->setText(QString());
        BotonCorchea->setText(QString());
        BotonNegra->setText(QString());
        BotonBlanca->setText(QString());
        BotonSemiC->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Tiempo de barrido:", nullptr));
        CB_Tiempo_barrido->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        CB_Tiempo_barrido->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        CB_Tiempo_barrido->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        CB_Tiempo_barrido->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));
        CB_Tiempo_barrido->setItemText(4, QApplication::translate("MainWindow", "5", nullptr));
        CB_Tiempo_barrido->setItemText(5, QApplication::translate("MainWindow", "6", nullptr));
        CB_Tiempo_barrido->setItemText(6, QApplication::translate("MainWindow", "7", nullptr));
        CB_Tiempo_barrido->setItemText(7, QApplication::translate("MainWindow", "8", nullptr));
        CB_Tiempo_barrido->setItemText(8, QApplication::translate("MainWindow", "9", nullptr));
        CB_Tiempo_barrido->setItemText(9, QApplication::translate("MainWindow", "10", nullptr));

        CB_Tiempo_barrido->setCurrentText(QApplication::translate("MainWindow", "1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "[seg]", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Potencia minima:", nullptr));
        LE_Potencia_min->setText(QApplication::translate("MainWindow", "2,30", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "M\303\272sica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
