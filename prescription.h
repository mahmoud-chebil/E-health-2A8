#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class prescription
{
public:
    prescription();
   prescription(int ,QString,int,QString);
   int get_id;
   QString get_type();
    QString get_dates();
    int get_dose;



   bool addpris();
   QSqlQueryModel *show();

  bool del(int);
  bool updatepris();
  QSqlQueryModel * chercherdose(const QString &);
  QSqlQueryModel * cherchertype(const QString &);
  QSqlQueryModel * chercherid(const QString &);
private:
   QString type,dates;
   int id,dose;
};

#endif // PRESCRIPTION_H
