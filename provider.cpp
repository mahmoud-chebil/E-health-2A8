#include "provider.h"
#include "ui_provider.h"
#include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QMediaPlayer>
#include "administration/dialog.h"
#include"login.h"
provider::provider(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::provider)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
            click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

provider::~provider()
{
    delete ui;
}

void provider::on_pushbutton_home_clicked()
{click->play();
   ui->stackedWidget->setCurrentIndex(0);
}

void provider::on_pushButton_home_2_clicked()
{click->play();
    hide();
        login l;
        l.exec();

}

void provider::on_pushButton_managemedicaments_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void provider::on_pushButton_manageprescription_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void provider::on_pushButton_addmedicaments_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void provider::on_pushButton_showmedicaments_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableViewmedicaments->setModel(tempmed.show());
}

void provider::on_pushButtonaddp2_clicked()
{click->play();
    int i = ui->lineEdit_id->text().toInt();
    QString n=ui->lineEdit_name->text();
    QString d = ui->lineEditdatesp2->text();
    int p = ui->lineEditprice->text().toInt();
    int q = ui->lineEditquantity->text().toInt();

    medicaments med(i,n,d,p,q);
    bool test=med.addmed();
    if (test)
    {

        QMessageBox::information(nullptr,"add medicament","medicament added !");
    }
}

void provider::on_pushButton_cancelp2_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void provider::on_pushButtonupdatep3_clicked()
{click->play();
    int i = ui->lineEdit_id_2->text().toInt();
    QString n=ui->lineEdit_name_2->text();
    QString d = ui->lineEditdatesp2_2->text();
    int p = ui->lineEditprice_2->text().toInt();
    int q = ui->lineEditquantity_2->text().toInt();

    medicaments med(i,n,d,p,q);
    bool test=med.updatemed();
    if (test)
    {
ui->tableViewmedicaments->setModel(tempmed.show());
        QMessageBox::information(nullptr,"update medicament","medicament updated !");
}
}

void provider::on_pushButtondeletep3_clicked()
{click->play();
    int id=ui->lineEdit_id_2->text().toInt();
    bool test=tempmed.del(id);

    if (test)
    {ui->tableViewmedicaments->setModel(tempmed.show());

        QMessageBox::information(nullptr,"delete medicament","medicament deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete medicament","medicament not deleted !");
    }
}

void provider::on_pushButtonprint_clicked()
{click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("E-Health");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}


void provider::on_pushButton_addprescription_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void provider::on_pushButton_showprescription_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableViewPrescription->setModel(temppris.show());
}

void provider::on_pushButtonaddp5_clicked()
{click->play();
    int i = ui->lineEdit_idp5->text().toInt();
    QString dt = ui->lineEditdates->text();
    int d = ui->lineEditdose->text().toInt();
    QString t = ui->lineEdit_typep5->text();

    prescription pris(i,dt,d,t);
    bool test=pris.addpris();
    if (test)
    {

        QMessageBox::information(nullptr,"add priscription","priscription added !");
    }
}

void provider::on_pushButton_cancelp5_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void provider::on_pushButtonsearch_clicked()
{click->play();
    if (ui->radioButtonid->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewPrescription->setModel(temppris.chercherid(type));

    }

    if (ui->radioButtontype->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewPrescription->setModel(temppris.cherchertype(type));

    }

    if (ui->radioButtondose->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewPrescription->setModel(temppris.chercherdose(type));

    }
    if (!(ui->radioButtondose->isChecked())&&!(ui->radioButtontype->isChecked())&&!(ui->radioButtonid->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("search error"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void provider::on_pushbutton_returnp6_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void provider::on_pushButtonupdatep6_clicked()
{click->play();
    int i = ui->lineEdit_idp5_2->text().toInt();
    QString dt = ui->lineEditdates_2->text();
    int d = ui->lineEditdose_2->text().toInt();
    QString t = ui->lineEdit_typep5_2->text();

    prescription pris(i,dt,d,t);
    bool test=pris.updatepris();
    if (test)
    {
    ui->tableViewPrescription->setModel(temppris.show());
        QMessageBox::information(nullptr,"update priscription","priscription updated !");
    }
}

void provider::on_pushButtondeletep6_clicked()
{click->play();
    int id=ui->lineEdit_idp5_2->text().toInt();
    bool test=temppris.del(id);

    if (test)
    {ui->tableViewPrescription->setModel(temppris.show());

        QMessageBox::information(nullptr,"delete priscription","priscription deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete priscription","priscription not deleted !");
    }
}

void provider::on_pushButtonmail_clicked()
{click->play();
    Dialog d;
    d.exec();
}

void provider::on_pushbutton_return_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}
