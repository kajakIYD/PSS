#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartGlobal>
#include "observer.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public observer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_w_changeKr_valueChanged(double arg1);

    void on_w_changeTi_valueChanged(double arg1);

    void on_w_changeMax_u_valueChanged(double arg1);

    void on_w_changeSp_valueChanged(double arg1);

    void on_pushButton_toggled(bool checked);

public:

    void Update(QVector<double> x, QVector<double> y);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
