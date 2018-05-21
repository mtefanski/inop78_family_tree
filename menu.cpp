#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <Windows.h>

#include "Tree.h"

using namespace std;
Tree tree;
char hsTab[2] = { '<',' ' };
char menuTab[6] = { '<',' ',' ',' ',' ',' ' };
char relTab[13] = { '<',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };

void startScreen() {
	cout << "Stworz drzewo  " << hsTab[0] << endl;
	cout << "Wczytaj drzewo " << hsTab[1] << endl;
}

void printMenu() {
	cout << "Dodaj czlonka rodziny    " << menuTab[0] << endl;
	cout << "Wyszukaj czlonka rodziny " << menuTab[1] << endl;
	cout << "Edytuj czlonka rodziny   " << menuTab[2] << endl;
	cout << "Usun czlonka rodziny     " << menuTab[3] << endl;
	cout << "Wyswietl drzewo          " << menuTab[4] << endl;
	cout << "Eksportuj drzewo         " << menuTab[5] << endl;
	cout << endl << "ESC aby wyjsc";
}

void formUser() {
	string imie, nazwisko, data;
	string rodowe = " ";
	bool gender;
	char rod, plec;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy Twoje nazwisko rodowe jest rozne od obecnego? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	cout << "Wprowadz date urodzenia (DD-MM-RRRR): ";
	cin >> data;
	cout << "Wprowadz plec (k/m): ";
	cin >> plec;

	if (plec == 'k')
		gender = 0;
	else gender = 1;

	tree.addUser(Person(imie, nazwisko, rodowe, Date(data), gender));
}

void form(int rel, bool gender) {
	string imie, nazwisko, data;
	string rodowe = " ";
	char rod;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy nazwisko rodowe jest rozne od obecnego? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	cout << "Wprowadz date urodznia (DD-MM-RRRR): ";
	cin >> data;
	tree.addPerson(Person(imie,nazwisko,rodowe,Date(data),gender), rel);
}

void otherForm(int map, string rel) {
	string imie, nazwisko, data;
	string rodowe = " ";
	char rod, plec;
	bool gender;
	cout << "Wprowadz imie: ";
	cin >> imie;
	cout << "Wprowadz nazwisko: ";
	cin >> nazwisko;
	cout << "Czy nazwisko rodowe jest rozne od obecnego? (t/n): ";
	cin >> rod;
	if (rod == 't') {
		cout << "Wprowadz nazwisko rodowe: ";
		cin >> rodowe;
	}
	cout << "Wprowadz date urodznia (DD-MM-RRRR): ";
	cin >> data;
	cout << "Wprowadz plec (k/m): ";
	cin >> plec;

	if (plec == 'k')
		gender = 0;
	else gender = 1;

	tree.addPerson(Person(imie, nazwisko, rodowe, Date(data), gender, rel), map);
}

void relation() {
	cout << "matka   " << relTab[0] << endl;
	cout << "ojciec  " << relTab[1] << endl;
	cout << "siostra " << relTab[2] << endl;
	cout << "brat    " << relTab[3] << endl;
	cout << "zona    " << relTab[4] << endl;
	cout << "maz     " << relTab[5] << endl;
	cout << "corka   " << relTab[6] << endl;
	cout << "syn     " << relTab[7] << endl;
	cout << "babcia  " << relTab[8] << endl;
	cout << "dziadek " << relTab[9] << endl;
	cout << "wnuczka " << relTab[10] << endl;
	cout << "wnuk    " << relTab[11] << endl;
	cout << "inny    " << relTab[12] << endl;
}


void moveDown(char tab[], int i) {
	tab[i] = ' ';
	tab[i + 1] = '<';
}

void moveUP(char tab[], int i) {
	tab[i] = ' ';
	tab[i - 1] = '<';
}

