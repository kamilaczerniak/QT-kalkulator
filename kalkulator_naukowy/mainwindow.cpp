#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <windows.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Left = 0;
    Right = 0;
    isPrzecinek = false;
    Oper = this->BezOperacji;
    Memory = 0;
    isLeft = false;
    isRight = false;
    ScreenClear = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Wczytywanie z przycisków numerycznych
void MainWindow::on_P0_clicked()
{
    AddToScreen("0");
}
void MainWindow::on_P1_clicked()
{
    AddToScreen("1");
}
void MainWindow::on_P2_clicked()
{
    AddToScreen("2");
}
void MainWindow::on_P3_clicked()
{
    AddToScreen("3");
}
void MainWindow::on_P4_clicked()
{
    AddToScreen("4");
}
void MainWindow::on_P5_clicked()
{
    AddToScreen("5");
}
void MainWindow::on_P6_clicked()
{
    AddToScreen("6");
}
void MainWindow::on_P7_clicked()
{
    AddToScreen("7");
}
void MainWindow::on_P8_clicked()
{
    AddToScreen("8");
}
void MainWindow::on_P9_clicked()
{
    AddToScreen("9");
}

//Klawisz przecinka
void MainWindow::on_PComma_clicked()
{
    if(isPrzecinek == true) return;
    ui->EScreen->setText(ui->EScreen->text().append("."));
    isPrzecinek = true;
}

//Przycisk wczytujący do pamięci
void MainWindow::on_P_RM_clicked()
{
    ui->EScreen->setText(QString::number(Memory));
}

//Wypisywanie liczby z pamięci
void MainWindow::on_P_Mplus_clicked()
{
    Memory = ui->EScreen->text().toDouble();
}
void MainWindow::AddToScreen(QString Text){
    QString oldtext = ui->EScreen->text();
    if(oldtext.length()>=ui->EScreen->maxLength())return;
    if(oldtext=="0")oldtext.clear();
    if(ScreenClear)
    {
        oldtext.clear();
        ScreenClear = false;
    }
    oldtext.append(Text);
    ui->EScreen->setText(oldtext);
}

//Przycisk odejmowania
void MainWindow::on_P_minus_clicked()
{
    OptionClicked();
    Oper = Minus;
}

//Przycisk dodawania
void MainWindow::on_P_plus_clicked()
{
    OptionClicked();
    Oper = Plus;
}

//Przycisk dzielenia
void MainWindow::on_P_dzielenie_clicked()
{
    OptionClicked();
    Oper = Dzielenie;
}

//Przycisk mnożenia
void MainWindow::on_P_mnozenie_clicked()
{
    OptionClicked();
    Oper = Mnozenie;
}

//Przycisk pierwiastka
void MainWindow::on_P_Sqrt_clicked()
{
    OptionClicked();
    Oper = Sqrt;
}

//Przycisk potęgowania
void MainWindow::on_P_Potega_clicked()
{
    OptionClicked();
    Oper = Potega;
}

//Przycisk silnia
void MainWindow::on_P_Silnia_clicked()
{
    OptionClicked();
    Oper = Silnia;
}

//Przycisk sinus
void MainWindow::on_P_sin_clicked()
{
    OptionClicked();
    Oper = Sinus;
}

//Przycisk cosinus
void MainWindow::on_P_cos_clicked()
{
    OptionClicked();
    Oper = Cosinus;
}

//Przycisk tangens
void MainWindow::on_P_tan_clicked()
{
    OptionClicked();
    Oper = Tangens;
}

//Przycisk przeliczania z dziesietnego na dwojkowy
void MainWindow::on_P_na_binarny_clicked()
{
    OptionClicked();
    Oper = Binarny;
}

//Przycisk przeliczania z dwojkowego na dziesietny
void MainWindow::on_P_na_dziesietny_clicked()
{
    OptionClicked();
    Oper = Dziesietny;
}

//Przycisk kasowania
void MainWindow::on_P_C_clicked()
{
    Left = 0;
    Right = 0;
    isPrzecinek = false;
    Oper = this-> BezOperacji;
    Memory = 0;
    ui->EScreen->setText("0");
    isLeft = false;
    isRight = false;
    ScreenClear = false;
}

