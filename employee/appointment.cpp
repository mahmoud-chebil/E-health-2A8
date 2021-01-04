    #include "appointment.h"

appointment::appointment()
{

}
appointment::appointment(int i,int d)
{
   id=i;
   dates=d;


}
bool appointment::add()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO APPOINTMENT(id,dates) VALUES(:id,:dates)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":dates",dates);



return query.exec();
}
bool appointment::update()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE APPOINTMENT SET id=:id,dates=:dates");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":dates",dates);



return query.exec();
}
bool appointment::del(int i)
{
    QSqlQuery query;
    query.prepare("Delete from appointment where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * appointment::show()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from appointment");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"dates");

return model;

}
