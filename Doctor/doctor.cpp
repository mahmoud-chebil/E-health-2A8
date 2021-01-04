#include "doctor.h"
#include "ui_doctor.h"
#include"patient.h"
#include"medicalfile.h"
#include<QMessageBox>
#include"administration/dialog.h"
#include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QMediaPlayer>
doctor::doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

doctor::~doctor()
{
    delete ui;
}
void doctor::on_pushButtonhome_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void doctor::on_pushButtonmanagepatient_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void doctor::on_pushButtonmanagefiles_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void doctor::on_pushButtonshowpatient_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableViewpatient->setModel(temppatient.show());
}

void doctor::on_pushButtonaddpatient_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void doctor::on_pushButtonpatientadded_clicked()
{
    click->play();
    int i = ui->lineEditidpatient->text().toInt();
    QString n=ui->lineEditnamepatient->text();
    QString l=ui->lineEditlast_namepatient->text();
    int a = ui->lineEditagepatient->text().toInt();
     QString g=ui->comboBox->currentText();
      QString m=ui->lineEditmailpatient->text();

    patient r(i,n,l,m,a,g);
    bool test=r.add();
    if (test)
    {
ui->tableViewpatient->setModel(temppatient.show());
        QMessageBox::information(nullptr,"add patient","patient added !");
    }
}

void doctor::on_pushButtoncanceltop1_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void doctor::on_pushButtonreturn_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void doctor::on_pushButtonupdate_clicked()
{
    click->play();
    int i = ui->lineEditidpatient_2->text().toInt();
    QString n=ui->lineEditnamepatient_2->text();
    QString l=ui->lineEditlast_namepatient_2->text();
    int a = ui->lineEditagepatient_2->text().toInt();
     QString g=ui->comboBox_2->currentText();
      QString m=ui->lineEditmailpatient_2->text();

    patient r(i,n,l,m,a,g);
    bool test=r.update();
    if (test)
    {ui->tableViewpatient->setModel(temppatient.show());

        QMessageBox::information(nullptr,"update patient","patient updated !");
    }
}

void doctor::on_pushButtondeletepatient_clicked()
{
    click->play();
    int id=ui->lineEditidpatient_2->text().toInt();
    bool test=temppatient.del(id);

    if (test)
    {ui->tableViewpatient->setModel(temppatient.show());

        QMessageBox::information(nullptr,"delete patient","patient deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete patient","patient not deleted !");
    }
}

void doctor::on_pushButtonsearchpatient_clicked()
{
    click->play();
    if (ui->radioButtonid->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewpatient->setModel(temppatient.searchid(type));

    }

    if (ui->radioButtonname->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewpatient->setModel(temppatient.searchname(type));

    }

    if (ui->radioButtonage->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewpatient->setModel(temppatient.searchage(type));

    }
    if (!(ui->radioButtonage->isChecked())&&!(ui->radioButtonname->isChecked())&&!(ui->radioButtonid->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("search failed"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void doctor::on_pushButtonaddfile_clicked()
{
    click->play();
   ui->stackedWidget->setCurrentIndex(5);
}

void doctor::on_pushButtonshowfile_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableView->setModel(tempmedicalfile.show());
}

void doctor::on_pushButtonfileadded_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(5);
    int i = ui->lineEditidfile->text().toInt();
    QString p=ui->lineEditfilepressure->text();
    QString b=ui->lineEditlast_namepatient->text();

     QString l=ui->comboBox_3->currentText();
      QString c=ui->lineEditchronicdiseases->text();

   medicalfile r(i,p,b,l,c);
    bool test=r.add();
    if (test)
    {
ui->tableView->setModel(tempmedicalfile.show());
        QMessageBox::information(nullptr,"add medicalfile","medicalfile added !");
    }
}

void doctor::on_pushButtoncanceltop4_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void doctor::on_pushButtonupdatefile_clicked()
{
    click->play();

    int i = ui->lineEditidfile_2->text().toInt();
    QString p=ui->lineEditfilepressure_2->text();
    QString b=ui->lineEditlast_namepatient_2->text();

     QString l=ui->comboBox_4->currentText();
      QString c=ui->lineEditchronicdiseases_2->text();

   medicalfile r(i,p,b,l,c);
    bool test=r.update();
    if (test)
    {
ui->tableView->setModel(tempmedicalfile.show());
        QMessageBox::information(nullptr,"update medicalfile","medicalfile updated !");
    }
}

void doctor::on_pushButtondeletefile_clicked()
{
    click->play();
    int id=ui->lineEditidfile_2->text().toInt();
    bool test=tempmedicalfile.del(id);

    if (test)
    {ui->tableView->setModel(tempmedicalfile.show());

        QMessageBox::information(nullptr,"delete file","file deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete file","file not deleted !");
    }
}

void doctor::on_pushButtonprint_clicked()
{
    click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("E-Health");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}

void doctor::on_pushButtonreturn_2_clicked()
{
    click->play();
ui->stackedWidget->setCurrentIndex(4);
}



void doctor::on_pushButtonmail_clicked()
{
    click->play();
    Dialog d;
    d.exec();
}
