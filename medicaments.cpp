#include "medicaments.h"

medicaments::medicaments()
{

}
medicaments::medicaments(int x,QString n,QString d,int p,int q)
{
 id=x;
 name=n;
 dates=d;
 price=p;
 quantity=q;


}
bool medicaments::addmed()
{
    QSqlQuery qry;

qry.prepare("INSERT INTO medications(id,name,dates,price,quantity) VALUES(:id,:name,:dates,:price,:quantity)");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":name",name);
qry.bindValue(":dates",dates);
qry.bindValue(":price",price);
qry.bindValue(":quantity",quantity);



return qry.exec();
}
bool medicaments::updatemed()
{
    QSqlQuery qry;

qry.prepare("UPDATE medications SET id=:id,name=:name,dates=:dates,price=:price,quantity=:quantity WHERE id=:id");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":name",name);
qry.bindValue(":dates",dates);
qry.bindValue(":price",price);
qry.bindValue(":quantity",quantity);


return qry.exec();
}

bool medicaments::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from medications where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * medicaments::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from medications");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"dates");
model->setHeaderData(3,Qt::Horizontal,"price");
model->setHeaderData(4,Qt::Horizontal,"quantity");


return model;

}
