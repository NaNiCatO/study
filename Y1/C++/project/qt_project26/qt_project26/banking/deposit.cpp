#include "deposit.h"
#include "ui_deposit.h"
#include "final.hpp"

#include "Final_project_0.cpp"


Deposit::Deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_buttonBox_accepted()
{
    Login_sys user;
    std::string type = user.check_type(username);
    if (type == "No limit"){
        User transaction(username);
    } else if(type == "Limit");{
        Limit_User transaction(username);
    }
}


void Deposit::on_buttonBox_rejected()
{
    this->close();
}

