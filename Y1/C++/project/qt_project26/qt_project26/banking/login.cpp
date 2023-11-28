#include "login.h"
#include "ui_login.h"
#include "user_login.h"

#include "login_sys.hpp"
//#include "login_sys.cpp"

#include <string>
#include <iostream>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
    username=ui->lineEdit_name->text();
    password=ui->lineEdit_pass->text();

    Login_sys regis ;
    if (regis.LoggedIn(username.toStdString() , password.toStdString())){
        User_login user_win;
        user_win.setModal(true);
        user_win.set_name(username.toStdString());
        user_win.exec();
    }
}

