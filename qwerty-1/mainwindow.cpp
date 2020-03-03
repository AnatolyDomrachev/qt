#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    QString s1 = ui->textEdit->toPlainText();
    QString s2 = ui->textEdit_2->toPlainText();

    bool valid;
    double n1 = s1.toDouble(&valid);


    if(valid)
        ui->textBrowser->setText(s1);
    else
        ui->textEdit->document()->setPlainText("Error!!!");

    ui->centralWidget->

}
