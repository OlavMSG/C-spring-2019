#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testCallByReference() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesRef(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << v0 << endl;
}

void testswapNumbers() {
	int a = 1;
	int b = 2;
	cout << "a = " << a << ", b = " << b << '\n';
	swapNumbers(a, b);
	cout << "swaping... \n";
	cout << "a = " << a << ", b = " << b << '\n';

}

void testVectorSorting() {
	vector<int> percentages;
	int n;
	cout << "Antall element i vektor: ";
	cin >> n;
	cout << '\n';
	randomizeVector(percentages, n);
	for (const int& x : percentages) {
		cout << x << ", ";
	}
	cout << '\n';
	double m1 = medianOfVector(percentages);
	cout << "median: " << m1  << '\n';
	sortVector(percentages);
	for (const int& x : percentages) {
		cout << x << ", ";
	}
	cout << '\n';
	
m1 = medianOfVector(percentages);
	cout << "median: " << m1 << '\n';
	
}

void testString() {
	string grades;
	grades = randomizeString(8, 'A', 'F');
	cout <<"Grades: " << grades << '\n';
	vector<int> gradeCount;
	for (char c = 'A'; c < 'G'; c++) {
		gradeCount.push_back(countChar(grades, c));
	}
	double sum = 0;
	for (int i = 0; i < gradeCount.size(); i++) {
		sum += gradeCount[i] * (5 - i);
	}
	 double gjennomsnitt = sum / gradeCount.size();
	 cout << "Gjennomsnittskarakter: " << gjennomsnitt << '\n';
	
	
	if (false) {
		string grades2;
		grades2 = readInputToString('A', 'F', 4);
		cout << "test les inn bokstaver: " << grades2 << '\n';
	}
	
}