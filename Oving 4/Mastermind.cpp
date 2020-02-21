#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "Mastermind.h"

void playMastermind() {
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr int Forsøk = 10;
	//bruker constexpr og ikke const fordi dette gjør det umulig å endre på disse konstantene i senere kode.
	string code;
	string guess;
	code = randomizeString(size, 'A', 'A' + (letters - 1));
	int rettplass = -1;
	int rett;
	int forsøk = 1;
	cout << "Velkommen til Mastermind! \nSpillet hvor du skal knekke min \"uknekklige\" kode på " << size << " bokstaver. \n"
		<< "Dette gjøres ved at du skriver inn en og en bokstav i koden du gjetter på. \nDu har " << Forsøk << " forsøk. \n"
		<< "Lykke til! \n\n";
	cout << "Koden er ikke: " << code << '\n';
	while (rettplass != size) {
		{if (forsøk == Forsøk + 1) {
			cout << "Tap! Å nei, bedre lykke neste gang, koden var " << code << '\n';
			break;
		}}
		cout << "Forsøk: " << forsøk << '\n';
		guess = readInputToString('A', 'A' + (letters - 1), size);
		cout << "Du gjettet " << guess << '\n';
		if (guess == code) {
			cout << "Gratuler du har vunnet, koden var " << code << ". Du klarte det på " << forsøk << " forsøk \n";
			break;
		}
		else {
			rettplass = checkCharactersAndPosition(code, guess);
			rett = checkCharacters(code, guess);
			cout << "Du har " << rett << " rett, hvorav " << rettplass << " på rett plass \n\n";
		}
		forsøk += 1;
	}
}

int checkCharactersAndPosition(const string code, const string guess) {
	int ok = 0;
	for (int i = 0; i < code.size(); i++) {
		if (guess[i] == code[i]) {
			ok += 1;
		}
	}
	return ok;
}

int checkCharacters(const string code, const string guess) {
	int ok = 0;
	set <int> s;
	for (char c : guess) {
		s.insert(c);
	}
	for (char a : s) {
		for (int i = 0; i < code.size(); i++) {
			if (a == code[i]) {
				ok += 1;
			}
		}
	}
	return ok;
}