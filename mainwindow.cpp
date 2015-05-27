#include "mainwindow.h"
#include "ui_mainwindow.h"

//QStringList MainWindow::Status = QStringList() << "Arial" << "Helvetica" << "Times" << "Courier";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    doorList.append(Door());
    doorList.append(Door());
    doorList.append(Door());

    Round = 1;
    Correct = 0;
    Wrong = 0;
    Result = 0;

    Status.append("Select one door");
    Status.append("Computer open one door");
    Status.append("User can select one of closed doors");
    Status.append("You Won!");
    Status.append("You Lost!");
    CurrentStatus = 0;
    UserSelectedDoor = -1;

    UpdateStatus();

    on_pushButton_4_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    NewGame();
    /*
    qsrand(qrand());
    int money = qrand() % ((2 + 1) - 0) + 0;

    qDebug() << "Money " << money;

    for(int i = 0; i < doorList.count(); i++)
        doorList[i].SetWinner(false);

    doorList[money].SetWinner(true);

    CurrentStatus = 0;
    Round++;
    Correct = 0;
    Wrong = 0;
    Result = 0;

    ui->labelRound->setText(QString::number(Round) + "/10");

    UpdateStatus();

    ui->pushButtonDoorOne->setChecked(false);
    ui->pushButtonDoorTwo->setChecked(false);
    ui->pushButtonDoorThree->setChecked(false);*/
}

void MainWindow::NewGame()
{
    ui->pushButtonDoorOne->setEnabled(true);
    ui->pushButtonDoorTwo->setEnabled(true);
    ui->pushButtonDoorThree->setEnabled(true);

    qsrand(qrand());
    int money = qrand() % ((2 + 1) - 0) + 0;

    qDebug() << "Money " << money;

    for(int i = 0; i < doorList.count(); i++)
        doorList[i].SetWinner(false);

    doorList[money].SetWinner(true);

    CurrentStatus = 0;
    Round = 1;
    Correct = 0;
    Wrong = 0;
    Result = 0;

    ui->labelCorrect->setText(QString::number(Correct));
    ui->labelResult->setText(QString::number(Result));
    ui->labelWrong->setText(QString::number(Wrong));

    ui->labelRound->setText(QString::number(Round) + "/10");

    UpdateStatus();

    ui->pushButtonDoorOne->setChecked(false);
    ui->pushButtonDoorTwo->setChecked(false);
    ui->pushButtonDoorThree->setChecked(false);

    ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");
    ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");
    ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");
}

void MainWindow::NewRound()
{
    if(Round == 10)
    {
        ui->pushButtonDoorOne->setEnabled(false);
        ui->pushButtonDoorTwo->setEnabled(false);
        ui->pushButtonDoorThree->setEnabled(false);

        Round = 1;

        ui->labelStatus->setText("Game is over, start a new one.");

        return;
    }

    ui->pushButtonDoorOne->setEnabled(true);
    ui->pushButtonDoorTwo->setEnabled(true);
    ui->pushButtonDoorThree->setEnabled(true);

    qsrand(qrand());
    int money = qrand() % ((2 + 1) - 0) + 0;

    qDebug() << "Money " << money;

    for(int i = 0; i < doorList.count(); i++)
        doorList[i].SetWinner(false);

    doorList[money].SetWinner(true);

    CurrentStatus = 0;
    Round++;

    ui->labelRound->setText(QString::number(Round) + "/10");

    UpdateStatus();

    ui->pushButtonDoorOne->setChecked(false);
    ui->pushButtonDoorTwo->setChecked(false);
    ui->pushButtonDoorThree->setChecked(false);

    ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");
    ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");
    ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprta.jpg); position: relative}");}


void MainWindow::UpdateStatus()
{
    ui->labelStatus->setText(Status.at(CurrentStatus));
}

void MainWindow::on_pushButtonDoorOne_clicked(bool checked)
{
    ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprtaSelected.jpg); position: relative}");
    qDebug() << "One clicked.";
    UserSelectedDoor = 0;
    DoWork();
}

void MainWindow::on_pushButtonDoorTwo_clicked(bool checked)
{
    qDebug() << "two clicked.";

    ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprtaSelected.jpg); position: relative}");
    UserSelectedDoor = 1;
    DoWork();
}

void MainWindow::on_pushButtonDoorThree_clicked(bool checked)
{
    qDebug() << "three clicked.";

    ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataZaprtaSelected.jpg); position: relative}");
    UserSelectedDoor = 2;
    DoWork();
}

