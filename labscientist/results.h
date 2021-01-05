#ifndef RESULTS_H
#define RESULTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class results
{
public:
    results();
    results(int ,QString,QString);
   int get_id;
   QString get_type();
    QString get_covid19();


   bool addresults();
   QSqlQueryModel *show();

  bool del(int);
  bool updateresults();
  QSqlQueryModel * cherchertype(const QString &);
  QSqlQueryModel * cherchercovid19(const QString &);
  QSqlQueryModel * chercherid(const QString &);
private:
   QString type,covid19;
   int id;
};

#endif // RESULTS_H
