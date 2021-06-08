#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "linreg.h"
#include <fstream>
#include <QMessageBox>
#include <string>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCore/QDebug>
#include <QtCharts/QValueAxis>
#include <QtCharts/QScatterSeries>
#include <plotter.h>
#include <QThread>
#include <QTime>

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
//        delete item;
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_load_file_widget_clicked()
{
    string filename = ui->filepath_field->text().toStdString();
    ifstream file(filename);
    string temp_x, temp_y;
    while(file>>temp_x && file>>temp_y)
    {
        this->x_vec.push_back(atof(temp_x.c_str()));
        this->y_vec.push_back(atof(temp_y.c_str()));
    }
    file.close();
    QMessageBox msgBox;
    msgBox.setText(QString("File Loaded"));
    msgBox.exec();
}


void MainWindow::on_fit_widget_clicked()
{
    QMessageBox msgBox;
    QString lr_str = ui->lr_field->text();
    QString epochs_str = ui->epoch_field->text();
    float lr = lr_str.toFloat();
    float epochs = epochs_str.toFloat();

    QChart *chart = new QChart();
    QChartView *chartView =  new QChartView(chart);
    float cur_loss;
    for (int i = 0; i < epochs; i++)
    {
        this->linreg.fit(this->x_vec, this->y_vec, 1, lr);
        auto predictions = this->linreg.predict(this->x_vec);
        cur_loss = this->linreg.loss(this->y_vec, predictions);
        delay();
        delete chartView;
        chart = new QChart();
        chartView = plot(this->x_vec, this->y_vec, predictions, chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->chart_field->layout()->addWidget(chartView);
        ui->epoch_label->setText(QString(("Epochs_elapsed: " + to_string(i)).c_str()));
        ui->eq_label->setText(QString(("Line equation: y = " + to_string(this->linreg.a) + "x + " + to_string(this->linreg.b)).c_str()));
        ui->loss_label->setText(QString(("Loss = " + to_string(cur_loss)).c_str()));
    }

    string message = "Final formula: y = " + to_string(this->linreg.a) + "x + " + to_string(this->linreg.b);
    msgBox.setText(QString(message.c_str()));
    msgBox.exec();
}



