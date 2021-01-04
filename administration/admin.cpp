#include "admin.h"
#include "ui_admin.h"
#include"dialog.h"
#include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QMediaPlayer>
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButtonhome_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void admin::on_pushButtonmanagerecruits_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void admin::on_pushButtonmanagedepartment_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void admin::on_pushButtonaddrecruits_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(tempdepartment.show());
}

void admin::on_pushButtonshowrecruits_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(3);

  ui->tableViewrecruit->setModel(temprecruit.show());
}

void admin::on_pushButtonadd_clicked()
{click->play();
    int i = ui->lineEditidrecruit->text().toInt();
    QString n=ui->lineEditnamerecruit->text();
    QString l=ui->lineEditlastnamerecruit->text();
    int y = ui->lineEdityearofbirth->text().toInt();
     QString s=ui->comboBoxsex->currentText();
      QString d=ui->lineEditdepartment->text();

    recruits r(i,n,l,y,s,d);
    bool test=r.add();
    if (test)
    {

        QMessageBox::information(nullptr,"add recruit","recruit added !");
    }
}

void admin::on_pushButtoncancel_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void admin::on_pushButtonreturntop1_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void admin::on_pushButtondelete_clicked()
{click->play();
    int id=ui->lineEditidrecruit_2->text().toInt();
    bool test=temprecruit.del(id);

    if (test)
    {ui->tableViewrecruit->setModel(temprecruit.show());

        QMessageBox::information(nullptr,"delete recruit","recruit deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete recruit","recruit not deleted !");
    }
}

void admin::on_pushButtonupdate_clicked()
{click->play();
    int i = ui->lineEditidrecruit_2->text().toInt();
    QString n=ui->lineEditnamerecruit_2->text();
    QString l=ui->lineEditlastnamerecruit_2->text();
    int y = ui->lineEdityearofbirth_2->text().toInt();
     QString s=ui->comboBoxsex_2->currentText();
      QString d=ui->lineEditdepartment_2->text();

    recruits r(i,n,l,y,s,d);
    bool test=r.update();
    if (test)
    {
ui->tableViewrecruit->setModel(temprecruit.show());
        QMessageBox::information(nullptr,"update recruit","recruit updated !");
    }
}

void admin::on_pushButtonadddepartment_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void admin::on_pushButtonshowdepartment_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableViewdepartment->setModel(tempdepartment.show());
}

void admin::on_pushButtonadd_department_clicked()
{click->play();
    int id=ui->lineEditiddepartment->text().toInt();
    QString d=ui->lineEdittypedepartment->text();
    department dd(id,d);
    bool test=dd.adddepart();
    if (test)
    {

        QMessageBox::information(nullptr,"add department","department added !");
    }
}

void admin::on_pushButtoncancel_department_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void admin::on_pushButtonreturntop4_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void admin::on_pushButtondelete_department_clicked()
{click->play();
    int id=ui->lineEditiddepartment_3->text().toInt();
    bool test=tempdepartment.del(id);

    if (test)
    {ui->tableViewdepartment->setModel(tempdepartment.show());

        QMessageBox::information(nullptr,"delete department","department deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete department","department not deleted !");
    }
}

void admin::on_pushButtonupdate_department_clicked()
{click->play();
    int id=ui->lineEditiddepartment_3->text().toInt();
    QString d=ui->lineEdittypedepartment_3->text();
    department dd(id,d);
    bool test=dd.updatedepart();
    if (test)
    {ui->tableViewdepartment->setModel(tempdepartment.show());

        QMessageBox::information(nullptr,"update department","department updated !");
    }
}

void admin::on_pushButtonsearch_clicked()
{click->play();
    if (ui->radioButton->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableViewrecruit->setModel(temprecruit.chercherid(type));

    }

    if (ui->radioButtonname->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableViewrecruit->setModel(temprecruit.cherchernom(type));

    }

    if (ui->radioButtonlastname->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableViewrecruit->setModel(temprecruit.chercherpre(type));

    }
    if (!(ui->radioButtonlastname->isChecked())&&!(ui->radioButtonname->isChecked())&&!(ui->radioButton->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void admin::on_pushButtonmail_clicked()
{click->play();
    Dialog d;
    d.exec();
}

void admin::on_pushButtontri_clicked()
{click->play();
    ui->tableViewdepartment->setModel(tempdepartment.tri());
}

void admin::on_pushButtonprint_clicked()
{click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("E-Health");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}
