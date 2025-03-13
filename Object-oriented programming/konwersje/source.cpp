#include "Header.h"


//ZADANIE 1 
	/*
TUlamek::TUlamek(int l, int m) : licznik(l), mianownik(m) {}

int TUlamek::zwroclicznik() {
	return licznik;
}

int TUlamek::zwrocmianownik() {
	return mianownik;
}

void TUlamek::wyswietl() {
	cout << licznik << "/" << mianownik << endl;
}

TUlamek mnozenie(TUlamek ulamek1, TUlamek ulamek2) {
	int l = ulamek1.licznik * ulamek2.licznik;
	int m = ulamek2.mianownik * ulamek2.mianownik;
	return TUlamek(l, m);
}

TUlamek::operator float() {
	return (float)licznik / (float)mianownik;
}

TUlamek::TUlamek(int l) : licznik(l), mianownik(1) {}

float kwadrat(float x) {
	return x * x;
}
*/

//ZADANIE 2
/*
TZespolona::TZespolona(double r, double u) : rzeczywista(r), urojona(u) {}


void pokaz(TZespolona z)
{
	cout << "[" << z.rzeczywista << ", " << z.urojona << "]" << endl;
}
*/

//ZADANIE 3 

Stone_weight::Stone_weight() : kamien(0), reszta_w_funtach(0.0), masa_w_funtach(0.0) {}

void Stone_weight::pokaz_mase_w_kamieniach() {
	cout << kamien << " kamieni i " << reszta_w_funtach << " funtow.\n";
}

void Stone_weight::pokaz_mase_w_funtach() {
	cout << masa_w_funtach << " funtow.\n";
}