#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"patient.h"
#include <QMainWindow>
#include"medicalfile.h"
#include <QMediaPlayer>

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
    void on_pushButtonhome_clicked();

    void on_pushButtonmanagepatient_clicked();

    void on_pushButtonmanagefiles_clicked();

    void on_pushButtonshowpatient_clicked();

    void on_pushButtonaddpatient_clicked();

    void on_pushButtonpatientadded_clicked();

    void on_pushButtoncanceltop1_clicked();

    void on_pushButtonreturn_clicked();

    void on_pushButtonupdate_clicked();

    void on_pushButtondeletepatient_clicked();

    void on_pushButtonsearchpatient_clicked();



    void on_pushButtonfileadded_clicked();

    void on_pushButtoncanceltop4_clicked();

    void on_pushButtonupdatefile_clicked();

    void on_pushButtondeletefile_clicked();

    void on_pushButtonprint_clicked();

    void on_pushButtonreturn_2_clicked();

    void on_pushButtonaddfile_clicked();

    void on_pushButtonshowfile_clicked();

    void on_pushButtonmail_clicked();

private:
    Ui::MainWindow *ui;
    patient temppatient;
    medicalfile tempmedicalfile;
    QMediaPlayer *click;
};
#endif // MAINWINDOW_H
