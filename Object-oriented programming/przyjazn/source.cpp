#include "header.h"

//zadanie 1
/*
TSilnik::TSilnik(int moc, int max_moment_obr) : moc(moc), max_moment_obr(max_moment_obr) {}

TSamochod::TSamochod(string model, int moc, int moment) : silnik(moc, moment), model(model) {}

void TSamochod::wypisz() {
  cout << "model: " << model << endl;
  cout << "moc: " << silnik.moc << endl;
  cout << "maksymalny moment obrotowy: " << silnik.max_moment_obr << endl;
}
*/
/*
void f_Zaprzyjaźniona(TKlasa& obj, int wartosc) {
    obj.x = wartosc;
    cout << "f_Zaprzyjaźniona zmodyfikowana, x na wartosc " << obj.x << endl;
}

void TZaprzyjaźniona_Klasa::zmienTKlasa(TKlasa& obj, int wartosc) {
    cout << "Pierwotna wartosc x: " << obj.x << endl;
    obj.x = wartosc;
    cout << "Nowa wartosc x: " << obj.x << endl;
}
*/

//zadanie 3
/*
TOkrag::TOkrag(float r, float x, float y) {
    promien = r;
    srodek.x = x;
    srodek.y = y;
}

bool PrzecinajaSie(TOkrag& k1, TOkrag& k2) {
    float odleglosc = sqrt(pow(k1.srodek.x - k2.srodek.x, 2) + pow(k1.srodek.y - k2.srodek.y, 2));
    return (odleglosc <= (k1.promien + k2.promien));
}
*/