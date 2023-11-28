#ifndef USER_LOGIN_H
#define USER_LOGIN_H

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

private:
    Ui::User_login *ui;
};

#endif // USER_LOGIN_H
