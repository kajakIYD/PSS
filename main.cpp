#include "mainwindow.h"
#include <QApplication>
#include "regulator.h"



QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QVector<double> x(101), y(101);
    for(int i=0; i<101; i++)
    {
        x[i] = i / 50.0 -1;
        y[i] = x[i]*x[i];
    }

    w.Update(x, y);



    return a.exec();
}
