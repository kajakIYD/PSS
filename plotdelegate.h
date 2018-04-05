#ifndef PLOTDELEGATE_H
#define PLOTDELEGATE_H
#include "observer.h"
#include "ui_mainwindow.h"
#include <QVector>
#include "qcustomplot.h"

class PlotDelegate : public Observer
{
public:
    PlotDelegate(Ui::MainWindow* ui, QMainWindow* mw);
    //PlotDelegate();
    virtual void UpdateView(double u, double y);
private:
    Ui::MainWindow * ui;
    double time=0;
    QVector<double> t={};
    QVector<double> y={};
    QVector<double> u={};
};

#endif // PLOTDELEGATE_H
