#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //get_info();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_info()
{
    QString f_cpu_info = "/proc/cpuinfo";
    QString s_cpu_model = "model name";
    QString v_cpu_model;
    QString s_cpu_freq = "cpu MHz";
    QString s_cpu_cs = "cache size";

    QString f_cpu_load = "/proc/stat";
    QString s_cpu_load = "cpu ";

    QString f_mem = "/proc/meminfo";
    QString s_mem_total = "MemTotal";
    QString s_mem_free = "MemFree";

    QString f_bat = "/sys/class/power_supply/BAT0/capacity";

    QFile file(f_cpu_info);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

// Get proc info
    QString var;
    QTextStream in(&file);

    std::string s1, s2, s3;
    while (!in.atEnd()) {
        QString line = in.readLine();

        //if(line.contains(s_cpu_model))
    //{
            QStringList list = line.split(":");
            var = list[0];
            s1 = var.toStdString();
            v_cpu_model = list[1];
    //}
    //    process_line(line);
    }


    ui->tableWidget->setItem(0,0,new QTableWidgetItem(v_cpu_model));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(var));
}
