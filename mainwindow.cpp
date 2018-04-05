#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(ARX *arx, QWidget *parent) :
    s_arx(arx),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    s_plotDelegate = new PlotDelegate(ui, this);
    //logger = new SaveMeas("E:\\Qt\\Projects\\PSS\\TestFile.txt");

    arx->RegisterObserver(s_plotDelegate);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateView()));
    timer->start(1000);
}

void MainWindow::updateViewStep()
{
    s_arx->Simulate_step(s_arx->public_U);
    krok = false;
    time++;
    if (time>s_arx->GetSwitchTime())
        s_arx->UpdateParameters();
}

void MainWindow::updateView()
{
    if (time>s_arx->GetSwitchTime())
        s_arx->UpdateParameters();
    if (!krok && mode)
    {
        s_arx->Simulate_step(s_arx->public_U);
        time++;
    }
}

void MainWindow::on_w_changeKr_valueChanged(double arg1)
{
    s_pi->Kr = arg1;
}

void MainWindow::on_w_changeTi_valueChanged(double arg1)
{
    s_pi->Ti = arg1;
}

void MainWindow::on_w_changeMax_u_valueChanged(double arg1)
{
    s_pi->max_u = arg1;
}

void MainWindow::on_w_changeSp_valueChanged(double arg1)
{
    s_pi->setpoint = arg1;
}

void MainWindow::on_w_changeU_valueChanged(double arg1)
{
   s_arx->public_U = arg1;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    timer->start(value);
}

MainWindow::~MainWindow()
{
    s_arx->UnregisterObserver(s_plotDelegate);
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mode = !(mode);
    if (mode)
    {
        ui->pushButton->text() = "Stop";
    }
    else
    {
        ui->pushButton->text() = "Start";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    krok = true;
    mode = false;
    updateViewStep();
}


