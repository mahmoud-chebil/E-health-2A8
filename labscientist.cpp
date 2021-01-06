#include "labscientist.h"
#include "ui_labscientist.h"
#include"tests.h"
#include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QMediaPlayer>
#include"results.h"
#include"login.h"
labscientist::labscientist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::labscientist)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
            click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

labscientist::~labscientist()
{
    delete ui;
}


void labscientist::on_pushbutton_home_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void labscientist::on_pushButton_addtest_clicked()
{click->play();
    ui->tableViewpatientp2->setModel(temppatient.showpatient());
ui->stackedWidget->setCurrentIndex(2);
}

void labscientist::on_pushButton_managetest_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void labscientist::on_pushButton_manageresults_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void labscientist::on_pushButton_showtest_clicked()
{click->play();
   ui->stackedWidget->setCurrentIndex(3);
   ui->tableViewtests->setModel(temptests.show());
}

void labscientist::on_pushButton_addresults_clicked()
{click->play();
    ui->tableViewtests_2->setModel(temptests.show());
     ui->stackedWidget->setCurrentIndex(5);
}

void labscientist::on_pushButton_showresults_clicked()
{click->play();
    ui->tableViewresults->setModel(tempresults.show());
     ui->stackedWidget->setCurrentIndex(6);
}

void labscientist::on_pushButton_cancelp2_clicked()
{click->play();
     ui->stackedWidget->setCurrentIndex(1);
}

void labscientist::on_pushbutton_return_clicked()
{click->play();
     ui->stackedWidget->setCurrentIndex(1);
}

void labscientist::on_pushButton_cancelp5_clicked()
{click->play();
     ui->stackedWidget->setCurrentIndex(4);
}

void labscientist::on_pushbutton_returnp6_clicked()
{click->play();
     ui->stackedWidget->setCurrentIndex(4);
}

void labscientist::on_pushButtonaddp2_clicked()
{click->play();
    int i = ui->lineEdit_id->text().toInt();
    QString t=ui->lineEdit_type->text();


    tests r(i,t);
    bool test=r.addtest();
    if (test)
    {

        QMessageBox::information(nullptr,"add test","test added !");
    }
}

void labscientist::on_pushButtondeletep3_clicked()
{click->play();
    int id=ui->lineEdit_id_2->text().toInt();
    bool test=temptests.del(id);

    if (test)
    {ui->tableViewtests->setModel(temptests.show());

        QMessageBox::information(nullptr,"delete test","test deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete test","test not deleted !");
    }
}

void labscientist::on_pushButtonupdatep3_clicked()
{click->play();
    int i = ui->lineEdit_id_2->text().toInt();
    QString t=ui->lineEdit_type_2->text();


    tests r(i,t);
    bool test=r.updatetest();
    if (test)
    {
ui->tableViewtests->setModel(temptests.show());
        QMessageBox::information(nullptr,"update recruit","recruit updated !");
}
}

void labscientist::on_pushButtonprint_clicked()
{click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("E-Health");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}

void labscientist::on_pushButtonaddp5_clicked()
{click->play();
    int i = ui->lineEdit_idp5->text().toInt();
    QString t=ui->lineEdit_typep5->text();
    QString c=ui->comboBoxcovid->currentText();


    results r(i,t,c);
    bool test=r.addresults();
    if (test)
    {

        QMessageBox::information(nullptr,"add result","result added !");
    }
}

void labscientist::on_pushButtonupdatep6_clicked()
{click->play();
    int i = ui->lineEdit_idp5_2->text().toInt();
    QString t=ui->lineEdit_typep5_2->text();
    QString c=ui->comboBoxcovid_2->currentText();


    results r(i,t,c);
    bool test=r.updateresults();
    if (test)
    {
ui->tableViewresults->setModel(tempresults.show());
        QMessageBox::information(nullptr,"update result","result updated !");
    }
}

void labscientist::on_pushButtondeletep6_clicked()
{click->play();
    int id=ui->lineEdit_idp5_2->text().toInt();
    bool test=tempresults.del(id);

    if (test)
    {ui->tableViewresults->setModel(tempresults.show());

        QMessageBox::information(nullptr,"delete result","result deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete result","result not deleted !");
    }
}

void labscientist::on_pushButtonmail_clicked()
{click->play();
Dialog d;
d.exec();
}

void labscientist::on_pushButtonsearch_clicked()
{click->play();
    if (ui->radioButtonid->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewresults->setModel(tempresults.chercherid(type));

    }

    if (ui->radioButtontype->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewresults->setModel(tempresults.cherchertype(type));

    }

    if (ui->radioButtoncovid19->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableViewresults->setModel(tempresults.cherchercovid19(type));

    }
    if (!(ui->radioButtoncovid19->isChecked())&&!(ui->radioButtontype->isChecked())&&!(ui->radioButtonid->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("search error"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void labscientist::on_pushButton_home_2_clicked()
{click->play();
    hide();
    login l;
    l.exec();

}