void MainWindow::DoWork()
{
    if(CurrentStatus == 0)
    {
        if(doorList[UserSelectedDoor].IsWinner())
        {
            CurrentStatus = 3;
            UpdateStatus();

            Correct++;
            Result++;

            ui->labelCorrect->setText(QString::number(Correct));
            ui->labelResult->setText(QString::number(Result));


            for(int i = 0; i < doorList.count(); i++)
            {
                if(doorList[i].IsWinner())
                {
                    if(i == 0)
                    {
                        ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                       // ui->pushButtonDoorOne->setChecked(true);
                    }
                    else if(i == 1)
                    {
                        ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                      //  ui->pushButtonDoorTwo->setChecked(true);
                    }
                    else if(i == 2)
                    {
                        ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                     //   ui->pushButtonDoorThree->setChecked(true);
                    }
                  //  ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                }
                else
                {
                    if(i == 0)
                    {
                        ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                 //       ui->pushButtonDoorOne->setChecked(true);
                    }
                    else if(i == 1)
                    {
                        ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                  //      ui->pushButtonDoorTwo->setChecked(true);
                    }
                    else if(i == 2)
                    {
                        ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                    //    ui->pushButtonDoorThree->setChecked(true);
                    }

                 //   ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                }
            }

            ui->pushButtonDoorOne->setEnabled(false);
            ui->pushButtonDoorTwo->setEnabled(false);
            ui->pushButtonDoorThree->setEnabled(false);

            QTimer::singleShot(2000, this, SLOT(NewRound()));
        }
        else
        {
            CurrentStatus = 1;
            UpdateStatus();

            for(int i = 0; i < doorList.count(); i++)
            {
                if(!doorList[i].IsWinner() && i != UserSelectedDoor)
                {
                    qDebug() << "Computer opens door number " << i;
                    // Computer open door, the one not clicked by user, and with no reward.
                    CurrentStatus = 2;
                    UpdateStatus();

                    if(i == 0)
                    {
                        ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                        ui->pushButtonDoorOne->setChecked(true);
                        ui->pushButtonDoorOne->setEnabled(false);
                    }
                    else if(i == 1)
                    {
                        ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                        ui->pushButtonDoorTwo->setChecked(true);
                        ui->pushButtonDoorTwo->setEnabled(false);
                    }
                    else if(i == 2)
                    {
                        ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                        ui->pushButtonDoorThree->setChecked(true);
                        ui->pushButtonDoorThree->setEnabled(false);
                    }
                }
            }
        }
    }
    else if(CurrentStatus == 2)
    {
        if(doorList[UserSelectedDoor].IsWinner())
        {
            CurrentStatus = 3;
            UpdateStatus();

            Correct++;
            Result++;

            ui->labelCorrect->setText(QString::number(Correct));
            ui->labelResult->setText(QString::number(Result));
        }
        else
        {
            Wrong++;
            Result--;

            CurrentStatus = 4;
            UpdateStatus();

            ui->labelWrong->setText(QString::number(Wrong));
            ui->labelResult->setText(QString::number(Result));
        }

        qDebug() << "Current Status " << CurrentStatus;
        for(int i = 0; i < doorList.count(); i++)
        {
            if(doorList[i].IsWinner())
            {
                if(i == 0)
                {
                    ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
               // ui->pushButtonDoorOne->setChecked(true);
                }
                else if(i == 1)
                {
                    ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                    //  ui->pushButtonDoorTwo->setChecked(true);
                }
                else if(i == 2)
                {
                    ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaMoney.jpg); position: relative}");
                    //   ui->pushButtonDoorThree->setChecked(true);
                }
            }
            else
            {
                if(i == 0)
                {
                    ui->pushButtonDoorOne->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                }
                else if(i == 1)
                {
                    ui->pushButtonDoorTwo->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                }
                else if(i == 2)
                {
                    ui->pushButtonDoorThree->setStyleSheet("QPushButton{border-image:url(:/Slike/VrataOdprtaPoop.jpg); position: relative}");
                }
            }
        }
        CurrentStatus = 0;
        ui->pushButtonDoorOne->setEnabled(false);
        ui->pushButtonDoorTwo->setEnabled(false);
        ui->pushButtonDoorThree->setEnabled(false);
        QTimer::singleShot(2000, this, SLOT(NewRound()));
    }
}
