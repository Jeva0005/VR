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
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    delete ui;
}

void MainWindow::on_timestart_clicked()
{
    if (gameTime > 0)
    {
    currentPlayer = 1;

    ui->progressBar_1->setRange(0, gameTime);
    ui->progressBar_2->setRange(0, gameTime);
    ui->progressBar_1->setValue(gameTime);
    ui->progressBar_2->setValue(gameTime);

    timer = new QTimer (this);
    connect(timer,&QTimer::timeout, this, &MainWindow::updateProgressBar);
    timer->setInterval(1000);
    timer->start();
    } else
    {
        QMessageBox::information(this, "Aikaa ei valittu", "Valitse aika");
    }
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1)
    {
        p1Time--;
        ui->progressBar_1->setValue(p1Time);

        if (p1Time == 0)
        {
            timer->stop();
            delete timer;
            QMessageBox::information(this, "Pelaaja 1 havisi", "Peli paattyy");
        }
    } else
    {
        p2Time--;
        ui->progressBar_2->setValue(p2Time);

        if (p2Time == 0)
        {
            timer->stop();
            delete timer;
            QMessageBox::information(this, "Pelaaja 2 havisi", "Peli paattyy");
        }
    }

}


void MainWindow::on_p1end_clicked()
{
    currentPlayer = 2;
}


void MainWindow::on_p2end_clicked()
{
    currentPlayer = 1;
}


void MainWindow::on_timeshort_clicked()
{
    gameTime = 10;
    p1Time = gameTime;
    p2Time = gameTime;

    ui->progressBar_1->setValue(10);
    ui->progressBar_2->setValue(10);

    ui->progressBar_1->setRange(0, gameTime);
    ui->progressBar_2->setRange(0, gameTime);
}


void MainWindow::on_timelong_clicked()
{
    gameTime = 30;
    p1Time = gameTime;
    p2Time = gameTime;

    ui->progressBar_1->setValue(30);
    ui->progressBar_2->setValue(30);

    ui->progressBar_1->setRange(0, gameTime);
    ui->progressBar_2->setRange(0, gameTime);
}


void MainWindow::on_gamestop_clicked()
{
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }

    gameTime = 0;
    currentPlayer = 1;

    // Tyhjennetään progressBarit
    ui->progressBar_1->setRange(0, gameTime);
    ui->progressBar_2->setRange(0, gameTime);
    ui->progressBar_1->setValue(0);
    ui->progressBar_2->setValue(0);

}

