/********************************************************************************
** Form generated from reading UI file 'mainwindowserver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWSERVER_H
#define UI_MAINWINDOWSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowServer
{
public:
    QWidget *centralWidget;
    QLabel *image;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_serverPort;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_record;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowServer)
    {
        if (MainWindowServer->objectName().isEmpty())
            MainWindowServer->setObjectName(QStringLiteral("MainWindowServer"));
        MainWindowServer->resize(882, 663);
        centralWidget = new QWidget(MainWindowServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(30, 20, 841, 471));
        image->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(560, 500, 315, 98));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_serverPort = new QLineEdit(widget);
        lineEdit_serverPort->setObjectName(QStringLiteral("lineEdit_serverPort"));

        horizontalLayout->addWidget(lineEdit_serverPort);


        verticalLayout->addLayout(horizontalLayout);

        btn_start = new QPushButton(widget);
        btn_start->setObjectName(QStringLiteral("btn_start"));

        verticalLayout->addWidget(btn_start);

        btn_stop = new QPushButton(widget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));

        verticalLayout->addWidget(btn_stop);


        horizontalLayout_2->addLayout(verticalLayout);

        btn_record = new QPushButton(widget);
        btn_record->setObjectName(QStringLiteral("btn_record"));

        horizontalLayout_2->addWidget(btn_record);

        MainWindowServer->setCentralWidget(centralWidget);
        image->raise();
        btn_start->raise();
        btn_stop->raise();
        btn_record->raise();
        lineEdit_serverPort->raise();
        label_2->raise();
        menuBar = new QMenuBar(MainWindowServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 882, 26));
        MainWindowServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowServer->setStatusBar(statusBar);

        retranslateUi(MainWindowServer);

        QMetaObject::connectSlotsByName(MainWindowServer);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowServer)
    {
        MainWindowServer->setWindowTitle(QApplication::translate("MainWindowServer", "MainWindowServer", Q_NULLPTR));
        image->setText(QApplication::translate("MainWindowServer", "Click start server to start...", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowServer", "Server Port", Q_NULLPTR));
        lineEdit_serverPort->setText(QApplication::translate("MainWindowServer", "30000", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindowServer", "start server", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindowServer", "stop server", Q_NULLPTR));
        btn_record->setText(QApplication::translate("MainWindowServer", "record", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowServer: public Ui_MainWindowServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSERVER_H
