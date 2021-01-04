#include "recruits.h"
#include"department.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



recruits::recruits()
{

}
 recruits::recruits(int i,QString n,QString l,int y,QString s,QString d)
 {
    id=i;
    name=n;
    last_name=l;
    year_of_birth=y;
    sex=s;
    department=d;


 }
bool recruits::add()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO RECRUITS(id,name,last_name,year_of_birth,sex,department) VALUES(:id,:name,:last_name,:year_of_birth,:sex,:department)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":name",name);
query.bindValue(":last_name",last_name);
query.bindValue(":year_of_birth",year_of_birth);
query.bindValue(":sex",sex);
query.bindValue(":department",department);


return query.exec();
}
bool recruits::update()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE recruits SET id=:id,name=:name,last_name=:last_name,year_of_birth=:year_of_birth,sex=:sex,department=:department WHERE id=:id");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":name",name);
query.bindValue(":last_name",last_name);
query.bindValue(":year_of_birth",year_of_birth);
query.bindValue(":sex",sex);
query.bindValue(":department",department);


return query.exec();
}

bool recruits::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from recruits where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * recruits::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from recruits");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"year_of_birth");
model->setHeaderData(4,Qt::Horizontal,"sex");
model->setHeaderData(5,Qt::Horizontal,"department");
return model;

}
QSqlQueryModel * recruits::chercherid(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from recruits where id like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"year_of_birth");
model->setHeaderData(4,Qt::Horizontal,"sex");
model->setHeaderData(5,Qt::Horizontal,"department");
return model;

}
QSqlQueryModel * recruits::chercherpre(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from recruits where last_name like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"year_of_birth");
model->setHeaderData(4,Qt::Horizontal,"sex");
model->setHeaderData(5,Qt::Horizontal,"department");
return model;

}
QSqlQueryModel * recruits::cherchernom(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from recruits where name like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"year_of_birth");
model->setHeaderData(4,Qt::Horizontal,"sex");
model->setHeaderData(5,Qt::Horizontal,"department");
return model;

}
