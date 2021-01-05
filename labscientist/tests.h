#ifndef TESTS_H
#define TESTS_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class tests
{
public:
    tests();
     tests(int ,QString);
    int get_id;
    QString get_type();


    bool addtest();
    QSqlQueryModel *show();
    QSqlQueryModel *showpatient();

   bool del(int);
   bool updatetest();
private:
    QString type;
    int id;
};

#endif // TESTS_H
