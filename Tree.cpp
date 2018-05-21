#include "Tree.h"

void Tree::addUser(const Person& _person) {
	_tree[0].push_back(_person);
}

void Tree::addGrandParent(const Person&person) {
	_tree[-2].push_back(person);
}

void Tree::addParent(const Person&person) {
	_tree[-1].push_back(person);
}

void Tree::addSibling(const Person& person) {
	_tree[3].push_back(person);
}

void Tree::addPartner(const Person& person) {
	_tree[1].push_back(person);
}

void Tree::addChild(const Person& person) {
	_tree[2].push_back(person);
}

void Tree::addGrandChild(const Person& person) {
	_tree[4].push_back(person);
}

void Tree::addPerson(const Person& person, int rel) {
	_tree[rel].push_back(person);
}

void Tree::printTree()
{
	
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		for (Person person : _tree[it->first]) {
			if (it->first == 0)
				cout << "ja-> " << person << endl;
			else if (it->first == 3) {
				if (person._gender == 0 && person._relationship==" ")
					cout << "siostra " << person << endl;
				else if(person._gender == 1 && person._relationship == " ")
					cout << "brat " << person << endl;
				else if (person._relationship != " ")
					cout << person._relationship << " " << person << endl;
			}
			else if (it->first == 1) {
				if (person._gender == 0)
					cout << "zona " << person << endl;
				else
					cout << "maz " << person << endl;
			}
			else if (it->first == 2) {
				if (person._gender == 0 && person._relationship == " ")
					cout << "corka " << person << endl;
				else if(person._gender == 1 && person._relationship == " ")
					cout << "syn " << person << endl;
				else if (person._relationship != " ")
					cout << person._relationship << " " << person << endl;
			}
			else if (it->first == -1) {
				if (person._gender == 0 && person._relationship == " ")
					cout << "matka " << person << endl;
				else if(person._gender == 1 && person._relationship == " ")
					cout << "ojciec " << person << endl;
				else if (person._relationship != " ")
					cout << person._relationship << " " << person << endl;
			}
			else if (it->first == -2) {
				if (person._gender == 0 && person._relationship == " ")
					cout << "babcia " << person << endl;
				else if (person._gender == 1 && person._relationship == " ")
					cout << "dziadek " << person << endl;
				else if (person._relationship != " ")
					cout << person._relationship << " " << person << endl;
			}
			else if (it->first == 4) {
				if (person._gender == 0)
					cout << "wnuczka " << person << endl;
				else
					cout << "wnuk " << person << endl;
			}
			else if (it->first > 4) {
				string s;
				for (int i = 0; i < (it->first - 4); i++) {
					s += "pra";
				}
				if (person._gender == 0)
					cout << s << "wnuczka " << person << endl;
				else
					cout << s << "wnuk " << person << endl;
			}
			else if (it->first < -2) {
				string s;
				int temp = -(it->first);
				for (int i = 0; i < temp - 2; i++) {
					s += "pra";
				}
				if (person._gender == 0)
					cout << s << "babcia " << person << endl;
				else
					cout << s << "dziadek " << person << endl;
			}
		}
	}
}

Pointer Tree::Find(string firstname, string lastname) {
	Pointer wsk;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vector = 0;
		for (Person person : _tree[it->first]) {
			if (person._firstName == firstname && person._lastName == lastname) {
				cout << person << endl;
				wsk.map = it->first;
				wsk.vector = vector;
				return wsk;
			}
			++vector;
		}
	}
	wsk.map = 404;
	return wsk;
}

void Tree::Delete(int map, int vector) {
	auto it = _tree[map].begin()+vector;
	_tree[map].erase(it);
}

void Tree::Edit(int map, int vector, const Person& person) {
	
	_tree[map].push_back(person);
	auto it = _tree[map].begin() + vector;
	_tree[map].erase(it);
	
}

