#include <iostream>

#include <math.h>
using namespace std;

// zadanie 1
/*
class Rodzic {
public:
    virtual void Metoda() {
        cout << "jestem z klasy Rodzic" << endl;
    }
};

class Potomek : public Rodzic {
public:
    void Metoda() override {
        cout << "jestem z klasy Potomek" << endl;
    }
};
*/

//zadanie 2
/*
const double PI = 3.14159265358979323846;
//  Skorzystaj z bibliotecznej zmiennej PI - nie chcialo zadzialac
class Bryla {
public:
    virtual double PolePowierzchni() = 0;
    virtual double Objętość() = 0;
};

class Kula : public Bryla {
private:
    double promień;
public:
    Kula(double r) : promień(r) {}
    double PolePowierzchni() {
        return 4 * PI * pow(promień, 2);
    }
    double Objętość() {
        return (4.0 / 3.0) * PI * pow(promień, 3);
    }
};

class Prostopadłościan : public Bryla {
private:
    double a, b, h;
public:
    Prostopadłościan(double aa, double bb, double hh) : a(aa), b(bb), h(hh) {}
    double PolePowierzchni() {
        return 2 * (a * b + a * h + b * h);
    }
    double Objętość() {
        return a * b * h;
    }
};
*/

//zadanie 3
/*
class Kształt {
public:
    virtual void ObliczPole() = 0;
};

class Koło : public Kształt {
private:
    float promień;
public:
    Koło(float r) : promień(r) {}
    void ObliczPole() override {
        cout << "Pole kola: " << 3.14f * promień * promień << endl;
    }
};

class Kwadrat : public Kształt {
private:
    float a;
public:
    Kwadrat(float bok) : a(bok) {}
    void ObliczPole() override {
        cout << "Pole kwadratu: " << a * a << endl;
    }
};
*/

int main() {

    //zadanie 1 
    /*
    Rodzic rodzic;
    Potomek potomek;

    cout << "wywolanie z obiektu klasy Rodzic:" << endl;
    rodzic.Metoda();

    cout << "wywolanie z obiektu klasy Potomek:" << endl;
    potomek.Metoda();

    Rodzic* wskaznik = &potomek;
    cout << "wywolanie z wskaznika na klase Rodzic:" << endl;
    wskaznik->Metoda();
    */

    //zadanie2
    /*
    Kula k1(3.5);
    Kula k2(6.0);

    cout << "Pole powierzchni kuli k1: " << k1.PolePowierzchni() <<endl;
    cout << "Objetosc kuli k1: " << k1.Objętość() <<endl;

   cout << "Pole powierzchni kuli k2: " << k2.PolePowierzchni() << endl;
   cout << "Objetosc kuli k2: " << k2.Objętość() << endl;

    Prostopadłościan p1(2.0, 3.0, 4.0);
    Prostopadłościan p2(5.0, 4.0, 3.0);

    cout << "Pole powierzchni prostopadloscianu p1: " << p1.PolePowierzchni() << endl;
    cout << "Objetosc prostopadloscianu p1: " << p1.Objętość() << endl;

    cout << "Pole powierzchni prostopadloscianu p2: " << p2.PolePowierzchni() << endl;
    cout << "Objetosc prostopadloscianu p2: " << p2.Objętość() << endl;
    */

    //zadanie 3
    /*
    Kształt* wsk;
    Koło kolo(1.5f);
    Kwadrat kwadrat(3.0f);

    wsk = &kolo;
    wsk->ObliczPole();

    wsk = &kwadrat;
    wsk->ObliczPole();
    */

    


	return 0;
}