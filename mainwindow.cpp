#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_mrecruits_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_mdepartment_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_statestics_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_addrecruit_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_showrecruit_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
  ui->tablerecruit->setModel(temprecruit.show());

}

void MainWindow::on_pushButton_adddepartment_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_showdepartment_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
      ui->tabledepart->setModel(tempdepartment.show());
}

void MainWindow::on_pushButton_p4ok_clicked()
{
    int i = ui->lineEdit_id->text().toInt();
    QString n=ui->lineEdit_name->text();
    QString l=ui->lineEdit_lname->text();
    int y = ui->lineEdit_year->text().toInt();
     QString s=ui->comboBox_sex->currentText();
      QString d=ui->comboBox_department->currentText();

    recruits r(i,n,l,y,s,d);
    bool test=r.add();
    if (test)
    {

        QMessageBox::information(nullptr,"add recruit","recruit added !");
    }
}

void MainWindow::on_pushButton_p4cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_p6ok_clicked()
{
    int id=ui->lineEdit_department->text().toInt();
    QString d=ui->comboBox_adddepartment->currentText();
    department dd(id,d);
    bool test=dd.adddepart();
    if (test)
    {

        QMessageBox::information(nullptr,"add department","department added !");
    }
}

void MainWindow::on_pushButton_p6cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_delete_clicked()
{

   int id=ui->lineEdit_del->text().toInt();
   bool test=temprecruit.del(id);

   if (test)
   {

       QMessageBox::information(nullptr,"delete recruit","recruit deleted !");
   }
   else
   {
     QMessageBox::warning(nullptr,"delete recruit","recruit not deleted !");
   }
}


void MainWindow::on_pushButton_delete_2_clicked()
{
    int id=ui->lineEdit_deldepart->text().toInt();
    bool test=tempdepartment.del(id);

    if (test)
    {

        QMessageBox::information(nullptr,"delete department","department deleted !");
    }
    else
    {
      QMessageBox::warning(nullptr,"delete department","department not deleted !");
    }
}
