#ifndef LABSCIENTIST_H
#define LABSCIENTIST_H

#include<QMessageBox>

#include <QMediaPlayer>
#include <QDialog>
#include"tests.h"
#include"results.h"
#include"administration/dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class labscientist; }
QT_END_NAMESPACE

class labscientist : public QDialog
{
    Q_OBJECT

public:
    labscientist(QWidget *parent = nullptr);
    ~labscientist();

private slots:
    void on_pushbutton_home_clicked();

    void on_pushButton_addtest_clicked();

    void on_pushButton_managetest_clicked();

    void on_pushButton_manageresults_clicked();

    void on_pushButton_showtest_clicked();

    void on_pushButton_addresults_clicked();

    void on_pushButton_showresults_clicked();

    void on_pushButton_cancelp2_clicked();

    void on_pushbutton_return_clicked();

    void on_pushButton_cancelp5_clicked();

    void on_pushbutton_returnp6_clicked();

    void on_pushButtonaddp2_clicked();

    void on_pushButtondeletep3_clicked();

    void on_pushButtonupdatep3_clicked();

    void on_pushButtonprint_clicked();

    void on_pushButtonaddp5_clicked();

    void on_pushButtonupdatep6_clicked();

    void on_pushButtondeletep6_clicked();

    void on_pushButtonmail_clicked();

    void on_pushButtonsearch_clicked();

    void on_pushButton_home_2_clicked();

private:
    Ui::labscientist *ui;
tests temptests;
tests temppatient;
results tempresults;
QMediaPlayer *click;
};
#endif // LABSCIENTIST_H
