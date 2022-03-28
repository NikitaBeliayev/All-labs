#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPushButton>
#include <QMainWindow>
#include<QTableWidget>
#include"game.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RestartGame_triggered();

    void on_NewGame_triggered();

    void on_Exit_triggered();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void showtable();
    Game* game;



};
#endif // MAINWINDOW_H
