#include <iostream>

using namespace std;
//ZADANIE 1	
/*
class kasa_fiskalna {
	int ilosc_sztuk;
	float cena;

public:
	kasa_fiskalna() {
		ilosc_sztuk = 0;
		cena = 0.0;
	}

	void zeruj_kase(){
		ilosc_sztuk = 0;
	cena = 0.0;
	}
	void dodaj_produkt(int ilosc, float cena_calosc) {
		ilosc_sztuk += ilosc;
		cena = cena_calosc;
	}
	float wartosc() {
		return ilosc_sztuk * cena;
	}
	int licz_produktow() {
		return ilosc_sztuk;
	}
	void wypisz() {
		cout << "liczba produktow: " << ilosc_sztuk << endl;
			cout << "cena: " << wartosc() << endl;
	}





};

*/

//ZADANIE 2
/*
class konto_bankowe {
private:
	double saldo;
public:
	konto_bankowe() {
		saldo = 0;
	}
	konto_bankowe(double poczatkowa) {
		saldo = poczatkowa;
	}
	void depozyt(double kwota) {
		saldo += kwota;
	}
	void wyplata(double kwota) {
		saldo -= kwota;
	}
	double pobierz_saldo() {
		return saldo;
	}
};

*/
/*
class przedmiot {
private:
	string nazwa;
	double cena=0.0;
public:
	przedmiot() : cena(0) {}
	przedmiot(string nazwa) : nazwa(nazwa), cena(0) {}
	przedmiot(string nazwa, double cena) : nazwa(nazwa), cena(cena) {}
	void drukuj() {
		cout << "Nazwa: " << nazwa << " cena: " << cena << endl;
	}
	};
	*/
/*
class TOsoba {
	string imie;
	int wiek;
	//zadanie 5
	int wzrost;

public :
	TOsoba() : imie(""), wiek(0), wzrost(0) {}
	TOsoba(const string& i, int w, int h) : imie(i), wiek(w), wzrost(h) {}
	TOsoba(const TOsoba& osoba) : imie(osoba.imie), wiek(osoba.wiek), wzrost(osoba.wzrost) {}
	void wypisz() const;
};

void TOsoba::wypisz() const {
	cout << "imie: " << imie << endl << "wiek: " << wiek << endl << "wzrost: " << wzrost << endl;

}
*/

//ZADANIE 6
class TSilnik {
	public:
	int moc;
	int max_moment_obr;
	TSilnik(int moc, int moment) : moc(moc), max_moment_obr(moment) {}
};

class TSamochod {
public:
	TSilnik silnik;
	string model;
	TSamochod(const string& model, int moc, int moment): silnik(moc, moment), model(model) {}

	void wypisz() {
		cout << "model: " << model << endl;
		cout << "moc: " << silnik.moc << endl;
		cout << "max moment obrotowy: " << silnik.max_moment_obr << endl;
	}
};


int main() {
	//ZADANIE 1	 
	/*
	kasa_fiskalna kasa;

	kasa.dodaj_produkt(3, 2.1);
	kasa.dodaj_produkt(5, 23.1);
	kasa.dodaj_produkt(2, 2.24);

	kasa.wypisz();

	float wartosc = kasa.wartosc();
	int produkty = kasa.licz_produktow();
	cout << "wartosc: " << wartosc << endl;
	cout << "liczba produktow: " << produkty << endl;
	cout << "zerowanie kasy=stan kasy:" << endl;
	kasa.zeruj_kase();
	kasa.wypisz();
	*/


//ZADANIE2
	/*
	konto_bankowe konto1;
	konto_bankowe konto2(100);

	konto1.depozyt(50);
	konto2.wyplata(20);

	cout << "Saldo konto1: " << konto1.pobierz_saldo() << endl;
	cout << "Saldo konto2: " << konto2.pobierz_saldo() << endl;
	*/
	/*
	przedmiot przedmiot1;
	przedmiot1.drukuj();

	przedmiot przedmiot2("pilka");
	przedmiot2.drukuj();

	przedmiot przedmiot3("groszek", 5.02);
	przedmiot3.drukuj();

	*/
	//ZADANIE 4 / 5

/*
	TOsoba obiekt1("Marek", 15,160);
	TOsoba obiekt2 = obiekt1;

	obiekt1.wypisz();
	obiekt2.wypisz();

	*/
	TSamochod* samochod = new TSamochod("fiat", 200, 230);
	samochod->wypisz();

	delete samochod;

	return 0;
}