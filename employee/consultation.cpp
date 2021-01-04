#include "consultation.h"

consultation::consultation()
{

}
consultation::consultation(int i,int d,int w,int t,int p)
{
   id=i;
   dates=d;
   weight=w;
   temperature=t;
   pressure=p;


}
bool consultation::add()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO CONSULTATION(id,dates,weight,temperature,pressure) VALUES(:id,:dates,:weight,:temperature,:pressure)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":dates",dates);
query.bindValue(":weight",weight);
query.bindValue(":temperature",temperature);
query.bindValue(":pressure",pressure);



return query.exec();
}
bool consultation::update()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE CONSULTATION SET id=:id,dates=:dates,weight=:weight,temperature=:temperature,pressure=:pressure");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":dates",dates);
query.bindValue(":weight",weight);
query.bindValue(":temperature",temperature);
query.bindValue(":pressure",pressure);



return query.exec();
}
bool consultation::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from consultation where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * consultation::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from consultation");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"weight");
model->setHeaderData(3,Qt::Horizontal,"temperature");
model->setHeaderData(4,Qt::Horizontal,"pressure");


return model;

}

QSqlQueryModel * consultation::searchid(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from consultation where id like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"weight");
model->setHeaderData(3,Qt::Horizontal,"temperature");
model->setHeaderData(4,Qt::Horizontal,"pressure");

return model;

}
QSqlQueryModel * consultation::searchdates(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from consultation where dates like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"weight");
model->setHeaderData(3,Qt::Horizontal,"temperature");
model->setHeaderData(4,Qt::Horizontal,"pressure");

return model;

}
QSqlQueryModel * consultation::searchweight(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from consultation where weight like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"weight");
model->setHeaderData(3,Qt::Horizontal,"temperature");
model->setHeaderData(4,Qt::Horizontal,"pressure");

return model;

}

