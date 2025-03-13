#include <iostream>
using namespace std;


//z przechowywaniem danych w tablicy:
/*
class List {

	int wielkosc = 10;
	int* tab;
	int rozmiar;
	int teraz_rozmiar;

public:
	List() {
		rozmiar = wielkosc;
		tab = new int[rozmiar];
		teraz_rozmiar = 0;
	}

	~List() {
		delete[] tab;
	}

	
	void add(int element) {
		if (teraz_rozmiar >= rozmiar) {
			int nowy_rozmiar = rozmiar * 2;
			int* nowa_tablica = new int[nowy_rozmiar];

			for (int i = 0; i < teraz_rozmiar; i++) {
				nowa_tablica[i] = tab[i];
			}
			delete[] tab;
			tab = nowa_tablica;
			rozmiar = nowy_rozmiar;
		}
		tab[teraz_rozmiar] = element;
		teraz_rozmiar++;

	}

	void remove() {
		if (teraz_rozmiar > 0) {
			teraz_rozmiar--;
		} 
		else {
			cout << "lista jest pusta";
		}
	}

	bool is_empty() {
		return teraz_rozmiar == 0;
	}

	int size() {
		return teraz_rozmiar;
	}

};
*/

//z przechowywaniem danych w postaci dynamicznie alokowanych obiektow:
class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};
class List {

	Node* head;
	int current_size;

public:
	List() : head(nullptr), current_size(0) {}

	~List() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void add(int element) {
		Node* newNode = new Node(element);
		newNode->next = head;
		head = newNode;
		current_size++;
	}

	void remove() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
			current_size--;
		}
		else {
			cout << "lista jest pusta";
		}
	}

	bool is_empty() {
		return current_size == 0;
	}

	int size() {
		return current_size;
	}
};





int main() {

	List lista;
	lista.add(1);
	lista.add(2);
	lista.add(1);
	lista.add(2);
	lista.add(1);
	lista.add(2); 

	cout << "czy lista jest pusta " << (lista.is_empty() ? "tak" : "nie") << endl;
	cout << "rozmiar listy: " << lista.size() << endl;
	

	return 0;
}