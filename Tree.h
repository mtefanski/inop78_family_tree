#pragma once
#include <map>
#include <vector>
#include <fstream>
#include "Person.h"

using std::vector;
using std::map;
using std::fstream;

class Tree
{
public:
	map<int, vector<Person>> _tree;

	void addUser(const Person&);
	
	void addGrandParent(const Person&);
	void addParent(const Person&);
	void addSibling(const Person&);
	void addPartner(const Person&);
	void addChild(const Person&);
	void addGrandChild(const Person&);

	void addPerson(const Person &,int);

	void printTree();

	Pointer Find(string, string);

	void Delete(int, int);

	void Edit(int, int, const Person&);

	bool Import(string);

	void Export(string);

};

