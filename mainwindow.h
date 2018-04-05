#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "observer.h"
#include "qcustomplot.h"
#include "pi.h"
#include "obiekt.h"
#include "arx.h"
#include "plotdelegate.h"
#include "savemeas.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(PI *pi, obiekt *ob, QWidget *parent = 0);
    explicit MainWindow(ARX* arx, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateView();

    void on_w_changeKr_valueChanged(double arg1);

    void on_w_changeTi_valueChanged(double arg1);

    void on_w_changeMax_u_valueChanged(double arg1);

    void on_w_changeSp_valueChanged(double arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_w_changeU_valueChanged(double arg1);

private:
    QTimer *timer;
    PI *s_pi;
    obiekt *s_ob;
    ARX *s_arx;
    PlotDelegate *plotDelegate;
    //SaveMeas *saveMeas;

    void updateViewStep();

    bool mode = false;
    QVector<double> x;
    QVector<double> y;
    QVector<double> sp;
    QVector<double> v_u;
    int time = 0;
    bool krok = false;
public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
