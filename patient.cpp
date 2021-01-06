#include "patient.h"

patient::patient()
{

}
patient::patient(int i,QString n,QString l,QString m,int a,QString g)
{
   id=i;
   name=n;
   last_name=l;
   mail=m;
   age=a;
   gender=g;


}
bool patient::add()
{
   QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO PATIENT(id,name,last_name,mail,age,gender) VALUES(:id,:name,:last_name,:mail,:age,:gender)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":name",name);
query.bindValue(":last_name",last_name);
query.bindValue(":mail",mail);
query.bindValue(":age",age);
query.bindValue(":gender",gender);


return query.exec();
}
bool patient::update()
{
   QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE patient SET id=:id,name=:name,last_name=:last_name,mail=:mail,age=:age,gender=:gender WHERE id=:id");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":name",name);
query.bindValue(":last_name",last_name);
query.bindValue(":mail",mail);
query.bindValue(":age",age);
query.bindValue(":gender",gender);


return query.exec();
}

bool patient::del(int i)
{
   QSqlQuery query;
   query.prepare("Delete from patient where id=:id");
   QString res= QString::number(i);
   query.bindValue(":id",res);
   return query.exec();

}
QSqlQueryModel * patient::show()
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
QSqlQueryModel * patient::searchid(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from patient where id like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"mail");
model->setHeaderData(4,Qt::Horizontal,"age");
model->setHeaderData(5,Qt::Horizontal,"gender");
return model;

}
QSqlQueryModel * patient::searchage(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from patient where age like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"mail");
model->setHeaderData(4,Qt::Horizontal,"age");
model->setHeaderData(5,Qt::Horizontal,"gender");
return model;

}
QSqlQueryModel * patient::searchname(const QString &type)
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from patient where name like '"+type+"%'");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"name");
model->setHeaderData(2,Qt::Horizontal,"last_name");
model->setHeaderData(3,Qt::Horizontal,"mail");
model->setHeaderData(4,Qt::Horizontal,"age");
model->setHeaderData(5,Qt::Horizontal,"gender");
return model;

}
