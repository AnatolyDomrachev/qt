#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("qwe"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("010101"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
