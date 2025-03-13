#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
class Drzewo {
public:
	Node* korzen;

	Drzewo() { korzen = nullptr; }

	void dodaj(int wartosc) {
		korzen = wstawrekurencyjnie(korzen, wartosc);
	}

	Node* wstawrekurencyjnie(Node* korzen, int wartosc) {
		if (korzen == nullptr) {
			Node* newnode = new Node;
			newnode->data = wartosc;
			newnode->left = nullptr;
			newnode->right = nullptr;
			return newnode;
		}

		else if (wartosc < korzen->data) {
			korzen->left = wstawrekurencyjnie(korzen->left, wartosc);
		}
		else if (wartosc > korzen->data) {
			korzen->right = wstawrekurencyjnie(korzen->right, wartosc);
		}
		return korzen;
	}

	void usuwanie(int wartosc) {
		korzen = usunrekurencyjnie(korzen, wartosc);
	}

	Node* usunrekurencyjnie(Node* korzen, int wartosc) {
		if (korzen == nullptr) {
			return korzen;
		}

		if (wartosc < korzen->data) {
			korzen->left = usunrekurencyjnie(korzen->left, wartosc);
		}
		else if (wartosc > korzen->data) {
			korzen->right = usunrekurencyjnie(korzen->right, wartosc);
		}
		else {
			if (korzen->left == nullptr) {
				Node* temp = korzen->right;
				delete korzen;
				return temp;
			}
			else if (korzen->right == nullptr) {
				Node* temp = korzen->left;
				delete korzen;
				return temp;
			}

			Node* temp = mniejszyNode(korzen->right);
			korzen->data = temp->data;
			korzen->right = usunrekurencyjnie(korzen->right, temp->data);
		}

		return korzen;
	}

	Node* mniejszyNode(Node* node) {
		Node* current = node;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	bool szukaj(int value) {
		return szukajrek(korzen, value);
	}

	bool szukajrek(Node* korzen, int value) {
		if (korzen == nullptr) {
			return false;
		}
		if (korzen->data == value) {
			return true;
		}
		if (value < korzen->data) {
			return szukajrek(korzen->left, value);
		}
		else {
			return szukajrek(korzen->right, value);
		}
	}

	int wysokosc() {
		return heightRec(korzen);
	}

	int heightRec(Node* korzen) {
		if (korzen == nullptr) {
			return 0;
		}

		int leftwys = heightRec(korzen->left);
		int rightwys = heightRec(korzen->right);

		return 1 + max(leftwys, rightwys);
	}

	int rozpietosc() {
		int minDepth = INT_MAX;
		int maxDepth = INT_MIN;
		rozpietoscrek(korzen, minDepth, maxDepth, 0);
		return maxDepth - minDepth;
	}

	void rozpietoscrek(Node* korzen, int& minDepth, int& maxDepth, int depth) {
		if (korzen == nullptr) {
			return;
		}

		minDepth = min(minDepth, depth);
		maxDepth = max(maxDepth, depth);

		rozpietoscrek(korzen->left, minDepth, maxDepth, depth + 1);
		rozpietoscrek(korzen->right, minDepth, maxDepth, depth + 1);
	}
};

void printTree(Node* korzen) {
	if (korzen == nullptr) {
		return;
	}

	queue<Node*> q;
	q.push(korzen);

	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			Node* node = q.front();
			q.pop();
			cout << node->data << " ";
			//wezel ma lewe dziecko= dodajemy do kolejki
			if (node->left != nullptr) {
				q.push(node->left);
			}
			//wezel ma prawe dziecko = dodajemy do kolejki
			if (node->right != nullptr) {
				q.push(node->right);
			}
			count--; //dekrementujemy l. wezlow w biezacym poziomie.
		}
		cout << endl;
	}
}





int main() {

	Drzewo drzewko;
	drzewko.dodaj(10);
	drzewko.dodaj(20);
	drzewko.dodaj(30);
	drzewko.dodaj(40);
	drzewko.dodaj(50);
	drzewko.dodaj(60);
	drzewko.dodaj(70);
	drzewko.dodaj(80);
	drzewko.dodaj(90);
	

	cout << "Struktura drzewa:" << endl;
	printTree(drzewko.korzen);

	cout << "wysokosc drzewa: " << drzewko.wysokosc() << endl;
	cout << "rozpietosc drzewa: " << drzewko.rozpietosc() << endl;

	drzewko.usuwanie(30);
	drzewko.usuwanie(60);

	cout << "usuniete 30 i 60, stan drzewka:" << endl;
	printTree(drzewko.korzen);

	int szukajwart;
	
	cout << "jaka szukac wartosc: " << endl;
	cin >> szukajwart;
	cout << szukajwart << ": " << (drzewko.szukaj(szukajwart) ? "Jest" : "nie ma") << endl;




	return 0;
}