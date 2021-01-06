#include "tests.h"

tests::tests()
{

}

tests::tests(int x,QString d)
{
 id=x;
 type=d;


}
bool tests::addtest()
{
    QSqlQuery qry;

qry.prepare("INSERT INTO test(id,type) VALUES(:id,:type)");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":type",type);



return qry.exec();
}
bool tests::updatetest()
{
    QSqlQuery qry;

qry.prepare("UPDATE test SET id=:id,type=:type WHERE id=:id");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":type",type);



return qry.exec();
}

bool tests::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from test where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * tests::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from test");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");

return model;

}
QSqlQueryModel * tests::showpatient()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from patient");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"mail");
model->setHeaderData(4,Qt::Horizontal,"age");
model->setHeaderData(5,Qt::Horizontal,"gender");
return model;

}