//Obsługa klawiszy klawiatury
void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_0:
        on_P0_clicked();
        e->accept();
        break;

    case Qt::Key_1:
        on_P1_clicked();
        e->accept();
        break;

    case Qt::Key_2:
        on_P2_clicked();
        e->accept();
        break;

    case Qt::Key_3:
        on_P3_clicked();
        e->accept();
        break;

    case Qt::Key_4:
        on_P4_clicked();
        e->accept();
        break;

    case Qt::Key_5:
        on_P5_clicked();
        e->accept();
        break;

    case Qt::Key_6:
        on_P6_clicked();
        e->accept();
        break;

    case Qt::Key_7:
        on_P7_clicked();
        e->accept();
        break;

    case Qt::Key_8:
        on_P8_clicked();
        e->accept();
        break;

    case Qt::Key_9:
        on_P9_clicked();
        e->accept();
        break;

    case Qt::Key_Plus:
        on_P_plus_clicked();
        e->accept();
        break;

    case Qt::Key_Minus:
        on_P_minus_clicked();
        e->accept();
        break;

    case Qt::Key_Slash:
        on_P_dzielenie_clicked();
        e->accept();
        break;

    case Qt::Key_Asterisk:
        on_P_mnozenie_clicked();
        e->accept();
        break;

    case Qt::Key_Equal:
        on_P_rowna_sie_clicked();
        e->accept();
        break;

    case Qt::Key_Enter:
        on_P_rowna_sie_clicked();
        e->accept();
        break;

    case Qt::Key_Comma:
        on_PComma_clicked();
        e->accept();
        break;

    case Qt::Key_Backspace:
        on_P_C_clicked();
        e->accept();
        break;

    default:
e->ignore();
        break;
    }
 }

//Przycisk równa się
void MainWindow::on_P_rowna_sie_clicked()
{
    if(!(isLeft)) return;
    Right = ui->EScreen->text().toDouble();
    double tmp = 0;      //Inicjalizacja zminnych użytych w funkcjach
    QString tmp2, wynik, brak = "Brak";

switch (Oper) {
    case Plus:          //Dodawanie
        tmp = Left + Right;
        break;

    case Minus:         //Odejmowanie
        tmp = Left - Right;
        break;

    case Mnozenie:      //Mnożenie
        tmp = Left * Right;
        break;

    case Dzielenie:     //Dzielenie
        if (Right == 0) break;
        tmp = Left / Right;
    break;

    case Sqrt:          //Pierwiastek
        tmp = pow(Left,(1/Right));
        break;

    case Potega:        //Potęgowanie
        tmp = pow(Left,Right);
        break;

    case Silnia:        //Silnia
        if(isLeft == true && Left >= 0 ){ //Sprawdzanie czy liczba jest większa od zera
            tmp = 1;
            for (int i = 1; i <= Left; ++i){
                tmp = tmp * i;
            }
         }
        break;

    case Sinus:         //Sinus
        tmp = sin(Left*Pi/180);
        break;

    case Cosinus:       //Cosinus
         tmp = cos(Left*Pi/180);
         break;

    case Tangens:       //Tangens
         tmp = tan(Left*Pi/180);
         break;

    case Binarny:       //Przeliczanie z systemu dziesiątkowego na binarny
        double calkowita, ulamkowa;
        ulamkowa = modf(Left, &calkowita);  //Rozbicie na część całkowitą i ułamkową
        if (ulamkowa != 0){
            QMessageBox::information(this,"Uwaga","Czesc ulamkowa zostanie pominieta");
        }
        while (calkowita != 0){
            if (int(calkowita) % 2 != 0) {
                tmp2 = "1";
            }
            else {
                tmp2 = "0";
            }
            calkowita /= 2;
            wynik = tmp2 + wynik;
            ulamkowa = modf(calkowita, &calkowita);
            }
        break;

    case Dziesietny:    //Przeliczanie z systemu binarnego na dziesietny
        QString wynik, tmp2;
        wynik = ui->EScreen->text();
        for (int i = 0; i < wynik.size(); ++i){
            tmp2 = wynik[wynik.size() - 1 - i];
            if (tmp2 != "1" && tmp2 != "0"){
                QMessageBox::information(this,"Uwaga!", "Liczba nie ma zapisu binarnego");
                tmp = 0;
                break;
            }
            if (tmp2 == "1"){
                tmp += pow(2.0, i) * 1.0;
            } else {
                tmp += pow(2.0, i) * 0.0;
            }
        }
        break;
}

//Wyświetlanie wyniku i przywracanie do wartości początkowych
ScreenClear = true;
if (Oper == Binarny){               //Warunek wyświetlania QStringa lub double
    ui->EScreen->setText(wynik);
} else {
    ui->EScreen->setText(QString::number(tmp));
}
Left = 0;
Right = 0;
isRight = false;
isLeft = false;
}

//Wczytywanie wartości do double
void MainWindow::OptionClicked()
{
    if(!isLeft)
    {
       Left = ui->EScreen->text().toDouble();
       isLeft = true;
       ScreenClear = true;
       isPrzecinek = false;
    }
}

void MainWindow::on_actionStandardowy_triggered()
{
    ui->statusBar->showMessage("K", 2000);

}

