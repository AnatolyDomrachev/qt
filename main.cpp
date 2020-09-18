#include "mainwindow.h"
#include <QApplication>
#include "QThread"
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //w.get_info();
    a.exec();

    return 0;
}
