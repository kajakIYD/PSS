#include "mainwindow.h"
#include <QApplication>
#include <QXmlStreamReader>
#include "pi.h"
#include "obiekt.h"
#include "config.h"



using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PI *pi = new PI(1,0,0,0);
    obiekt *ob = new obiekt(20, 0.8);
    ARX *arx = new ARX();
    MainWindow w(arx);

    //MainWindow w(pi,ob);
    w.show();



    return a.exec();
}