void menu(int &i, char &x) {
	system("cls");
	i = 0;
	printMenu();
	do {
		x = _getch();
		switch (x) {
		case 72: //up
			if (i > 0) {
				moveUP(menuTab, i);
				system("cls");
				printMenu();
				i--;
			}
			break;
		case 80: //down
			if (i < 5) {
				moveDown(menuTab, i);
				system("cls");
				printMenu();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0) { //dodaj czlonka rodziny
				system("cls");
				i = 0;
				relation();
				do {
					x = _getch();
					switch (x) {
					case 72: //up
						if (i > 0) {
							moveUP(relTab, i);
							system("cls");
							relation();
							i--;
						}
						break;
					case 80: //down
						if (i < 12) {
							moveDown(relTab, i);
							system("cls");
							relation();
							i++;
						}
						break;
					case 13: //enter
						if (i == 0) {		//matka
							system("cls");
							form(-1, 0);
						}		
						if (i == 1) {		//ojciec
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-1, 1);
						}		
						if (i == 2) {		//siostra
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(3, 0);
						}		
						if (i == 3) {		//brat
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(3, 1);
						}		
						if (i == 4) {		//zona
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(1, 0);
						}		
						if (i == 5) {		//maz
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(1, 1);
						}		
						if (i == 6) {		//corka
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(2, 0);
						}		
						if (i == 7) {		//syn
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(2, 1);
						}		
						if (i == 8) {		//babcia
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-2, 0);
						}		
						if (i == 9) {		//dziadek
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(-2, 1);
						}
						if (i == 10) {		//wnuczka
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(4, 0);
						}
						if (i == 11) {		//wnuk
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							form(4, 1);
						}
						if (i == 12) {		//inny
							relTab[i] = ' ';
							relTab[0] = '<';
							system("cls");
							cout << "Da kogo z Twojej rodziny ta osoba jest w blizszej relacji?" << endl;
							string firstName, lastName;
							cout << "Podaj imie: ";
							cin >> firstName;
							cout << "Podaj nazwisko: ";
							cin >> lastName;
							system("cls");
							Pointer seek = tree.Find(firstName, lastName);
							if (seek.map == 404)
								cout << "Nie znaleziono" << endl;
							else {
								cout << endl << "Kim ta osoba jest dla Ciebie?: ";
								string rel;
								cin >> rel;
								system("cls");
								otherForm(seek.map, rel);
							}
						}
						system("cls");
						i = 0;
						x = 25;
						break;
					default:
						break;
					}
				} while (x != 25);
				system("cls");
				printMenu();
			}
			if (i == 1) {								//wyszukaj czlonka rodziny
				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				if (tree.Find(firstName, lastName).map == 404)
					cout << "Nie znaleziono" << endl;
				cout << endl << "Strzaˆka w gore aby wrocic";
			}
			if (i == 2) {								//edytuj czlonka rodziny
				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				Pointer seek = tree.Find(firstName, lastName);
				if (seek.map == 404)
					cout << "Nie znaleziono" << endl;
				else {
					cout << endl << "Czy na pewno chcesz edytowac tego czlonka rodziny? (t/n) ";
					char dec;
					cin >> dec;
					if (dec = 't') {

						string imie, nazwisko, data;
						string rodowe = " ";
						bool gender;
						char rod, plec;
						cout << "Wprowadz imie: ";
						cin >> imie;
						cout << "Wprowadz nazwisko: ";
						cin >> nazwisko;
						cout << "Czy nazwisko rodowe jest rozne od obecnego? (t/n): ";
						cin >> rod;
						if (rod == 't') {
							cout << "Wprowadz nazwisko rodowe: ";
							cin >> rodowe;
						}
						cout << "Wprowadz date urodznia (DD-MM-RRRR): ";
						cin >> data;

						cout << "Wprowadz plec (k/m): ";
						cin >> plec;

						if (plec == 'k')
							gender = 0;
						else gender = 1;


						tree.Edit(seek.map,seek.vector,Person(imie, nazwisko, rodowe, Date(data), gender));

					}
				}
				cout << endl << "Strzaˆka w gore aby wrocic";
			}
			if (i == 3) {								//usun czlonka rodziny
			
				system("cls");
				string firstName, lastName;
				cout << "Podaj imie: ";
				cin >> firstName;
				cout << "Podaj nazwisko: ";
				cin >> lastName;
				system("cls");
				Pointer seek = tree.Find(firstName, lastName);
				if (seek.map == 404)
					cout << "Nie znaleziono" << endl;
				else {
					cout << endl << "Czy na pewno chcesz usunac? (t/n) ";
					char dec;
					cin >> dec;
					if (dec = 't')
						tree.Delete(seek.map, seek.vector);
				}
				cout << endl << "Strzaˆka w gore aby wrocic";

			}
			if (i == 4) {//wyswietl drzewo
			system("cls");
			tree.printTree();
			cout << endl << "Strzaˆka w gore aby wrocic";
			}

			if (i == 5) {//eksportuj drzewo
				system("cls");
				cout << "Podaj nazwe pliku: ";
				string filename;
				cin >> filename;
				tree.Export(filename);
				cout << "Drzewo wyeksportowano";
				cout << endl << "Strzaˆka w gore aby wrocic";
			}
			break;
		default:
			break;
		}
	} while (x != 27);
}

int main() {
	char x;
	int i = 0;

	startScreen();
	do {
		x = _getch();
		switch (x) {
		case 72: //up
			if (i > 0) {
				moveUP(hsTab, i);
				system("cls");
				startScreen();
				i--;
			}
			break;
		case 80: //down
			if (i < 1) {
				moveDown(hsTab, i);
				system("cls");
				startScreen();
				i++;
			}
			break;
		case 13: //enter
			if (i == 0) {//stworz drzewo
				system("cls");
				formUser();
				menu(i, x);
			}
			if (i == 1) {//wczytaj drzewo
				system("cls");
				string filename;
				cout << "Wprowadz nazwe pliku: ";
				cin >> filename;
				if (tree.Import(filename))
					menu(i, x);
				else {
					system("cls");
					startScreen();

					cout << endl << "Blad wczytania pliku, sprobuj ponownie";
				}
			}
			break;
		default:
			break;
		}
	} while (x != 27);
	return 0;
}