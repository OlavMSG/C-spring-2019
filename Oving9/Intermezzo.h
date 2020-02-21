#pragma once
#include <iostream>
#include <string> 
#include <utility>

using namespace::std;


class Dummy {
public:
	int *num;
	Dummy() 
	{
		num = new int{ 0 };
	}
	~Dummy() 
	{
		delete num;
	}
	int get() const;
	Dummy(const Dummy &other);
	Dummy operator=(Dummy rhs)
	{
		swap(num, rhs.num);
		return *this;
	}

};

void dummyTest();