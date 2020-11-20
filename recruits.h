#ifndef RECRUITS_H
#define RECRUITS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class recruits
{
public:
    recruits();
    recruits(int,QString,QString,int,QString,QString);
    QString get_name();
    QString get_last_name();
    QString get_sex();
    QString get_department();

    int get_id;
    int get_year_of_birth;

    bool add();
    QSqlQueryModel *show();
   bool del(int);


private:
    QString name,last_name,sex,department;
    int id,year_of_birth;
};

#endif // RECRUITS_H
