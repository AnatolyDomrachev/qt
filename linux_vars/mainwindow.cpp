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
    get_cpu_info();
    get_cpu_load();
    get_mem_load();
    get_bat_load();
}

void MainWindow::get_cpu_info()
{

    QFile file(f_cpu_info);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

// Get proc info
    QTextStream in(&file);
        QString line;
            QStringList list ;
    int num_vars = 0;

    for(int i=0; i<1000; i++){
        line = in.readLine();

      if(line.contains(s_cpu_model))
      {
            list = line.split(":");
            v_cpu_model = list[1];
	    num_vars++;
      }

      if(line.contains(s_cpu_cs))
      {
            list = line.split(":");
            v_cpu_cs = list[1];
	    num_vars++;
      }

      if(line.contains(s_cpu_freq))
      {
            list = line.split(":");
            v_cpu_freq = list[1];
	    num_vars++;
      }

      if(num_vars==3)
	break;

    }

    ui->tableWidget->setItem(0,0,new QTableWidgetItem(v_cpu_model));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(v_cpu_freq));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(v_cpu_cs));
}
void MainWindow::get_cpu_load()
{
    double Idle , NonIdle ;
    QString idle , iowait , user , nice , system , irq , softirq , steal;

    QFile file(f_cpu_load);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line;
    QStringList list ;
    QRegularExpression regex( " +" );

    for(int i=0; i<1000; i++){
        line = in.readLine();

      if(line.contains(s_cpu_load))
      {
            QStringList list = line.split(regex);
            idle = list[4];
            iowait = list[5];

user  = list[1];
nice  = list[2];
system  = list[3];
irq  = list[6];
softirq  = list[7];
steal = list[8];

            Idle = idle.toInt() + iowait.toInt();
            NonIdle = user.toInt() + nice.toInt() + system.toInt() + irq.toInt() + softirq.toInt() + steal.toInt();
            v_cpu_load = NonIdle/(Idle + NonIdle)*100;
            break;
      }
    }

    QString result = QString::number(v_cpu_load, 'g', 3);

    ui->tableWidget->setItem(0,3,new QTableWidgetItem(result));
}

void MainWindow::get_mem_load()
{
}

void MainWindow::get_bat_load()
{
}

