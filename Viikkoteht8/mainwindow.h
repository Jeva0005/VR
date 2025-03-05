#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMessageBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_timestart_clicked();
    void updateProgressBar();

    void on_p1end_clicked();

    void on_p2end_clicked();

    void on_timeshort_clicked();

    void on_timelong_clicked();

    void on_gamestop_clicked();

private:
    Ui::MainWindow *ui;
    int p1Time;
    int p2Time;
    int currentPlayer = 1;
    int gameTime = 0;
    QTimer *timer = nullptr;
};
#endif // MAINWINDOW_H
