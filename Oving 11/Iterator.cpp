#include "Iterator.h"

void replace(vector<string>& vec, string old, string replacement) {
	for (vector<string>::iterator p = vec.begin(); p != vec.end(); ++p)
	{
		if (*p == old) 
		{
			p = vec.erase(p);
			p = vec.insert(p, replacement);
		}
	}
}

void replace(set<string>& set1, string old, string replacement) {
	for (set<string>::iterator p = set1.begin(); p != set1.end(); ++p)
	{
		if (*p == old)
		{
			p = set1.erase(p);
			p = set1.insert(p, replacement);
		}
	}
}

void print_reverse(const vector<string> vec)
{
	for (vector<string>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl << endl;
}

void print_reverse(const set<string> set1)
{
	for (set<string>::const_reverse_iterator it = set1.crbegin(); it != set1.crend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl << endl;
}

void print(const vector<string> vec)
{
	for (vector<string>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl << endl;
}

void print(const set<string> set1)
{
	for (set<string>::const_iterator it = set1.cbegin(); it != set1.cend(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl << endl;
}

void testIterator() 
{
	vector<string> vec1{ "Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur" };
	print_reverse(vec1);
	vector<string> vec2{ "Lorem", "Ipsum", "Dolor", "Lorem" };
	replace(vec2, "Lorem", "Latin");
	print(vec2);

	set<string> set1{ "Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur" };
	print_reverse(set1);
	set<string> set2{ "Lorem", "Ipsum", "Dolor", "Lorem" };
	replace(set2, "Lorem", "Latin");
	print(set2);
	//set dropper duplikate, kunne brukt template for print, print_revese og replace
}
