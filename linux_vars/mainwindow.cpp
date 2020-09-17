#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    get_proc_info();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_proc_info()
{
        QFile file("/proc/cpuinfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    //while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList list = line.split(":");
    //    process_line(line);
    //}


    ui->tableWidget->setItem(0,0,new QTableWidgetItem(list[0]));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("010101"));
}
