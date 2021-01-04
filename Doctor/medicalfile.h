#ifndef MEDICALFILE_H
#define MEDICALFILE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class medicalfile
{
public:
    medicalfile();
    medicalfile(int,QString,QString,QString,QString);
    QString get_pressure();
    QString get_lungs();
    QString get_blood_type();
    QString get_chronic_diseases();

    int get_id;


    bool add();
    QSqlQueryModel *show();
   bool del(int);
   bool update();


private:
    QString pressure,lungs,blood_type,chronic_diseases;
    int id;
};

#endif // MEDICALFILE_H
