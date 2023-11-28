#include "register.h"
#include "ui_register.h"


#include "login_sys.hpp"
#include "login_sys.cpp"


#include <string>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    if (!fs::exists(current_path + "/Name_list")) {
        // If it doesn't exist, create it
        fs::create_directory(current_path + "/Name_list");
    }
    QString username, password, type;
    username=ui->lineEdit_name->text();
    password=ui->lineEdit_pass->text();
    type= ui->comboBox->currentText();
    Login_sys regis ;
    regis.Register(username.toStdString() , password.toStdString(), type.toStdString());

    this->close();
}




