#include "std_lib_facilities.h"

int maxOfTwo(int a, int b) {
	//finner største tall av a og b
	if (a > b) {
		cout << "A is greater than B\n";
		return a;}
	else {
		cout << "B is greater than or equal to A\n";
		return b;}
}

int fibonacci(int n) {
	//fibonaccitallene opp til og med fibonaccitall n, og summer dem
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers: \n";
	for (int x = 1; x < n+1; ++x) {
		cout << x << ", " << b << '\n';
		int temp = b;
		b += a;
		a = temp;}
	cout << "---\n";
	return b;}

int squareNumberSum(int n) {
	//kvadratsummen av tallene opp til n
	int totalSum = 0;
	for (int i = 0; i < n; ++i) {
		totalSum += i * i; 
		cout << i * i << '\n';}
	cout << totalSum << '\n';
	return totalSum;}

void triangleNumbersbelow(int n) {
	//skriver ut trejanttall under n
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << " : " << "sep = \"\"" << '\n';
	while (acc < n) {
		cout << acc << '\n';
		acc += num;
		num += 1;}
	cout << '\n';}

bool isPrime(int n) {
	//primtall opp til n
	for (int j = 2; j < n; ++j) {
		if (n % j == 0) {
			return false;}}
	return true;}

void naivePrimeNumberSearch(int n) {
	//skriver ut primtall opp til n
	for (int number = 2; number < n; ++number) {
		if (isPrime(number)) {
			cout << number << " is a prime \n";
		}
	}
}

int findGreatestDivisor(int n) {
	for (int divisor = n - 1; divisor > 0; --divisor) {
		if (n%divisor == 0) {
			return divisor;
		}
	}
	return 1;
}

int main(){
	//kjører funkjsonene
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << '\n';
	cout << "Oppgave c)\n";
	cout << fibonacci(10) << '\n';
	cout << "Oppgave d)\n";
	cout << squareNumberSum(10) << '\n';
	cout << "Oppgave e)\n";
	triangleNumbersbelow(10);
	cout << "Oppgave f)\n";
	if (isPrime(7))
	{
		cout << "true";
	}
	else {
		cout << "fasle";
	}
	cout << '\n';
	cout << "Oppgave g)\n";
	naivePrimeNumberSearch(10);
	cout << "Oppgave h)\n";
	cout << findGreatestDivisor(1);








	return 0;
}