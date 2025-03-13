#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
class Ofiara {
public:
    string imie;
    string nazwisko;
    Ofiara* left;
    Ofiara* right;
    Ofiara(const string& imie, const string& nazwisko) : imie(imie), nazwisko(nazwisko), left(nullptr), right(nullptr) {}
};

class Notatnik {
public:
    Ofiara* korzen;
    int iloscOfiar;

    Notatnik() : korzen(nullptr), iloscOfiar(0) {}

    void dodaj(const string& imie, const std::string& nazwisko) {
        korzen = dodajRekurencyjnie(korzen, imie, nazwisko);
        iloscOfiar++;
    }

    Ofiara* dodajRekurencyjnie(Ofiara* korzen, const string& imie, const string& nazwisko) {
        if (korzen == nullptr) {
            return new Ofiara(imie, nazwisko);
        }

        int porownanieImienia = imie.compare(korzen->imie);
        int porownanieNazwiska = nazwisko.compare(korzen->nazwisko);

        if (porownanieImienia < 0 || (porownanieImienia == 0 && porownanieNazwiska < 0)) {
            korzen->left = dodajRekurencyjnie(korzen->left, imie, nazwisko);
        }
        else {
            korzen->right = dodajRekurencyjnie(korzen->right, imie, nazwisko);
        }
        return korzen;
    }

    void printTree(Ofiara* korzen) {
        if (korzen == nullptr) {
            return;
        }

        queue<Ofiara*> q;
        q.push(korzen);

        while (!q.empty()) {
            int count = q.size();
            while (count > 0) {
                Ofiara* node = q.front();
                q.pop();
                cout << node->imie << " " << node->nazwisko << " ";
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                count--;
            }
            cout << endl;
        }
    }

    bool szukajBFS(const string& imie, const string& nazwisko) {
        if (korzen == nullptr) {
            return false;
        }

        queue<Ofiara*> kolejka;
        kolejka.push(korzen);

        while (!kolejka.empty()) {
            Ofiara* ofiara = kolejka.front();
            kolejka.pop();

            if (ofiara->imie == imie && ofiara->nazwisko == nazwisko) {
                return true;
            }

            if (ofiara->left != nullptr) {
                kolejka.push(ofiara->left);
            }

            if (ofiara->right != nullptr) {
                kolejka.push(ofiara->right);
            }
        }

        return false;
    }

    bool szukajDFS(const string& imie, const string& nazwisko) {
        if (korzen == nullptr) {
            return false;
        }

        stack<Ofiara*> stos;
        stos.push(korzen);

        while (!stos.empty()) {
            Ofiara* ofiara = stos.top();
            stos.pop();

            if (ofiara->imie == imie && ofiara->nazwisko == nazwisko) {
                return true;
            }

            if (ofiara->right != nullptr) {
                stos.push(ofiara->right);
            }

            if (ofiara->left != nullptr) {
                stos.push(ofiara->left);
            }
        }

        return false;
    }

    void rotacjaLewo(Ofiara*& korzen) {
        if (korzen == nullptr || korzen->right == nullptr) {
            return;
        }

        Ofiara* nowyKorzen = korzen->right;
        korzen->right = nowyKorzen->left;
        nowyKorzen->left = korzen;
        korzen = nowyKorzen;
    }

    void rotacjaPrawo(Ofiara*& korzen) {
        if (korzen == nullptr || korzen->left == nullptr) {
            return;
        }

        Ofiara* nowyKorzen = korzen->left;
        korzen->left = nowyKorzen->right;
        nowyKorzen->right = korzen;
        korzen = nowyKorzen;
    }

    void przekształcNaPrawoskośne() {
        while (korzen != nullptr) {
            while (korzen->left != nullptr) {
                rotacjaPrawo(korzen);
            }
            korzen = korzen->right;
        }
    }


    void zrównoważDrzewo() {
        przekształcNaPrawoskośne();
        int m = iloscOfiar - 1;
        int n = pow(2, floor(log2(iloscOfiar + 1))) - 1;

        for (int i = 0; i < iloscOfiar - n; i++) {
            rotacjaLewo(korzen);
        }

        for (int i = n / 2; i > 0; i /= 2) {
            for (int j = 0; j < i; j++) {
                rotacjaLewo(korzen);
            }
        }
    }
};
};



int main() {


	cout << "Welcome to the game...\t" << "~Death note~" <<endl;
	cout << "Loading..." << endl;
	cout << "Do you want to know rules?\n" << "y(yes)\t" << "n(no)\t" << endl;
	string wybor;
	cin >> wybor;

	if (wybor == "yes" || wybor == "y") {
		cout << "RULES" << endl;
		cout << "<1>The human whose name is written in this note shall die." << endl;
		cout << "<2>This note will not take effect unless the writer has the person's face in their mind when writing his/her name. Therefore, people sharing the same name will not be affected." << endl;
		cout << "<3> If the cause of death is written within the next 40 seconds of writing the person's name, it will happen." << endl;
		cout << "<4> If the cause of death is not specified, the person will simply die of a heart attack." << endl;
		cout << "<5>After writing the cause of death, details of the death should be written in the next 6 minutes and 40 seconds. " << endl;
		
	}

	else if (wybor == "no" || wybor == "n") {
		int number;
		string imie;
		string nazwisko;
		string opcja;
		Notatnik notatnik;
		cout << "Lets begin...\t" << "Choose number:" << endl;
		cout << "<1> Add victim" << endl;
		cout << "<2> Search victim" << endl;
		cin >> number;
		switch (number) {

		case 1:
			while (true) {
				cout << "Write the victim's name:\t";
				cin >> imie;
				if (imie == "end") {
					cout << "~Death Note~" << endl;
					notatnik.printTree(notatnik.korzen);
					break;
				}
				cout << "Write the victim's surname:\t";
				cin >> nazwisko;
				notatnik.dodaj(imie, nazwisko);
			}
			cout << "Do you want to go to option 2? (yes/no)" << endl;
			cin >> opcja;
			if (opcja == "no" || opcja == "n") {
				cout << "Sayonara";
				break;
			}


		case 2:
			int wybor2;

			cout << "Choose algorithm: " << endl;
			cout << "<1> BFS" << endl;
			cout << "<2> DFS" << endl;
			cin >> wybor2;

			if (wybor2 == 1) {
				cout << "<< BFS >>" << endl;
				string szukaneImie, szukaneNazwisko;
				cout << "Enter victim's name: ";
				cin >> szukaneImie;
				cout << "Enter victim's surname: ";
				cin >> szukaneNazwisko;
				bool znaleziona = notatnik.szukajBFS(szukaneImie, szukaneNazwisko);

				if (znaleziona) {
					cout << "Victim found in the Death Note." << endl;
				}
				else {
					cout << "Victim not found in the Death Note." << endl;
				}
			}
			else if (wybor2 == 2) {
				cout << "<< DFS >>" << endl;
				string szukaneImie, szukaneNazwisko;
				cout << "Enter victim's name: ";
				cin >> szukaneImie;
				cout << "Enter victim's surname: ";
				cin >> szukaneNazwisko;
				bool znaleziona = notatnik.szukajDFS(szukaneImie, szukaneNazwisko);

				if (znaleziona) {
					cout << "Victim found in the Death Note." << endl;
				}
				else {
					cout << "Victim not found in the Death Note." << endl;
				}
			}
			else {
				cout << "Sayonara" << endl;
			}

		}
	}
	return 0;
}