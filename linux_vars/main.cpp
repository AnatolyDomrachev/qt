#include "mainwindow.h"
#include <QApplication>
#include "QThread"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QThread::sleep(3);
    w.get_info();

    return a.exec();
}
