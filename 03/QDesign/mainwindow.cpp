#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dialog(new Dialog())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
}

void MainWindow::on_pushButton_clicked()
{
    dialog->show();
}
