#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <string>
#include <QDialog>

namespace Ui {
class User_login;
}

class User_login : public QDialog
{
    Q_OBJECT

public:
    explicit User_login(QWidget *parent = nullptr);
    ~User_login();

    void set_name(std::string name){
        username = name;
    }

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::User_login *ui;
    std::string username;
};

#endif // USER_LOGIN_H
