#include <iostream>
#include <string>
#include <vector>
using namespace std;

//zadanie 1 
/*
class Figura
{
protected:
	int wysokosc;
	int szerokosc;
public :
	void Ustaw_wartosc(int h, int sz) {
		wysokosc = h;
		szerokosc = sz;
	}
};

class Prostokat : public Figura {
public:
	inline int zwrocwysokosc() { return wysokosc; }
	inline int zwrocszerokosc() { return szerokosc; }
	inline int pole1() { return wysokosc * szerokosc; }
};

class Trojkat : public Figura {
public:
	inline int zwrocwysokosc() { return wysokosc; }
	inline int zwrocszerokosc() { return szerokosc; }
	inline int pole2() { return (wysokosc * szerokosc)/2 ; }
	
};
*/

//zadanie 2
/*
class A {
public:
	void wyswietl() {
		cout << "KLASA A" << endl;
	}
};

class B {
public:
	void wyswietl() {
		cout << "KLASA B" << endl;
	}
};

class C {
public:
	void wyswietl() {
		cout << "KLASA C" << endl;
	}
};

class Z : public A , public B , public C {
public:
	void wyswietlABC() {
		A::wyswietl();
		B::wyswietl();
		C::wyswietl();
	}
};
*/

//zadanie 3
/*
const float PI = 3.14159265358;

class Punkt {
protected:
	float x, y;
	string nazwa;

	void Wyswietl() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	Punkt(float x = 0, float y = 0, string nazwa = "S") : x(x), y(y), nazwa(nazwa) {}
};

class Kolo : public Punkt {

	float promien;
	string nazwa_kola;
public:
	

	void Wyswietl() {
		cout << "Nazwa kola: " << nazwa_kola << endl;
		cout << "Srodek kola: ";
		Punkt::Wyswietl();
		cout << "Promien kola: " << promien << endl;
		cout << "Pole kola: " << PI * pow(promien, 2) << endl;
	}
	Kolo(string nazwa_kola = "kolo0", string nazwa_punktu = "S", float x = 0, float y = 0, float promien = 1)
		: Punkt(x, y, nazwa_punktu), promien(promien), nazwa_kola(nazwa_kola) {}
	
};

*/

//zadanie 4
/*
class Zwierze {
public:
	int wiek;
	int ilosc_nog;
};

class Zwierze_domowe : public Zwierze {
public:
	string imie;
	string kolor_siersci;

};

class Hipopotam : public Zwierze {
public:
	void wyswietl() {
		cout << "HIP HIP" << endl;
	}
};

class Kot : public Zwierze_domowe {
public:
	void wyswietl1(){
		cout << " KOTEK ROBI MIAU " << endl;
	}
};


class Pies : public Zwierze_domowe {
public:
	void wyswietl2(){
		cout << " PIESEK ROBI HAU" << endl;
	}

};
*/

//zadanie 5
/*
class Osoba {
	string imie, nazwisko, ulica;
public :
	void wczytaj_dane() {
		cout << "podaj imie: ";
		cin >> imie;
		cout << "podaj nazwisko: ";
		cin >> nazwisko;
		cout << "podaj ulice: ";
		cin >> ulica;
	}
	void wyswietl_dane() {
		cout << "imie: " << imie << endl;
		cout << "nazwisko: " << nazwisko << endl;
		cout << "ulica: " << ulica << endl;
	}
};

class Kadra : public Osoba {
protected:
	string wyksztalcenie;
public:
	void wczytaj_dane_1() {
		wczytaj_dane();
		cout << "podaj wyksztalcenie: ";
		cin >> wyksztalcenie;
	}
	void wyswietl_dane_1() {
		wyswietl_dane();
		cout << "wyksztalcenie: " << wyksztalcenie << endl;
	}
};
*/

// zadanie 6
class Question {
	string text, answer;
public:
	Question() : text(""), answer("") {}

	void set_text(string question_text) {
		text = question_text;
	}

	void set_answer(string correct_response) {
		answer = correct_response;
	}

	bool check_answer(string response) const {
		return response == answer;
	}

	void display() const {
		cout << text << endl;
	}

};

class Choise_question : public Question {

};

int main() {
	//zadanie1
	/*
	Prostokat prostokat;
	Trojkat trojkat;
	
	prostokat.Ustaw_wartosc(2, 3);
	trojkat.Ustaw_wartosc(3, 4);

cout << "Wymiary prostokata: " << prostokat.zwrocwysokosc() << "x" << prostokat.zwrocszerokosc() <<  endl;
cout << "pole prostokata: " << prostokat.pole1() << endl;
cout << "Wymiary trojkata: " << trojkat.zwrocwysokosc() << "x" << trojkat.zwrocszerokosc() << endl;
cout << "pole trojkata: " << trojkat.pole2() << endl;
*/

	//zadanie 2
/*
	Z w;
	w.wyswietlABC();
	*/

	//zadanie 3
	/*
	Kolo kolo("kolo2", "a", 1, 2, 3);
	kolo.Wyswietl();
	*/

	//zadanie 4
	/*
	Hipopotam h;
	h.wiek = 5;
	h.ilosc_nog = 4;
	cout << "wiek: " << h.wiek << " ilosc nog" << h.ilosc_nog << endl;
	h.wyswietl();
	Kot k;
	k.wiek = 2;
	k.ilosc_nog = 4;
	k.imie = "Krecik"; 
	k.kolor_siersci = "czarny";
	cout << "wiek: " << k.wiek << " ilosc nog" << k.ilosc_nog << " imie " << k.imie << "kolor siersci " << k.kolor_siersci << endl;
	k.wyswietl1();
	Pies p;
	p.wiek = 3;
	p.ilosc_nog = 4;
	p.imie = "Fretka";
	p.kolor_siersci = "Brazowy";
	cout << "wiek: " << p.wiek << " ilosc nog" << p.ilosc_nog << endl;
		cout << " imie " << p.imie <<" kolor siersci " << p.kolor_siersci << endl;
	p.wyswietl2();
	*/
	
	//zadanie 5
	/*
	Kadra k;
	k.wczytaj_dane_1();
	k.wyswietl_dane_1();
	*/

	// zadanie 6

	Question o;
	string user_answer;
	o.set_text("Jaka jest stolica Francji");
	o.set_answer("Paryz");

	o.display();

	cout << "twoja odpowiedz: " << endl;
	cin >> user_answer;

	if (o.check_answer(user_answer)) {
		cout << "prawda" << endl;
	}
	else {
		cout << "nieprawda" << endl;
	}



	return 0;
}