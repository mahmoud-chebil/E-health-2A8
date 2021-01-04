#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class patient
{
public:
    patient();
    patient(int,QString,QString,QString,int,QString);
    QString get_name();
    QString get_last_name();
    QString get_gender();
    QString get_mail();

    int get_id;
    int get_age;

    bool add();
    QSqlQueryModel *show();
   bool del(int);
   bool update();
   QSqlQueryModel * searchid(const QString &);
   QSqlQueryModel * searchname(const QString &);
   QSqlQueryModel * searchage(const QString &);


private:
    QString name,last_name,gender,mail;
    int id,age;
};

#endif // PATIENT_H
