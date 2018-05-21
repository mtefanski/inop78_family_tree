#pragma once
#include <string>
#include "Date.h"

using std::string;
using std::ostream;
typedef struct { int map; int vector; } Pointer;

class Person {
public:
	
	string _firstName;
	string _lastName;
	string _familyName;
	Date _birthDate;
	Date _deathDate;
	bool _gender;

	string _relationship;

	Pointer mother;
	Pointer father;
	Pointer partner;

	Person();
	Person(string, string, string, Date, bool);
	Person(string, string, string, Date, bool, string);
	Person(const Person&);
	Person& operator=(const Person&);
	friend ostream & operator<<(ostream&, const Person&);
};