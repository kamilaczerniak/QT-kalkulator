#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <math.h>
#include <string.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_P7_clicked();

    void on_P4_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P0_clicked();

    void on_P_rowna_sie_clicked();

    void on_P_dzielenie_clicked();

    void on_P_mnozenie_clicked();

    void on_P_Mplus_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P_RM_clicked();

    void on_P_minus_clicked();

    void on_P_plus_clicked();

    void on_P_C_clicked();

    void on_P9_clicked();

    void on_P8_clicked();

    void on_PComma_clicked();

    void on_P_Sqrt_clicked();

    void on_P_Potega_clicked();

    void on_P_Silnia_clicked();

    void on_P_sin_clicked();

    void on_P_cos_clicked();

    void on_P_tan_clicked();

    void on_actionStandardowy_triggered();

    void on_P_na_binarny_clicked();

    void on_P_na_dziesietny_clicked();

private:
    Ui::MainWindow *ui;


enum Operacje
{
    Plus,
    Minus,
    Mnozenie,
    Dzielenie,
    Sqrt,
    Potega,
    Silnia,
    Sinus,
    Cosinus,
    Tangens,
    Binarny,
    Dziesietny,
    BezOperacji
};

void AddToScreen(QString Text);
void OptionClicked();

void keyReleaseEvent(QKeyEvent *e);

double Left;
double Right;
bool isLeft;
bool isRight;
int Oper;
double Memory;
bool isPrzecinek;
bool ScreenClear;
double Pi = 3.141592;

};

#endif // MAINWINDOW_H
