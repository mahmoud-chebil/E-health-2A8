#include "prescription.h"

prescription::prescription()
{

}
prescription::prescription(int x,QString dt,int d,QString t)
{
 id=x;
 type=t;
 dates=dt;
 dose=d;


}
bool prescription::addpris()
{
    QSqlQuery qry;

qry.prepare("INSERT INTO prescription(id,dates,dose,type) VALUES(:id,:dates,:dose,:type)");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":dates",dates);
qry.bindValue(":dose",dose);
qry.bindValue(":type",type);




return qry.exec();
}
bool prescription::updatepris()
{
    QSqlQuery qry;

qry.prepare("UPDATE prescription SET id=:id,dates=:dates,dose=:dose,type=:type WHERE id=:id");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":dates",dates);
qry.bindValue(":dose",dose);
qry.bindValue(":type",type);




return qry.exec();
}

bool prescription::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from prescription where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * prescription::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from prescription");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"dose");
model->setHeaderData(3,Qt::Horizontal,"type");
return model;

}
QSqlQueryModel * prescription::chercherid(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from prescription where id like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"dose");
model->setHeaderData(3,Qt::Horizontal,"type");
return model;

}
QSqlQueryModel * prescription::cherchertype(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from prescription where type like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"dose");
model->setHeaderData(3,Qt::Horizontal,"type");

return model;

}
QSqlQueryModel * prescription::chercherdose(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from prescription where dose like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");
model->setHeaderData(2,Qt::Horizontal,"dose");
model->setHeaderData(3,Qt::Horizontal,"type");

return model;

}
