#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <string>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();
    void set_name(std::string& name){
        username = name;
    }

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Deposit *ui;
    std::string username ;
};

#endif // DEPOSIT_H
