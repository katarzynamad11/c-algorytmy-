#include <iostream>
using namespace std;
#include <string>
//zadanie 1 
/*
class Class {
public:
	int x, y;
	Class(int x, int y) : x(x), y(y) {}
	Class() = default;
	Class operator+(Class& obj) {
		Class wynik;
		wynik.x = this->x + obj.x;
		wynik.y = this->y + obj.y;
		return wynik;
	}
};
*/

//zadanie 2
/*
class Class {
	int x, y;
public:
	Class(int x, int y) : x(x), y(y) {}
	Class() = default;
	int getX() { return x; }
	int getY() { return y; }
	friend Class operator+(Class& obj1, Class& obj2) {
		Class wynik;
		wynik.x = obj1.x + obj2.x;
		wynik.y = obj1.y + obj2.y;
		return wynik;
	}
};
*/

//zadanie 3
/*
class Punkt2D {
	int x, y;
public:
	Punkt2D(int x, int y) : x(x), y(y) {}
	friend ostream& operator<<(ostream& o, Punkt2D& p) {
		o << "(" << p.x << ", " << p.y << ")";
		return o;
	}

	friend istream& operator>>(istream& i, Punkt2D& p) {
		i >> p.x >> p.y;
		return i;
	}
};
*/

//zadanie 4
/*
struct TStruktura {
	string imie;
	TStruktura(string imie) : imie(imie) {}
};

bool operator!(TStruktura& s) {
	return s.imie.length() > 5;
}

*/

//zadanie 5

class TOsoba {
	string imie;
	int wiek;
public:
	TOsoba(string imie, int wiek) : imie(imie), wiek(wiek) {}
	friend ostream& operator<<(ostream& o, TOsoba& osoba);
};

ostream& operator<<(ostream& o, TOsoba& osoba) {
	o << osoba.imie << " - " << osoba.wiek << " lat";
	return o;
}


int main() {
	//zadanie 1
	/*
	Class zbior1(1, 2);
	Class zbior2(4, 5);
	Class wynik = zbior1 + zbior2;

	cout << "czesc x zbioru wynikowego: " << wynik.x << endl;
	cout << "czesc y zbioru wynikowego: " << wynik.y << endl;
	*/

	//zadanie 2
	/*
	Class obj1(3, 5);
	Class obj2(1, 3);
	Class wynik = obj1 + obj2;

	cout << "czesc x zbioru wynikowego: " << wynik.getX() << endl;
	cout << "czesc y zbioru wynikowego: " << wynik.getY() << endl;
	*/

	//zadanie 3
	/*
	Punkt2D obiekt(3,4);

cout << "obiekt: " << obiekt << endl;

cout << "Podaj wspolrzedne punktu: ";
cin >> obiekt;

cout << "Wprowadzone wspolrzedne: " << obiekt << endl;
*/

	//zadanie 4
	/*
	TStruktura tablica[] = { TStruktura("Katarzyna"), TStruktura("Tomasz"), TStruktura("Marek"), TStruktura("Magdalena"), TStruktura("Adam") };
	for (TStruktura& sprawdz : tablica) {
		if (!sprawdz) {
			cout << sprawdz.imie << endl;
		}
	}
	*/

	//zadanie 5

	TOsoba tablica[] = { {"Katarzyna", 20}, {"Marcin", 25}, {"Tomasz", 23}, {"Marek", 18}, {"Aleksandra", 16} };

	for (TOsoba& osoba : tablica) {
		cout << osoba << endl;
	}


	return 0;
}