#include "Fibonacci.h"

void fillInFibonacciNumbers(int result[], int length) 
{
	result[0] = 0;
	if (length == 1) {
		return;
	}
	result[1] = 1;
	if (length == 2) {
		return;
	}
	//length 1 er "1 indekset"
	for (int i = 2; i < length; i++) {
		result[i] = result[i - 1] + result[i - 2];
	}
}

void printArray(int arr[], int length) 
{
	string s = "( ";
	for (int i = 0; i < length; i++) {
		s += to_string(arr[i]) + ' ';
	}
	s += ')';
	cout << s << endl;
}

void createFibonacci() 
{
	int length;
	cout << "Hvor mange fibonacci tall skal generes? ";
	cin >> length;
	int* fib = new int[length];
	fillInFibonacciNumbers(fib, length);
	printArray(fib, length);
	delete[] fib;
}