#include "Person.h"


// Implementation of the calss Person

Person::Person(string fn, string en) : fornavn{ fn }, etternavn{ en } {}

void Person::printPersonCasual() const 
{ 
	cout << fornavn << " " << etternavn << endl; 
}

void Person::printPersonOfficial() const 
{ 
	cout << etternavn << ", " << fornavn << endl; 
}

string Person::getLastName() const 
{ 
	return etternavn; 
}

string Person::getFirstName() const 
{ 
	return fornavn; 
}
// Functions

void insertPerson(list<Person> &l, const Person& p)
{
	for (list<Person>::iterator itr = l.begin(); itr != l.end(); itr++)
	{
		if (itr->getLastName() < p.getLastName()) { continue; }
		if (itr->getLastName() == p.getLastName() && itr->getFirstName() < p.getFirstName())
		{
			continue;
		}
		if (itr->getLastName() == p.getLastName() && itr->getFirstName() == p.getFirstName())
		{
			cout << "Person alredy in list." << endl;
			return;
		}

		l.insert(itr, p);
		return;
	}

	l.insert(l.end(), p);
}void printPeopleList(list<Person> l)
{
	for (list<Person>::iterator itr = l.begin(); itr != l.end(); itr++)
	{
		itr->printPersonOfficial();
	}}bool operator==(const Person& lhs, const Person& rhs){	return lhs.getLastName() == rhs.getLastName() && lhs.getFirstName() == rhs.getFirstName();}ostream& operator<<(ostream& os, Person& p) {	p.printPersonOfficial();	return os;}void testPerson(){	list<Person> l;	Person p1{ "Olav", "Gran" };	insertPerson(l, p1);	Person p2{ "Marieluise", "Gran" };	insertPerson(l, p2);	Person p3{ "Sigrid", "Gran" };	insertPerson(l, p3);	Person p4{ "Frauke", "Gran" };	insertPerson(l, p4);	Person p5{ "Bjoern", "Gran" };	insertPerson(l, p5);	printPeopleList(l);}