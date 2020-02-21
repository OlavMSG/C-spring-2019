#pragma once
#include <list>
#include <string>
#include <iostream>

using namespace::std;


class Person 
{
private:
	string fornavn;
	string etternavn;

public:
	Person(string fn, string en);

	void printPersonCasual() const;
	void printPersonOfficial() const;
	string getLastName() const;
	string getFirstName() const;
	friend bool operator==(const Person& lhs, const Person& rhs);
};


void insertPerson(list<Person> &l, const Person& p);

void printPeopleList(list<Person> l);