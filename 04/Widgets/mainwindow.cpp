#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxButtons->setTitle("Палочки Twix");
    ui->radioButtonLeft->setText("Левая палочка Twix");
    ui->radioButtonRight->setText("Правая палочка Twix");
    QPushButton *actionButton = ui->actionButton;
    QComboBox *excursion = ui->excursion;
    QProgressBar *progressScale = ui->progressScale;
    actionButton->setMaximumSize(200, 40);
    actionButton->setText("Нажми меня поскорее!");
    actionButton->setCheckable(true);
    excursion->addItem(QString("Левая фабрика Twix"));
    excursion->addItem(QString("Правая фабрика Twix"));
    progressScale->setMinimum(0);
    progressScale->setMaximum(10);
    progressScale->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionButton_toggled(bool checked)
{
    int scaleValue = ui->progressScale->value();
    if (checked)
        {
            qDebug()<<"Button is ON";
            ui->progressScale->setValue(++scaleValue);
            timer = new QTimer(this);
            counter = 2;
            connect (timer, SIGNAL(timeout()), this , SLOT(onTimeout()));
            timer->start(100);
        }
        else
        {
            qDebug()<<"Button OFF";
        }
}

void MainWindow::onTimeout() {
        counter--;
        if (counter == -1)
        {
            timer->stop();
            ui->actionButton->toggled(false);
            ui->actionButton->setCheckable(false);
            ui->actionButton->setCheckable(true);
            int value = ui->progressScale->value();
            if (value == 10) {
                QMessageBox msg;
                msg.setText("Конец!!!");
                msg.setIcon(QMessageBox::Information);
                msg.setStandardButtons(QMessageBox::Yes);
                msg.setDefaultButton(QMessageBox::Yes);
                msg.setWindowTitle("Обнуляем?");
                msg.show();
                if (msg.exec() == QMessageBox::Yes)
                {
                    ui->progressScale->setValue(0);
                }
            }
        }
}

