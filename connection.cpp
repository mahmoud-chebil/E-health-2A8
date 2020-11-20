#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("sns");//inserer le nom de la source de données ODBC
db.setUserName("mahmoud");//inserer nom de l'utilisateur
db.setPassword("mahmoud");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::fermerconnexion(){
    db.close();
}
