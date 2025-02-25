#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Lisaanappi_clicked()
{
    QString str = ui->numeronaytto->text();
    int num = str.toInt();
    qDebug() << "Numero= " << num;
    num++;
    qDebug() << "Kasvatettu numero= " << num;
    QString uusiStr = QString::number(num);
    ui->numeronaytto->setText(uusiStr);
}


void MainWindow::on_Resetnappi_clicked()
{
    QString str = ui->numeronaytto->text();
    int num = str.toInt();
    num = 0;
    QString uusiStr = QString::number(num);
    ui->numeronaytto->setText(uusiStr);
}

