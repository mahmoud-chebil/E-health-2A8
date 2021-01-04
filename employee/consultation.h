#ifndef CONSULTATION_H
#define CONSULTATION_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class consultation
{
public:
    consultation();
   consultation(int,int,int,int,int);


    int get_id;
    int get_dates;
    int get_weight;
    int get_temperature;
    int get_pressure;

    bool add();
    QSqlQueryModel *show();
   bool del(int);

   bool update();
   QSqlQueryModel * searchid(const QString &);
   QSqlQueryModel * searchdates(const QString &);
   QSqlQueryModel * searchweight(const QString &);
private:

    int id,dates,weight,temperature,pressure;
};

#endif // CONSULTATION_H
