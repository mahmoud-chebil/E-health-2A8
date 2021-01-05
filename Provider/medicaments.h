#ifndef MEDICAMENTS_H
#define MEDICAMENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class medicaments
{
public:
    medicaments();
    medicaments(int ,QString,QString,int,int);
   int get_id;
   QString get_name();
   QString get_dates();
   int get_price;
   int get_quantity;


   bool addmed();
   QSqlQueryModel *show();

  bool del(int);
  bool updatemed();
private:
   QString name,dates;
   int id,price,quantity;
};

#endif // MEDICAMENTS_H
