#include "Person.h"

Person::Person()
	:
	_firstName(" "),
	_lastName(" "),
	_familyName(" "),
	_birthDate(Date(0, 0, 0)),
	_deathDate(Date(0, 0, 0)),
	_gender(0),
	_relationship(" ")
{
}

Person::Person(string firstName, string lastName, string familyName, Date birthDate, bool gender)
	:
	_firstName(firstName),
	_lastName(lastName),
	_familyName(familyName),
	_birthDate(Date(birthDate)),
	_deathDate(Date(0,0,0)),
	_gender(gender),
	_relationship(" ")
{
}

Person::Person(string firstName, string lastName, string familyName, Date birthDate, bool gender, string rel) 
	:
	_firstName(firstName),
	_lastName(lastName),
	_familyName(familyName),
	_birthDate(Date(birthDate)),
	_deathDate(Date(0, 0, 0)),
	_gender(gender),
	_relationship(rel)
{
}

Person::Person(const Person& copy)
	:
	_firstName(copy._firstName),
	_lastName(copy._lastName),
	_familyName(copy._familyName),
	_birthDate(copy._birthDate),
	_deathDate(copy._deathDate),
	_gender(copy._gender),
	_relationship(copy._relationship)
{
}

Person& Person::operator=(const Person& copy) {
	if (this == &copy)
		return *this;

	_firstName = copy._firstName;
	_lastName = copy._lastName;
	_familyName = copy._familyName;
	_birthDate = copy._birthDate;
	_deathDate = copy._deathDate;
	_gender = copy._gender;
	_relationship = copy._relationship;

	return *this;
}

std::ostream & operator<<(std::ostream & s, const Person & p) {
	
	if (p._familyName != " ")
		s << p._firstName << " " << p._lastName << " (" << p._familyName << ") " << "ur. "<< p._birthDate;
	else
		s << p._firstName << " " << p._lastName << " ur. " << p._birthDate;
	
	if (p._deathDate._day != 0) {
		s << " zm. " << p._deathDate;
	}
	return s;
}