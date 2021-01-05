#include "results.h"

results::results()
{

}
results::results(int x,QString d,QString c)
{
 id=x;
 type=d;
 covid19=c;


}
bool results::addresults()
{
    QSqlQuery qry;

qry.prepare("INSERT INTO results(id,type,covid19) VALUES(:id,:type,:covid19)");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":type",type);
qry.bindValue(":covid19",covid19);



return qry.exec();
}
bool results::updateresults()
{
    QSqlQuery qry;

qry.prepare("UPDATE results SET id=:id,type=:type,covid19=:covid19 WHERE id=:id");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":type",type);
qry.bindValue(":covid19",covid19);



return qry.exec();
}

bool results::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from results where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * results::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from results");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");
model->setHeaderData(2,Qt::Horizontal,"covid19");

return model;

}
QSqlQueryModel * results::chercherid(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from results where id like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");
model->setHeaderData(2,Qt::Horizontal,"covid19");

return model;

}
QSqlQueryModel * results::cherchertype(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from results where type like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");
model->setHeaderData(2,Qt::Horizontal,"covid19");

return model;

}
QSqlQueryModel * results::cherchercovid19(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from results where covid19 like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");
model->setHeaderData(2,Qt::Horizontal,"covid19");

return model;

}