bool Tree::Import(string filename) {
	fstream file;
	file.open(filename, std::ios::in);
	if (file.good()) {
		int lastAdded = 0;
		while (file) {
			string firstName, lastName;
			string familyName= " ";
			string relationship =" ";
			string date;
			char temp;
			string tempDate;

			file >> relationship;
			if (relationship == " ")
				break;

			file >> firstName;
			file >> lastName;
			file >> temp;
			if (temp == '(') {
				file >> familyName;
				familyName.resize(familyName.length() - 1);

				file >> date;
			}
			else {
				date += temp;
				file >> tempDate;
				date += tempDate;
			}
			
			if (relationship == "ja->") {
				bool gender;
				file >> gender;
				addUser(Person(firstName, lastName, familyName, Date(date), gender));
				lastAdded = 0;
			}
			else if (relationship == "siostra") {
				addSibling(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = 1;
			}
			else if (relationship == "brat") {
				addSibling(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = 1;
			}
			else if (relationship == "zona") {
				addPartner(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = 2;
			}
			else if (relationship == "maz") {
				addPartner(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = 2;
			}
			else if (relationship == "corka") {
				addChild(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = 3;
			}
			else if (relationship == "syn") {
				addChild(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = 3;
			}
			else if (relationship == "matka") {
				addParent(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = -1;
			}
			else if (relationship == "ojciec")	{
				addParent(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = -1;
			}
			else if (relationship == "babcia") {
				addGrandParent(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = -2;
			}
			else if (relationship == "dziadek") {
				addGrandParent(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = -2;
			}
			else if (relationship == "wnuczka") {
				addGrandChild(Person(firstName, lastName, familyName, Date(date), 0));
				lastAdded = 4;
			}
			else if (relationship == "wnuk") {
				addGrandChild(Person(firstName, lastName, familyName, Date(date), 1));
				lastAdded = 4;
			}
			else if (relationship[0] == 'p' && relationship[1] == 'r' &&  relationship[2] == 'a' ) {
				int counter = 1;
				string rest;
				for (int i = 3; i < relationship.length(); i = i + 3) {
					if (relationship[i] == 'p')
						counter++;
					else break;
				}
				for (int i = (counter*3); i < relationship.length(); i++) {
					rest += relationship[i];
				}
				
				if (rest == "babcia") {
					int rel = -(counter);
					addPerson(Person(firstName, lastName, familyName, Date(date), 0), rel-2);
					lastAdded = rel-2;
				}
				else if (rest == "dziadek") {
					int rel = -(counter);
					addPerson(Person(firstName, lastName, familyName, Date(date), 1), rel - 2);
					lastAdded = rel - 2;
				}
				else if (rest == "wnuczka") {
					addPerson(Person(firstName, lastName, familyName, Date(date), 0), 4 + counter);
					lastAdded = 4+counter;
				}
				else if (rest == "wnuk") {
					addPerson(Person(firstName, lastName, familyName, Date(date), 1), 4 + counter);
					lastAdded = 4 + counter;
				}

			}
			else {
				bool gender;
				if (relationship[relationship.length()-1] == 'a')
					gender = 0;
				else gender = 1;
				addPerson(Person(firstName, lastName, familyName, Date(date), gender, relationship), lastAdded);
			}
		}
	

		file.close();
		return true;
	}
	else {
		file.close();
		return false;
	}
}

void Tree::Export(string filename) {

	fstream file;
	file.open(filename, std::ios::out);

	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		for (Person person : _tree[it->first]) {
			if (it->first == 0)
				file << "ja-> " << person << endl;
			else if (it->first == 3) {
				if (person._gender == 0 && person._relationship == " ")
					file << "siostra " << person << endl;
				else if (person._gender == 1 && person._relationship == " ")
					file << "brat " << person << endl;
				else if (person._relationship != " ")
					file << person._relationship << " " << person << endl;
			}
			else if (it->first == 1) {
				if (person._gender == 0)
					file << "zona " << person << endl;
				else
					file << "maz " << person << endl;
			}
			else if (it->first == 2) {
				if (person._gender == 0 && person._relationship == " ")
					file << "corka " << person << endl;
				else if (person._gender == 1 && person._relationship == " ")
					file << "syn " << person << endl;
				else if (person._relationship != " ")
					file << person._relationship << " " << person << endl;
			}
			else if (it->first == -1) {
				if (person._gender == 0 && person._relationship == " ")
					file << "matka " << person << endl;
				else if (person._gender == 1 && person._relationship == " ")
					file << "ojciec " << person << endl;
				else if (person._relationship != " ")
					file << person._relationship << " " << person << endl;
			}
			else if (it->first == -2) {
				if (person._gender == 0 && person._relationship == " ")
					file << "babcia " << person << endl;
				else if (person._gender == 1 && person._relationship == " ")
					file << "dziadek " << person << endl;
				else if (person._relationship != " ")
					file << person._relationship << " " << person << endl;
			}
			else if (it->first == 4) {
				if (person._gender == 0)
					file << "wnuczka " << person << endl;
				else
					file << "wnuk " << person << endl;
			}
			else if (it->first > 4) {
				string s;
				for (int i = 0; i < (it->first - 4); i++) {
					s += "pra";
				}
				if (person._gender == 0)
					file << s << "wnuczka " << person << endl;
				else
					file << s << "wnuk " << person << endl;
			}
			else if (it->first < -2) {
				string s;
				int temp = -(it->first);
				for (int i = 0; i < temp - 2; i++) {
					s += "pra";
				}
				if (person._gender == 0)
					file << s << "babcia " << person << endl;
				else
					file << s << "dziadek " << person << endl;
			}
		}
	}


	file.close();
}