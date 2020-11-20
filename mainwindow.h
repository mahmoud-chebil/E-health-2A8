#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"recruits.h"
#include "department.h"
#include<QMessageBox>


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_mrecruits_clicked();

    void on_pushButton_mdepartment_clicked();

    void on_pushButton_statestics_clicked();

    void on_pushButton_addrecruit_clicked();

    void on_pushButton_showrecruit_clicked();

    void on_pushButton_adddepartment_clicked();

    void on_pushButton_showdepartment_clicked();

    void on_pushButton_p4ok_clicked();

    void on_pushButton_p4cancel_clicked();

    void on_pushButton_p6ok_clicked();

    void on_pushButton_p6cancel_clicked();



    void on_pushButton_delete_clicked();



    void on_pushButton_delete_2_clicked();

private:
    Ui::MainWindow *ui;
    recruits temprecruit;
    department tempdepartment;
};
#endif // MAINWINDOW_H
