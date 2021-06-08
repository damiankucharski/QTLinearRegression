/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *fit_widget;
    QPushButton *load_file_widget;
    QLineEdit *filepath_field;
    QLineEdit *lr_field;
    QLineEdit *epoch_field;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *chart_field;
    QLabel *epoch_label;
    QLabel *eq_label;
    QLabel *loss_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        fit_widget = new QPushButton(centralwidget);
        fit_widget->setObjectName(QString::fromUtf8("fit_widget"));
        fit_widget->setGeometry(QRect(80, 120, 75, 23));
        load_file_widget = new QPushButton(centralwidget);
        load_file_widget->setObjectName(QString::fromUtf8("load_file_widget"));
        load_file_widget->setGeometry(QRect(80, 80, 75, 23));
        filepath_field = new QLineEdit(centralwidget);
        filepath_field->setObjectName(QString::fromUtf8("filepath_field"));
        filepath_field->setGeometry(QRect(170, 80, 331, 20));
        lr_field = new QLineEdit(centralwidget);
        lr_field->setObjectName(QString::fromUtf8("lr_field"));
        lr_field->setGeometry(QRect(170, 120, 151, 20));
        epoch_field = new QLineEdit(centralwidget);
        epoch_field->setObjectName(QString::fromUtf8("epoch_field"));
        epoch_field->setGeometry(QRect(332, 120, 171, 20));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 210, 421, 191));
        chart_field = new QHBoxLayout(horizontalLayoutWidget);
        chart_field->setObjectName(QString::fromUtf8("chart_field"));
        chart_field->setContentsMargins(0, 0, 0, 0);
        epoch_label = new QLabel(centralwidget);
        epoch_label->setObjectName(QString::fromUtf8("epoch_label"));
        epoch_label->setGeometry(QRect(80, 150, 121, 21));
        eq_label = new QLabel(centralwidget);
        eq_label->setObjectName(QString::fromUtf8("eq_label"));
        eq_label->setGeometry(QRect(80, 190, 241, 21));
        loss_label = new QLabel(centralwidget);
        loss_label->setObjectName(QString::fromUtf8("loss_label"));
        loss_label->setGeometry(QRect(80, 170, 91, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        fit_widget->setText(QCoreApplication::translate("MainWindow", "Fit model", nullptr));
        load_file_widget->setText(QCoreApplication::translate("MainWindow", "Load file", nullptr));
        filepath_field->setText(QCoreApplication::translate("MainWindow", "C:\\Users\\cdami\\Documents\\LinearRegression\\doc.txt", nullptr));
        lr_field->setText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        epoch_field->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        epoch_label->setText(QCoreApplication::translate("MainWindow", "Epochs_elapsed: 0", nullptr));
        eq_label->setText(QCoreApplication::translate("MainWindow", "Line equation: y = 0x + 0", nullptr));
        loss_label->setText(QCoreApplication::translate("MainWindow", "Loss = inf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
