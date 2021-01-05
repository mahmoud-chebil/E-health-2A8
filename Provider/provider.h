#ifndef PROVIDER_H
#define PROVIDER_H

#include<QMessageBox>

#include <QMediaPlayer>
#include <QDialog>
#include"medicaments.h"
#include"prescription.h"
namespace Ui {
class provider;
}

class provider : public QDialog
{
    Q_OBJECT

public:
    explicit provider(QWidget *parent = nullptr);
    ~provider();

private slots:
    void on_pushbutton_home_clicked();

    void on_pushButton_home_2_clicked();

    void on_pushButton_managemedicaments_clicked();

    void on_pushButton_manageprescription_clicked();

    void on_pushButton_addmedicaments_clicked();

    void on_pushButton_showmedicaments_clicked();

    void on_pushButtonaddp2_clicked();

    void on_pushButton_cancelp2_clicked();

    void on_pushButtonupdatep3_clicked();

    void on_pushButtondeletep3_clicked();

    void on_pushButtonprint_clicked();

    void on_pushButton_addprescription_clicked();

    void on_pushButton_showprescription_clicked();

    void on_pushButtonaddp5_clicked();

    void on_pushButton_cancelp5_clicked();

    void on_pushButtonsearch_clicked();

    void on_pushbutton_returnp6_clicked();

    void on_pushButtonupdatep6_clicked();

    void on_pushButtondeletep6_clicked();

    void on_pushButtonmail_clicked();

    void on_pushbutton_return_clicked();

private:
    Ui::provider *ui;
    medicaments tempmed;
    prescription temppris;
    QMediaPlayer *click;
};

#endif // PROVIDER_H
