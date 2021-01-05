#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include"administration/admin.h"
#include"labscientist/labscientist.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
private slots:
    void on_pushButton_login_clicked();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
