#include "employee.h"
#include "ui_employee.h"
#include"appointment.h"
#include<QMessageBox>
#include "administration/dialog.h"
#include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QMediaPlayer>
#include"login.h"
employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
            click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

employee::~employee()
{
    delete ui;
}
void employee::on_pushButton_addconsultation_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void employee::on_pushButton_consultation_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void employee::on_pushButtonhome_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void employee::on_pushButton_backp3_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void employee::on_pushButton_updatep3_clicked()
{ click->play();
    int i = ui->lineEditconsultationid_2->text().toInt();
        int d = ui->lineEdit_date_2->text().toInt();
        int w = ui->lineEdit_weight_2->text().toInt();
        int t = ui->lineEdit_temperature_2->text().toInt();
        int p = ui->lineEdit_bloodpressure_2->text().toInt();


        consultation r(i,d,w,t,p);
        bool test=r.update();
        if (test)
        {ui->tableView->setModel(tempconsultation.show());

            QMessageBox::information(nullptr,"update consultation","consultation updated !");
        }
}

void employee::on_pushButton_deletep3_clicked()
{ click->play();
    int id=ui->lineEditconsultationid_2->text().toInt();
    bool test=tempconsultation.del(id);

    if (test)
    {ui->tableView->setModel(tempconsultation.show());

        QMessageBox::information(nullptr,"delete consultation","consultation deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete consultation","consultation not deleted !");
    }
}

void employee::on_pushButton_addappointment_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void employee::on_pushButton_showappointment_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableView_appintment->setModel(tempappointment.show());
}

void employee::on_pushButton_shoconsultation_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableView->setModel(tempconsultation.show());
}

void employee::on_pushButtonhome_addp5_clicked()
{ click->play();
    int i = ui->lineEdit_appointmentid->text().toInt();
    int d = ui->lineEdit_dateappointment->text().toInt();


    appointment r(i,d);
    bool test=r.add();
    if (test)
    {

        QMessageBox::information(nullptr,"add appointment","appointment added !");
    }
}

void employee::on_pushButtonhome_cancelp5_clicked()
{ click->play();
ui->stackedWidget->setCurrentIndex(4);
}

void employee::on_pushButton_backp6_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void employee::on_pushButton_updatep6_clicked()
{ click->play();
    int i = ui->lineEdit_appointmentidp6->text().toInt();
    int d = ui->lineEdit_dateappointmentp6->text().toInt();


    appointment r(i,d);
    bool test=r.update();
    if (test)
    {ui->tableView_appintment->setModel(tempappointment.show());

        QMessageBox::information(nullptr,"update appointment","appointment updated !");
    }
}

void employee::on_pushButton_deletep6_clicked()
{ click->play();
    int id=ui->lineEdit_appointmentidp6->text().toInt();
    bool test=tempappointment.del(id);

    if (test)
    {ui->tableView_appintment->setModel(tempappointment.show());

        QMessageBox::information(nullptr,"delete appointment","appointment deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete appointment","appointment not deleted !");
    }
}

void employee::on_pushButton_appointment_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void employee::on_pushButtonhome_cancelp2_clicked()
{ click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void employee::on_pushButtonhome_addp2_clicked()
{ click->play();
    int i = ui->lineEditconsultationid->text().toInt();
    int d = ui->lineEdit_date->text().toInt();
    int w = ui->lineEdit_weight->text().toInt();
    int t = ui->lineEdit_temperature->text().toInt();
    int p = ui->lineEdit_bloodpressure->text().toInt();


    consultation r(i,d,w,t,p);
    bool test=r.add();
    if (test)
    {ui->tableView->setModel(tempconsultation.show());

        QMessageBox::information(nullptr,"add consultation","consultation added !");
    }

}

void employee::on_pushButtonhome_print_clicked()
{ click->play();
QPrinter rd;
QPrintDialog d(&rd,this);
d.setWindowTitle("E-Health");
d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
if(d.exec() != QDialog::Accepted)
    return ;

}

void employee::on_pushButtonsearch_clicked()
{ click->play();
    if (ui->radioButtonid->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView->setModel(tempconsultation.searchid(type));

    }

    if (ui->radioButtondates->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView->setModel(tempconsultation.searchdates(type));

    }

    if (ui->radioButtonweight->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView->setModel(tempconsultation.searchweight(type));

    }
    if (!(ui->radioButtonid->isChecked())&&!(ui->radioButtondates->isChecked())&&!(ui->radioButtonweight->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void employee::on_pushButtonmail_clicked()
{ click->play();
    Dialog d;
    d.exec();
}

void employee::on_pushButtonhome_2_clicked()
{click->play();
    hide();
    login l;
    l.exec();
}
