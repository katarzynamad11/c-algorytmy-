#include <iostream>
#include <iomanip> // formatowanie danych: setfill/setw
#include <string>
#include <cmath>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct T_data {
	int day;
	int month;
	int year;

	void get_date(); //definicja metody pobierającej date
	void give_date(); //definicja metody wyświetlającą date
};

void T_data::get_date() { // referencja do obiektu T_data
	// T_data x;
	cout << "Enter the day:" << endl;
	cin >> day;
	cout << "Enter the month:" << endl;
	cin >> month;
	cout << "Enter the year:" << endl;
	cin >> year;
}

void T_data::give_date() {

	cout << setfill('0') << setw(2) << day << "." << setw(2) << month << "." << year << endl;

	//setfill: ustawienie znaku wypełnienia = szerokosc wyswietlanej jest mniejsza niz minimum ^2 okreslone przez setw
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class T_student{
	char initial[2];
	string last_name;
	int year;
	int group;
	
	T_data my_birth; // obiekt moje_urodziny ze struktury T_data

public:
	T_student() : initial{ "a"}, last_name("Nowak"), year(0), group(0) {}
	void data() const {
		cout << "Initial:" << initial << "\nLast name: " << last_name << "\nyear: " << year << "\ngrupa: " << group << endl;
	}
	void get_data();
	void give_data();
};

void T_student::get_data() {
	cout << "Enter initial" << endl;
	cin >> initial;
	cout << "Enter last_name" << endl;
	cin >> last_name;
	cout << "Enter year" << endl; // Zakładamy że studia nie trwają dluzej niz 6 lat
	cin >> year;
	while (year > 6) {	// rok nie moze byc wiekszy niz 6
		cout << "Wrong number. Studies do not last longer than 6 years. Enter again" << endl;
		cin >> year;
	}
	cout << "Enter group" << endl;
	cin >> group;
	while (group > 10) {	// zakladamy ze jesli uzytkownik podal wieksza grupe niz 10 to program upewnia sie 
		cout << "Are you sure you entered the correct number, type y = yes , n = no" << endl;
		string answer;
		cin >> answer;
		if (answer == "n" || answer == "no") {
			cout << "Enter correct group" << endl;
			cin >> group;
		}
		else break; // uzytkownik wybral poprawna grupe, opuszczamy petle
	}

	cout << "Date of birth" << endl;
	cout << "Enter day" << endl;
	cin >> my_birth.day;
	cout << "Enter month" << endl;
	cin >> my_birth.month;
	cout << "Enter year" << endl;
	cin >> my_birth.year;

}

void T_student::give_data() {
	cout << "Initial:" << initial << endl;
	cout << "Last name:" << last_name<< endl;
	cout << "Year:" << year << endl;
	cout << "Group:" << group << endl;
	cout << "Date of birth:" << setfill('0') << setw(2) << my_birth.day << "." << setw(2) <<  my_birth.month << "." << my_birth.year << endl;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class area_rectangle { // obliczanie pola prostokata
	double a;
	double b;
	double result;
public:
	void enter_data(); // metoda aby wpisac wartosci a i b
	void math(); // metoda do przeliczania pola prostokata
	void give_result(); // wynik dzialania
};

void area_rectangle::enter_data() {
	cout << "Enter a: " << endl;
	cin >> a;
	cout << "Enter b: " << endl;
	cin >> b;
}

void area_rectangle::math() {
	result = a * b;
}

void area_rectangle::give_result() {
	cout << "a= " << a << endl;
	cout << "b= " <<  b << endl;
	cout << "Result a * b = " << setprecision(3) << result << endl; // do 2 miejsc po przecinku
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class equation {
	float a, b, c;
	float x1, x2;
	float delta;
public:
	void entering(); // wczytamy wartości
	void mathing(); // metoda obliczająca
	void resulting(); // wypisanie wyniku
	
};

void equation::entering() {
	cout << "Enter a:" << endl;
	cin >> a;
	if (a == 0) {
		cout << "Wrong number,it cant be 0" << endl;
		exit(0);
	}
	cout << "Enter b:" << endl;
	cin >> b;
	cout << "Enter c:" << endl;
	cin >> c;
}

void equation::mathing() {
	delta = b * b - 4 * a * c;
	if (delta == 0) {
		x1 = x2 = -b / (2 * a);
	}
	else if (delta > 0) {
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
	}
	else {
		cout << "delta is negative" << endl;
	}
}



void equation::resulting() {
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
	cout << "RESULT" << endl;
	if (delta > 0) {
		cout << "x1 = " << setprecision(3) << x1 << ", x2 = " << x2 << endl;
	}
	else if (delta == 0) { 
		cout << "x = " << setprecision(3) << x1 << endl;
	}
	else { 
		cout << "Delta is negative" << endl;
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class sort {
	int* values; // wskaznik na wartosc 
	int size;
public:
	void read(); // odczytuje dane i umieszcza je w tablicy o nazwie values
	void sorting(); // sortowanie babelkowe
	void results();
};

void sort::read() {
	cout << "enter the size of the array" << endl;
	cin >> size;
	values = new int[size]; // dynamiczna tablica 
	cout << "enter the values" << endl;
	
	for (int i = 0; i < size; i++) {
		cin >> values[i];
	}
}

void sort::sorting() {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (values[j] > values[j + 1]) {
				int temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}



void sort::results() {
	cout << "sorted numbers" << endl;
	for (int i = 0; i < size; i++) {
		cout << values[i] << ' ';
	}

}


int main() {


	T_data data;
	data.get_date();
	data.give_date();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	T_student student;
	T_student student2;
	student.data();

	T_student* wsk_student = &student2;
	cout << "Basic: " << endl;
	student.give_data();
	cout << "with wsk" << endl;

	wsk_student->get_data();
	wsk_student->give_data();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	area_rectangle check;
	check.enter_data();
	check.math();
	check.give_result();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	equation sqrt;
	sqrt.entering();
	sqrt.mathing();
	sqrt.resulting();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	sort sort1;
	sort1.read();
	sort1.sorting();
	sort1.results();




	return 0;
}