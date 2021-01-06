#include "login.h"
#include "ui_login.h"
#include"administration/admin.h"
#include"administration/dialog.h"
#include"Doctor/doctor.h"
#include"employee/employee.h"
#include"Provider/provider.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
void login::on_pushButton_login_clicked()
{admin w;
 doctor d;
 employee e;
 labscientist l;
 provider p;



    QString mail = ui->lineEdit_mail->text();
        QString password = ui->lineEdit_password->text();

        QSqlQuery query;

        if (query.exec("SELECT * from login WHERE mail ='"+mail+"' AND password ='"+password+"'"))

           {if(mail=="admin")
            {int count=0;
            while(query.next())
            {count++;}
       if(count==1)
            {
             // QMessageBox::information(this, "loginin", "mail and Password are correct");
              hide();
               w.exec();

            }
}
            if(mail=="doctor")
                        {int count=0;
                        while(query.next())
                        {count++;}
                   if(count==1)
                        {
                         // QMessageBox::information(this, "login", "mail and Password are correct");
                          hide();
                           d.exec();

                        }}
                   if(mail=="employee")
                               {int count=0;
                               while(query.next())
                               {count++;}
                          if(count==1)
                               {
                                // QMessageBox::information(this, "login", "mail and Password are correct");
                                 hide();
                                  e.exec();

                               }
            }
                   if(mail=="labscientist")
                               {int count=0;
                               while(query.next())
                               {count++;}
                          if(count==1)
                               {
                                // QMessageBox::information(this, "login", "mail and Password are correct");
                                 hide();
                                  l.exec();

                               }
            }
                   if(mail=="provider")
                               {int count=0;
                               while(query.next())
                               {count++;}
                          if(count==1)
                               {
                                // QMessageBox::information(this, "login", "mail and Password are correct");
                                 hide();
                                  p.exec();

                               }
            }
        else if(mail!="admin"||mail!="doctor"||mail!="labscientist"||mail!="employee"||mail!="provider")
            {
              qDebug()<<("mail and Password are incorrect");
            }
}
}
