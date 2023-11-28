#include "user_login.h"
#include "ui_user_login.h"
#include "deposit.h"
#include "withdraw.h"
#include "transfer.h"

User_login::User_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_login)
{
    ui->setupUi(this);
}

User_login::~User_login()
{
    delete ui;
}


void User_login::on_pushButton_2_clicked()
{
    Withdraw withdraw_win;
    withdraw_win.setModal(true);
    withdraw_win.exec();
}


void User_login::on_pushButton_3_clicked()
{
    Transfer transfer_win;
    transfer_win.setModal(true);
    transfer_win.exec();
}




void User_login::on_pushButton_1_clicked()
{
    Deposit deposit_win;
    deposit_win.set_name(username);
    deposit_win.setModal(true);
    deposit_win.exec();
}

