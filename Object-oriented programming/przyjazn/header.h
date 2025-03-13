#include <iostream>
#include <string>
	
using namespace std;

//zadanie 1
/*
class TSamochod;
class TSilnik {
private:
	int moc;
	int max_moment_obr;
public:
	TSilnik(int moc, int max_moment_obr);
	friend class TSamochod;
};

class TSamochod {
private:
	TSilnik silnik;
	string model;
public:

	TSamochod(string model, int moc, int moment);

	void wypisz();
	
};
*/
/*
class TKlasa;

void f_Zaprzyjaźniona(TKlasa& obj, int wartosc);

class TZaprzyjaźniona_Klasa {
public:
	void zmienTKlasa(TKlasa& obj, int wartosc);
};

class TKlasa {
private:
	int x;
	friend void f_Zaprzyjaźniona(TKlasa& obj, int wartosc);
	friend class TZaprzyjaźniona_Klasa;
public:
	TKlasa(int wartosc) : x(wartosc) {}
};

*/

//zadanie 3 
/*
struct Srodek {
	float x;
	float y;
};

class TOkrag {
private:
	float promien;
	Srodek srodek;
public:
	TOkrag(float r, float x, float y);
	friend bool PrzecinajaSie(TOkrag& k1, TOkrag& k2);
};
*/

//zadanie dodatkowe

class telewizor {
	public:
    enum tryb { Off, On, MinVal = 20, MaxVal, Antena, Kabel, TV, DVD };

   
	telewizor(tryb mode = Kabel, int maxChannels = 125);
    void OnOff();
    bool VolUp();
    bool VolDown();
    void ChanUp();
    void ChanDown();
    void SetMode(tryb mode);
    void SetInput(tryb input);
    void SetChannel(int channel);
    void drukuj();

private:
    tryb mode_;
    int maxChannels_;
    int currentChannel_;
    int volume_;
    tryb input_;
    tryb state_;
};



