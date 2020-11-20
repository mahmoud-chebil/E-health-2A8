#include "department.h"

department::department()
{

}
department::department(int x,QString d)
{
 id=x;
 type=d;


}
bool department::adddepart()
{
    QSqlQuery qry;

qry.prepare("INSERT INTO DEPARTMENT(id,type) VALUES(:id,:type)");

QString res=QString::number(id);
qry.bindValue(":id",res);
qry.bindValue(":type",type);



return qry.exec();
}


bool department::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from department where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * department::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from department");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"type");

return model;

}
