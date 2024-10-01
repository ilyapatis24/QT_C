#include "mainwindow.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;
    QLabel *label = new QLabel(&window);
    label->setText("Hello\nWorld!!!");
    window.show();
    return application.exec();
}
