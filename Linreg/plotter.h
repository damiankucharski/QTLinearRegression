#ifndef PLOTTER_H
#define PLOTTER_H

#endif // PLOTTER_H

#include "mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCore/QDebug>
#include <QtCharts/QValueAxis>
#include <QtCharts/QScatterSeries>
QChartView * plot(vector<float>x, vector<float>y, vector<float>predictions, QChart * chart)
{
    QLineSeries *line_series = new QLineSeries();
    QScatterSeries *scatter_series = new QScatterSeries();
    for (int i = 0; i < predictions.size(); i++)
    {
        line_series->append(x[i], predictions[i]);
        scatter_series->append(x[i], y[i]);
    }
    chart->legend()->hide();
    chart->addSeries(line_series);
    chart->addSeries(scatter_series);
    chart->createDefaultAxes();
    chart->setTitle("Regression chart");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
