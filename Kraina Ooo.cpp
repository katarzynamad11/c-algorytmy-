#include <iostream>
#include <string>

using namespace std;

struct Postac {
    string imie;
    bool czyBohater;  // true dla bohatera, false dla przeciwnika

    Postac(const string& imie, bool czyBohater) : imie(imie), czyBohater(czyBohater) {}
};

class Przygoda {

    struct ElementListy {
        Postac postac;
        ElementListy* next;

        ElementListy(const Postac& postac) : postac(postac), next(nullptr) {}
    };

    ElementListy* headBohater;
    ElementListy* tailBohater;
    ElementListy* headPrzeciwnik;
    ElementListy* tailPrzeciwnik;

public:
    Przygoda() : headBohater(nullptr), tailBohater(nullptr), headPrzeciwnik(nullptr), tailPrzeciwnik(nullptr) {}

    void el_listaBohaterow(const string& imie) {
        Postac bohater(imie, true);
        ElementListy* nowyElement = new ElementListy(bohater);

        if (!headBohater) {
            headBohater = tailBohater = nowyElement;
        }
        else {
            tailBohater->next = nowyElement;
            tailBohater = nowyElement;
        }
    }

    void el_listaPrzeciwnikow(const string& imie) {
        Postac przeciwnik(imie, false);
        ElementListy* nowyElement = new ElementListy(przeciwnik);

        if (!headPrzeciwnik) {
            headPrzeciwnik = tailPrzeciwnik = nowyElement;
        }
        else {
            tailPrzeciwnik->next = nowyElement;
            tailPrzeciwnik = nowyElement;
        }
    }

    void polaczListy() {
        if (headBohater) {
            tailBohater->next = headPrzeciwnik;
            headPrzeciwnik = tailPrzeciwnik = nullptr;
        }
    }

    void wyswietlListeBohaterowPrzedScaleniem() {
        ElementListy* obecny = headBohater;
        cout << "lista bohaterow przed scaleniem:" << endl;
        while (obecny) {
            if (obecny->postac.czyBohater) {
                cout << "bohater: " << obecny->postac.imie << endl;
            }
            obecny = obecny->next;
        }
    }

    void wyswietlListePrzeciwnikowPrzedScaleniem() {
        ElementListy* obecny = headPrzeciwnik;
        cout << "lista przeciwnikow przed scaleniem:" << endl;
        while (obecny) {
            if (!obecny->postac.czyBohater) {
                cout << "przeciwnik: " << obecny->postac.imie << endl;
            }
            obecny = obecny->next;
        }
    }

    void wyswietlListePoScaleniu() {
        ElementListy* obecny = headBohater;
        cout << "lista po scaleniu:" << endl;
        while (obecny) {
            if (obecny->postac.czyBohater) {
                cout << "bohater: " << obecny->postac.imie << endl;
            }
            else {
                cout << "przeciwnik: " << obecny->postac.imie << endl;
            }
            obecny = obecny->next;
        }
    }
};

int main() {
    Przygoda przygodzie;

    przygodzie.el_listaBohaterow("Bohater1");
    przygodzie.el_listaPrzeciwnikow("Przeciwnik1");
    przygodzie.el_listaBohaterow("Bohater2");
    przygodzie.el_listaPrzeciwnikow("Przeciwnik2");

    cout << "---------------------------------------------------" << endl;
    przygodzie.wyswietlListeBohaterowPrzedScaleniem();
    przygodzie.wyswietlListePrzeciwnikowPrzedScaleniem();

    przygodzie.polaczListy();

    cout << "---------------------------------------------------" << endl;
    przygodzie.wyswietlListePoScaleniu();

    return 0;
}
