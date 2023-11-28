#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"
#include "register.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Register regis_win;
    regis_win.setModal(true);
    regis_win.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Login log_win;
    log_win.setModal(true);
    log_win.exec();
}

