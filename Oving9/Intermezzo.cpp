#include "Intermezzo.h"


void dummyTest() 
{
	Dummy a;
	*a.num = 4;
	Dummy b{ a };
	Dummy c;
	c = a;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	*b.num = 3;
	*c.num = 5;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	//cin.get(); // For å hindre at
	// programmet avslutter med en gang
}


int  Dummy::get() const
{
	return *num;
}

Dummy::Dummy(const Dummy &other) : num{ nullptr }
{
	this->num = new int{};
	*num = other.get();
}

//a koden skriver ut: 
//a: 4
//b: 4
//c : 4
//a : 5
//b : 5
//c : 5
//b, ja svarte mitt fra forgje oppgave stemte, dette er fordi verken 
//kopikonstruktørern ikke er definert og = operatoren ikke er overlastet.
//c, nei, = operatoren er ikke enda overlastet.
