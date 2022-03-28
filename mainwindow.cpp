#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (auto i = 0; i < 4; i++) {
        ui -> tableWidget -> setColumnWidth(i, 70);
        ui -> tableWidget -> setRowHeight(i, 70);
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget -> setEditTriggers ( QAbstractItemView :: NoEditTriggers );
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();


    game = new Game();


    while(game->collectibility() == false)
    {
        game = new Game();
    }
    showtable();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}


void MainWindow::on_RestartGame_triggered()
{
    game->RestartGame();
    showtable();
}


void MainWindow::on_NewGame_triggered()
{
    if(game!= nullptr)
    {
        delete game;
    }
    game = new Game();
    showtable();
}


void MainWindow::on_Exit_triggered()
{
     QApplication::quit();
}


void MainWindow::showtable()
{

    for(int i = 0;i<4;i++)
    {
        for(int j = 0; j<4;j++)
        {
            QString str;
            if(game->GetValue(i,j) == 16)
            {
                str = "";
            }
            else
            {
                str = QString::number(game->GetValue(i,j));
            }
            QTableWidgetItem* item = new QTableWidgetItem(str);
            ui->tableWidget->setItem(i,j,item);

        }
    }

}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    game->Move(row, column);
    showtable();
    if(game->isFinished())
    {
        if (QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть снова?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            QApplication::quit();
        else {
            game->Startgame();
            showtable();
        }
    }

}

