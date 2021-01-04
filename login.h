#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include"administration/admin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();



private:
    Ui::login *ui;
};
#endif // LOGIN_H
