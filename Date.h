#pragma once

#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

class Date{
public:
	short _day;
	short _month;
	short _year;

	Date();
	Date(short,short,short);
	Date(const Date&);
	Date(string);
	Date& operator=(const Date&);
	~Date();

	bool isset();
	friend std::ostream & operator<<(std::ostream &, const Date & );
};

