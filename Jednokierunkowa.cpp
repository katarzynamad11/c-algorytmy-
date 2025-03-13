#include <iostream>
using namespace std;

class Node {
public:
    int wartosc;
    Node* nastepny;

    Node(int value) : wartosc(value), nastepny(nullptr) {}
};

class Lista {
public:
    Node* glowa;

    Lista() : glowa(nullptr) {}

    void dodaj(int wartosc) {
        Node* nowyElement = new Node(wartosc);
        nowyElement->nastepny = glowa;
        glowa = nowyElement;
    }

    int policzWielokrotnosciPierwszego() {
        if (glowa == nullptr) {
            return 0;
        }

        int wartoscPierwszego = glowa->wartosc;
        int licznik = 0;

        Node* obecny = glowa->nastepny;

        while (obecny != nullptr) {
            if (obecny->wartosc % wartoscPierwszego == 0) {
                licznik++;
            }
            obecny = obecny->nastepny;
        }

        return licznik;
    }

    void wyswietlListe() {
        Node* obecny = glowa;
        while (obecny != nullptr) {
            cout << obecny->wartosc << " ";
            obecny = obecny->nastepny;
        }
       cout << endl;
    }

    ~Lista() {
        while (glowa != nullptr) {
            Node* temp = glowa;
            glowa = glowa->nastepny;
            delete temp;
        }
    }
};

int main() {
    Lista lista;
    lista.dodaj(3);
    lista.dodaj(6);
    lista.dodaj(9);
    lista.dodaj(12);
    lista.dodaj(15);
    lista.dodaj(3);

    lista.wyswietlListe();

    int wynik = lista.policzWielokrotnosciPierwszego();
    cout << "liczba elementow bedacych wielokrotnosciami pierwsze elementu: " << wynik << endl;

    return 0;
}