#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class department
{
public:
    department();
    department(int ,QString);
    int get_id;
    QString get_type();


    bool adddepart();
    QSqlQueryModel *show();
   bool del(int);


private:
    QString type;
    int id;
};

#endif // DEPARTMENT_H
