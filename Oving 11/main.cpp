#include "Iterator.h"
#include "Person.h"
#include "LinkedList.h"
#include "Templates.h"
#include "LinkedList.h"

int main() 
{
	srand(time(0));
	testIterator();
	cout << endl;
	testPerson();
	cout << endl;
	testLinkedList();
	cout << endl;
	testTemplate();
	cout << endl;
	return 0;
}