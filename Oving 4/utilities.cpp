#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
}

void swapNumbers(int& a, int& b) {
	int placeholder = a;
	a = b;
	b = placeholder;
}

void randomizeVector(vector<int>& vektor, int n) {
	for (int i = 0; i < n; i++) {
		vektor.push_back(randomWithLimits(0, 100));
	}

}

//generer tilfeldig tall med grenser
int randomWithLimits(int nedreGrense, int ovreGrense) {
	while (true) {
		int tilfeldig_tall = rand();
		if ((tilfeldig_tall >= nedreGrense) and (tilfeldig_tall <= ovreGrense)) {
			return tilfeldig_tall;
		}
	}
}

void sortVector(vector<int>& vektor) {
	int i = 1;
	while (i < vektor.size()) {
		int j = i;
		while ((j > 0) && (vektor[j - 1] > vektor[j])) {
			swapNumbers(vektor[j], vektor[j - 1]);
			j -= 1;
		}
		i += 1;

	}
}

double medianOfVector(const vector<int>& vektor) {
	int k = vektor.size() - 1; //null indekser
	double m1;
	if (k % 2 != 0) {
		m1 = (vektor[k / 2] + vektor[k / 2 + 1])/ 2;
		return m1;
	}
	else {
		m1 = vektor[(k + 1)/ 2];
		return m1;

	}
}

string randomizeString(int AntallTegn, char nedregrense, char ovregrense) {
	string s;
	int ng = static_cast<int>(nedregrense);
	int og = static_cast<int>(ovregrense);

	for (int i = 0; i < AntallTegn; i++) {
		char c = randomWithLimits(ng, og);
		s.push_back(c);
	}
	return s;
}

string readInputToString(char nedregrense, char ovregrense, int n) {
	string s;
	while (s.size() != n) {
		char c;
		cout << "Skriv inn en bokstav (" << nedregrense << '-' << ovregrense << "): ";
		cin >> c;
		cout << '\n';
		if (isalpha(c)) {
			if (((c >= toupper(nedregrense)) && (c <= toupper(ovregrense)))
				or ((c >= tolower(nedregrense)) && (c <= tolower(ovregrense)))) {
				s.push_back(toupper(c)); //vil bare ha store bokstaver i streng
			}
			else {
				cout << "Ugyldig input, prøv igjen. \n";
			}
		}
		else {
			cout << "Ugyldig input, prøv igjen. \n";
		}
	}
	return s;
}

int countChar(string s, char c) {
	int count = 0;
	for (char x : s) {
		if (x == c) {
			count += 1;
		}
	}
	return count;
}
