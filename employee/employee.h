#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include"appointment.h"
#include <QMainWindow>
#include"consultation.h"
#include <QMediaPlayer>
namespace Ui {
class employee;
}

class employee : public QDialog
{
    Q_OBJECT

public:
    explicit employee(QWidget *parent = nullptr);
    ~employee();
private slots:
    void on_pushButton_addconsultation_clicked();

    void on_pushButton_consultation_clicked();

    void on_pushButtonhome_clicked();

    void on_pushButton_backp3_clicked();

    void on_pushButton_updatep3_clicked();

    void on_pushButton_deletep3_clicked();

    void on_pushButton_addappointment_clicked();

    void on_pushButton_showappointment_clicked();

    void on_pushButton_shoconsultation_clicked();

    void on_pushButtonhome_addp5_clicked();

    void on_pushButtonhome_cancelp5_clicked();

    void on_pushButton_backp6_clicked();

    void on_pushButton_updatep6_clicked();

    void on_pushButton_deletep6_clicked();

    void on_pushButton_appointment_clicked();

    void on_pushButtonhome_cancelp2_clicked();

    void on_pushButtonhome_addp2_clicked();

    void on_pushButtonhome_print_clicked();



    void on_pushButtonsearch_clicked();

    void on_pushButtonmail_clicked();

    void on_pushButtonhome_2_clicked();

private:
    Ui::employee *ui;
    appointment tempappointment;
    consultation tempconsultation;
    QMediaPlayer *click;
};

#endif // EMPLOYEE_H
