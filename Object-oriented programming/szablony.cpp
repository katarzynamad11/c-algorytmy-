#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//zadanie 1
/*
template<typename T>
T Dodaj(T a, T b) {
	return a + b;
}
*/

//zadanie 2
/*
template<typename R>
R Max(R a, R b) {
	return (a > b) ? a : b;
}
*/

//zadanie 3
/*
template<typename T, int Rozmiar>
class Tablica {
private:
	T* elementy;
public:
	Tablica() { elementy = new T[Rozmiar]; }
	~Tablica() { delete[] elementy; }
};
*/

//zadanie 4
/*
template<typename T>
class Kula {
private:
	T promien;
public:
	Kula(T r) : promien(r) {}

	T PolePowierzchni() {
		return 4 * 3.14 * promien * promien;
	}

	T Objętość() {
		return (4.0 / 3.0) * 3.14 * promien * promien * promien;
	}
};
*/

//zadanie 5
/*
template<typename T, int Rozmiar>
class Tablica {
private:
	T elementy[Rozmiar];
public:
	void ustawelement(int indeks, T wartosc) {
		if (indeks >= 0 && indeks < Rozmiar) {
			elementy[indeks] = wartosc;
		}
	}
	T suma() {
	T suma = 0;
	for (int i = 0; i < Rozmiar; i++) {
		suma += elementy[i];
	}
	return suma;
}
};
*/

//zadanie 6
/*
template<typename T>
T PoleProstopadloscianu(T a, T b, T c) {
	return 2 * (a * b + a * c + b * c);
}
*/

//zadanie 7
/*
template<typename T>
class Prostopadloscian {
private:
	T a, b, c;

public:
	Prostopadloscian(T a, T b, T c) : a(a), b(b), c(c) {}

	T PoleProstopadłościanu() {
		return 2 * (a * b + a * c + b * c);
	}
};
*/




int main() {

	//zadanie 1
	/*
	int l1 = 2;
	int l2 = 3;
	int wynikint = Dodaj<int>(l1, l2);
	cout << "suma liczb calkowitych: " << wynikint << endl;

	double l11 = 2.3;
	double l12 = 3.5;
	double wynikdouble = Dodaj<double>(l11, l12);
	cout << "suma liczb zmiennoprzecinkowych: " << wynikdouble << endl;

	string l21 = "Milego";
	string l22 = " dnia";
	string wynikstring = Dodaj<string>(l21, l22);
	cout << "suma stringow: " << wynikstring << endl;
	*/

	//zadanie 2
	/*
	int a = 5, b = 4;
	double x = 12.4, y = 3.2;
	cout << "wiekszy int: " << Max(a, b) << endl;
	cout << "wiekszy double: " << Max(x, y) << endl;
	*/

	//zadanie 3
	/*
	Tablica<int, 4> tablicaint;
	Tablica<double, 7> tablicadouble;
	*/

	//zadanie 4
	/*
	Kula<int> kulaint(4);
	cout << "kula o promieniu 4, int: " << endl;
	cout << "pole powierzchni: " << kulaint.PolePowierzchni() << endl;
	cout << "objetosc: " << kulaint.Objętość() << endl;

	Kula<double> kuladouble(2.2312);
	cout << "kula o promieniu 2.2312, double: " << endl;
	cout << "pole powierzchni: " << kuladouble.PolePowierzchni() << endl;
	cout << "objetosc: " << kuladouble.Objętość() << endl;

	Kula<float> kulafloat(2.3);
	cout << "kula o promieniu 2.3, float: " << endl;
	cout << "pole powierzchni: " << kulafloat.PolePowierzchni() << endl;
	cout << "objetosc: " << kulafloat.Objętość() << endl;
	*/

	//zadanie 5
	/*
	Tablica<int, 5> tablicaInt;
	tablicaInt.ustawelement(0, 1);
	tablicaInt.ustawelement(1, 2);
	tablicaInt.ustawelement(2, 3);
	tablicaInt.ustawelement(3, 4);
	tablicaInt.ustawelement(4, 5);

	int sumaInt = tablicaInt.suma();
	cout << "Suma elementow tablicy int: " << sumaInt << endl;

	Tablica<double, 3> tablicaDouble;
	tablicaDouble.ustawelement(0, 2.1);
	tablicaDouble.ustawelement(1, 3.2);
	tablicaDouble.ustawelement(2, 6.3);

	double sumaDouble = tablicaDouble.suma();
	cout << "Suma elementow tablicy double: " << sumaDouble << endl;
	*/

	//zadanie 6
	/*
	int inta = 3;
	int intb = 4;
	int intc = 5;
	int poleint = PoleProstopadloscianu(inta, intb, intc);
	cout << "PoleProstopadloscianu int : " << poleint << endl;

	double doublea = 2.2;
	double doubleb = 3.4;
	double doublec = 4.5;
	double poledouble = PoleProstopadloscianu(doublea, doubleb, doublec);
	cout << "PoleProstopadloscianu double: " << poledouble << endl;

	float floata = 1.2;
	float floatb = 2.3;
	float floatc = 4.4;
	float polefloat = PoleProstopadloscianu(floata, floatb, floatc);
	cout << "PoleProstopadloscianu float: " << polefloat << endl;
	*/

	//zadanie 7
	/*
	Prostopadloscian<int> prostopadloscianInt(3, 4, 5);
	cout << "Pole prostopadloscianu int: " << prostopadloscianInt.PoleProstopadłościanu() << endl;

	Prostopadloscian<double> prostopadloscianDouble(2.7, 3.5, 4.2);
	cout << "Pole prostopadloscianu double: " << prostopadloscianDouble.PoleProstopadłościanu() << endl;

	Prostopadloscian<float> prostopadloscianFloat(1.3, 2.5, 3.4);
	cout << "Pole prostopadloscianu float: " << prostopadloscianFloat.PoleProstopadłościanu() << endl;
	*/




	return 0;
}