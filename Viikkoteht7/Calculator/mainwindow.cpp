#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setActiveControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    if(state == 3) {
        state = 1;


        QString num1Str = ui->num1->text();
        float num1 = num1Str.toFloat();

        QString num2Str = ui->num2->text();
        float num2 = num2Str.toFloat();

        float result = num1 + num2;
        qDebug() << "Plus:" << result << "=" << num1 << "+" << num2;

        QString resStr = QString::number(result);
        ui->result->setText(resStr);


        setActiveControls();
    }
}

void MainWindow::on_N1_clicked()
{
    QString str = ui->N1->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N2_clicked()
{
    QString str = ui->N2->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N3_clicked()
{
    QString str = ui->N3->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N4_clicked()
{
    QString str = ui->N4->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N5_clicked()
{
    QString str = ui->N5->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N6_clicked()
{
    QString str = ui->N6->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N7_clicked()
{
    QString str = ui->N7->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N8_clicked()
{
    QString str = ui->N8->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N9_clicked()
{
    QString str = ui->N9->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_N0_clicked()
{
    QString str = ui->N0->text();
    int n = str.toInt();
    numberClickHandler(n);
}

void MainWindow::numberClickHandler(int n)
{
    qDebug() << "Valittu numero=" << n;
    QString str = QString::number(n);
    if (state == 1) {
        ui->num1->setText(str);
    } else if (state == 2) {
        ui->num2->setText(str);
    }
}

void MainWindow::setActiveControls()
{
    if(state == 1){
        ui->num1->setEnabled(true);
        ui->num2->setEnabled(false);
        ui->result->setEnabled(false);
        ui->add->setEnabled(false);
        ui->div->setEnabled(false);
        ui->sub->setEnabled(false);
        ui->mult->setEnabled(false);
    } else if (state == 2) {
        ui->num1->setEnabled(false);
        ui->num2->setEnabled(true);
        ui->result->setEnabled(false);
        ui->add->setEnabled(false);
        ui->div->setEnabled(false);
        ui->sub->setEnabled(false);
        ui->mult->setEnabled(false);
    } else if (state == 3) {
        ui->num1->setEnabled(false);
        ui->num2->setEnabled(false);
        ui->result->setEnabled(true);
        ui->add->setEnabled(true);
        ui->div->setEnabled(true);
        ui->sub->setEnabled(true);
        ui->mult->setEnabled(true);
    }
}


void MainWindow::on_enter_clicked()
{
    if (state == 3) {
        state = 3;
    } else {
        state++;
    }
    qDebug() << "Siirrytty tilaan" << state;
    setActiveControls();

}


void MainWindow::on_sub_clicked()
{
    if(state == 3) {
        state = 1;


        QString num1Str = ui->num1->text();
        float num1 = num1Str.toFloat();

        QString num2Str = ui->num2->text();
        float num2 = num2Str.toFloat();

        float result = num1 - num2;
        qDebug() << "Miinus:" << result << "=" << num1 << "-" << num2;

        QString resStr = QString::number(result);
        ui->result->setText(resStr);

        state = 1;
    }
}


void MainWindow::on_mult_clicked()
{
    if(state == 3) {
        state = 1;


        QString num1Str = ui->num1->text();
        float num1 = num1Str.toFloat();

        QString num2Str = ui->num2->text();
        float num2 = num2Str.toFloat();

        float result = num1 * num2;
        qDebug() << "Kerto:" << result << "=" << num1 << "*" << num2;

        QString resStr = QString::number(result);
        ui->result->setText(resStr);

        setActiveControls();
    }
}


void MainWindow::on_div_clicked()
{
    if(state == 3) {
        state = 1;


        QString num1Str = ui->num1->text();
        float num1 = num1Str.toFloat();

        QString num2Str = ui->num2->text();
        float num2 = num2Str.toFloat();

        float result = num1 / num2;
        qDebug() << "Jako:" << result << "=" << num1 << "/" << num2;

        QString resStr = QString::number(result, 'f', 2);
        ui->result->setText(resStr);

        setActiveControls();
    }
}


void MainWindow::on_clear_clicked()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();

    state = 1;
    setActiveControls();

    qDebug() << "Laskin tyhjennetty";
}

