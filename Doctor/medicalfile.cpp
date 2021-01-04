#include "medicalfile.h"

medicalfile::medicalfile()
{

}
medicalfile::medicalfile(int i,QString p,QString b,QString l,QString c)
{
   id=i;
   pressure=p;
   blood_type=b;
   lungs=l;

   chronic_diseases=c;


}
bool medicalfile::add()
{
   QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO medicalfile(id,pressure,blood_type,lungs,chronic_diseases) VALUES(:id,:pressure,:blood_type,:lungs,:chronic_diseases)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":pressure",pressure);
query.bindValue(":blood_type",blood_type);
query.bindValue(":lungs",lungs);

query.bindValue(":chronic_diseases",chronic_diseases);


return query.exec();
}
bool medicalfile::update()
{
   QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE medicalfile SET id=:id,pressure=:pressure,blood_type=:blood_type,lungs=:lungs,chronic_diseases=:chronic_diseases WHERE id=:id");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":pressure",pressure);
query.bindValue(":blood_type",blood_type);
query.bindValue(":lungs",lungs);

query.bindValue(":chronic_diseases",chronic_diseases);


return query.exec();
}

bool medicalfile::del(int i)
{
   QSqlQuery query;
   query.prepare("Delete from medicalfile where id=:id");
   QString res= QString::number(i);
   query.bindValue(":id",res);
   return query.exec();

}
QSqlQueryModel * medicalfile::show()
{
 QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from medicalfile");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"pressure");
model->setHeaderData(2,Qt::Horizontal,"blood_type");
model->setHeaderData(3,Qt::Horizontal,"lungs");

model->setHeaderData(4,Qt::Horizontal,"chronic_diseases");
return model;

}
