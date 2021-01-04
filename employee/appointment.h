#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class appointment
{
public:
    appointment();
    appointment(int,int);


    int get_id;
    int get_dates;

    bool add();
    QSqlQueryModel *show();
   bool del(int);

   bool update();
   QSqlQueryModel * cherchernom(const QString &);
   QSqlQueryModel * chercherpre(const QString &);
   QSqlQueryModel * chercherid(const QString &);
private:

    int id,dates;
};

#endif // APPOINTMENT_H
