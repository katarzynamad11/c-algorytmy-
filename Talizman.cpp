#include <iostream>
#include <string>
using namespace std;

const int MAX_GRACZA = 100; 


class Gracz {
public:
    int liczbaTowarzyszy;
   string towarzysze[MAX_GRACZA];
};


void usunTowarzysza(Gracz& gracz, int pozycja) {
    if (pozycja < 0 || pozycja >= gracz.liczbaTowarzyszy) {
        cout << "nieprawidlowwa pozycja " << endl;
        return;
    }

    for (int i = pozycja; i < gracz.liczbaTowarzyszy - 1; i++) {
        gracz.towarzysze[i] = gracz.towarzysze[i + 1];
    }

    gracz.liczbaTowarzyszy--;

    cout << "usunieto towarzysza z pozycji " << pozycja << endl;
}

int main() {
    Gracz gracz;
    gracz.liczbaTowarzyszy = 5;

    gracz.towarzysze[0] = "Towarzysz1";
    gracz.towarzysze[1] = "Towarzysz2";
    gracz.towarzysze[2] = "Towarzysz3";
    gracz.towarzysze[3] = "Towarzysz4";
    gracz.towarzysze[4] = "Towarzysz5";

    cout << "Lista towarzyszy gracza:" << endl;
    for (int i = 0; i < gracz.liczbaTowarzyszy; i++) {
        cout << i << ": " << gracz.towarzysze[i] << endl;
    }

    int pozycjaDoUsuniecia = 3; 
    usunTowarzysza(gracz, pozycjaDoUsuniecia);

    cout << "zaktualizowana lista towarzyszy gracza:" << endl;
    for (int i = 0; i < gracz.liczbaTowarzyszy; i++) {
        cout << i << ": " << gracz.towarzysze[i] << endl;
    }

    return 0;
}




