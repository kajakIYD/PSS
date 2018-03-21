#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "pi.h"


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
    ui->Plot1->addGraph();

}

void MainWindow::Update(QVector<double> x, QVector<double> y)
{
    ui->Plot1->graph(0)->setData(x,y);
    ui->Plot1->xAxis->setLabel("x");
    ui->Plot1->yAxis->setLabel("y");
    ui->Plot1->replot();
}

void MainWindow::on_w_changeKr_valueChanged(double arg1)
{
    //pi.Kr = arg1;
}

void MainWindow::on_w_changeTi_valueChanged(double arg1)
{
    //pi.Ti = arg1;
}

void MainWindow::on_w_changeMax_u_valueChanged(double arg1)
{
    //pi.max_u = arg1;
}

void MainWindow::on_w_changeSp_valueChanged(double arg1)
{

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





void MainWindow::on_pushButton_toggled(bool checked)
{
    bool x = checked;
}
