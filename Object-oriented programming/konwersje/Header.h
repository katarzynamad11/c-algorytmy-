#include <iostream>
using namespace std;


//ZADANIE 1 
    /*
class TUlamek {
private:
    int licznik;
    int mianownik;
public:
    TUlamek(int l, int m);
    int zwroclicznik();
    int zwrocmianownik();
    void wyswietl();
    friend TUlamek mnozenie(TUlamek ulamek1, TUlamek ulamek2);
    operator float();
    TUlamek(int l);
};

float kwadrat(float x);
*/

//ZADANIE 2
/*
class TZespolona {
private:
    double rzeczywista;
    double urojona;
public:
   
    TZespolona(double r = 0, double u = 0); // konstruktor domyślny

    friend void pokaz(TZespolona z);

};
*/

//ZADANIE 3

class Stone_weight {
private:
    int ilosc_funtow_na_kamien = 14;
    int kamien;
    double reszta_w_funtach;
    double masa_w_funtach;
public:
    Stone_weight();
    Stone_weight(double waga_w_funtach);
    Stone_weight(int ilosc_kamieni, double ilosc_funtow);
    void pokaz_mase_w_funtach();
    void pokaz_mase_w_kamieniach();
    void pokaz_mase_w_funtach();
};
