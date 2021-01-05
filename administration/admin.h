#ifndef ADMIN_H
#define ADMIN_H
#include"recruits.h"
#include "department.h"
#include<QMessageBox>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>
#include"login.h"
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();
private slots:
    void on_pushButtonhome_clicked();

    void on_pushButtonmanagerecruits_clicked();

    void on_pushButtonmanagedepartment_clicked();

    void on_pushButtonaddrecruits_clicked();

    void on_pushButtonshowrecruits_clicked();

    void on_pushButtonadd_clicked();

    void on_pushButtoncancel_clicked();

    void on_pushButtonreturntop1_clicked();

    void on_pushButtondelete_clicked();

    void on_pushButtonupdate_clicked();

    void on_pushButtonadddepartment_clicked();

    void on_pushButtonshowdepartment_clicked();

    void on_pushButtonadd_department_clicked();

    void on_pushButtoncancel_department_clicked();

    void on_pushButtonreturntop4_clicked();

    void on_pushButtondelete_department_clicked();

    void on_pushButtonupdate_department_clicked();

    void on_pushButtonsearch_clicked();

    void on_pushButtonmail_clicked();

    void on_pushButtontri_clicked();

    void on_pushButtonprint_clicked();

    void on_pushButtonhome_2_clicked();

private:
    Ui::admin *ui;
    recruits temprecruit;
    department tempdepartment;
    QMediaPlayer *click;

};

#endif // ADMIN_H
