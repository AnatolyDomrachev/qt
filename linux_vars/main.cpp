#include "mainwindow.h"
#include <QApplication>
#include "QThread"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;





    //QTimer::(3000, &w, SLOT(get_info()));


    w.show();
    //QThread::sleep(3);
    //w.get_info();

    return a.exec();
}
