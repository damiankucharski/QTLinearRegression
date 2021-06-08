#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linreg.h"
#include <vector>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Linreg linreg;

    vector<float>x_vec{};
    vector<float>y_vec{};
private slots:

    void on_load_file_widget_clicked();

    void on_fit_widget_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
