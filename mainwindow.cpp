#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
    //        ui->progressBar,SLOT(setValue(int)));
            //connect - tworzy połączenie między widżetami
            //1. sender - wejscie
            //2. signal -
            //3. receiver - wyjście
            //4. slot -
            //disconnect - dezaktywuje połączenie
    ui->customPlot->addGraph();

}

void MainWindow::Update(QVector<double> x, QVector<double> y)
{
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_pushButton_2_clicked()
{
    // example of messege box
    // critical
    // information
    // question
    // warning
    //QMessageBox::about(this, "Myt title", "This is my custom message");
    //QMessageBox::critical(this, "My title", "My information");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My title","Question?",
                                                 QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else{
        qDebug() <<"No is clicked";
    }
}*/
