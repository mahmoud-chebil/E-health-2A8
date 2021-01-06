#include "login.h"

#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        qDebug()<<("database is open");
                   qDebug()<<("connection successful.\nClick Cancel to exit.");

}
    else
        qDebug()<<("database is not open");
                   qDebug()<<("connection failed.\n"
                                "Click Cancel to exit.");



    return a.exec();
}
