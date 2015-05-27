#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

#include "Door.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void MainWindow::UpdateStatus();
    void MainWindow::DoWork();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButtonDoorOne_clicked(bool checked);
    void on_pushButtonDoorTwo_clicked(bool checked);
    void on_pushButtonDoorThree_clicked(bool checked);
    void NewRound();
    void NewGame();

private:
    Ui::MainWindow *ui;
    QList<Door> doorList;
    int Round;
    int Correct;
    int Wrong;
    int Result;
    int CurrentStatus;
    QStringList Status;
    int UserSelectedDoor;
};

#endif // MAINWINDOW_H
