#include "connexion.h"

connexion::connexion()
{

}

bool connexion::create_cnx()

{

    bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SNS");
db.setUserName("skander");
db.setPassword("26052301");

if (db.open())
    test=true;

return test;
}
