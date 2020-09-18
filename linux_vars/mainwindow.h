#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //void get_info();
    ~MainWindow();

private slots:
    void get_info();
    //void on_tableWidget_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QString f_cpu_info = "/proc/cpuinfo";
    QString s_cpu_model = "model name";
    QString v_cpu_model;
    QString s_cpu_freq = "cpu MHz";
    QString v_cpu_freq;
    QString s_cpu_cs = "cache size";
    QString v_cpu_cs;

    QString f_cpu_load = "/proc/stat";
    QString s_cpu_load = "cpu ";
    double v_cpu_load;

    QString f_mem = "/proc/meminfo";
    QString s_mem_total = "MemTotal";
    QString s_mem_free = "MemFree";

    QString f_bat = "/sys/class/power_supply/BAT0/capacity";

    void get_cpu_info();
    void get_cpu_load();
    void get_mem_load();
    void get_bat_load();
};

#endif // MAINWINDOW_H
