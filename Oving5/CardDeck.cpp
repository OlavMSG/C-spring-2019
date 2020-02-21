#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"


int randomWithLimits(int nedreGrense, int ovreGrense) {
	while (true) {
		int tilfeldig_tall = rand();
		if ((tilfeldig_tall >= nedreGrense) and (tilfeldig_tall <= ovreGrense)) {
			return tilfeldig_tall;
		}
	}
}

CardDeck::CardDeck() {
	for (int i = 0; i < 4; ++i) { //4 forskjellinge suiter
		for (int j = 2; j < 15; ++j) {//rank går fra 2 til 14=ace
			Card ij = Card(Suit(i), Rank(j));
			cards.push_back(ij);
		}
	}
	currentCardIndex = 0;
}

void CardDeck::swap(int Indeks1, int Indeks2) {
	Card card1 = cards.at(Indeks1);
	cards.at(Indeks1) = cards.at(Indeks2);
	cards.at(Indeks2) = card1;
}

void CardDeck::print() {
	int k = 1; //telle variabel
	string stringToPrint;
	for (Card x : cards) {
		string s1 = x.toString();
		if (k == 6) {
			s1 = s1 + ", \n";
			k = 0;
		}
		else {
			s1 = s1 + ", ";
		}
		stringToPrint += s1;
		k += 1;
	}
	stringToPrint.pop_back();
	stringToPrint.pop_back();

	cout << stringToPrint << endl;
}

void CardDeck::printShort() {
	int k = 1; //telle variabel
	string stringToPrint;
	for (Card x : cards) {
		string s1 = x.toStringShort();
		if (k == 13) {
			s1 = s1 + ", \n";
			k = 0;
		}
		else {
			s1 = s1 + ", ";
		}
		stringToPrint += s1;
		k += 1;
	}

	stringToPrint.pop_back();
	stringToPrint.pop_back();

	cout << stringToPrint << endl;
}

void CardDeck::shuffle() {
	int MaxAntallSwap = randomWithLimits(52, 104); //vil swape MaxAntallSwap ganger.
	int AntallSwap = 0; //telle variabel
	while (AntallSwap < MaxAntallSwap) {
		int Indeks1 = randomWithLimits(0, 51); //gir random tall mellom 0 og 51
		int Indeks2 = randomWithLimits(0, 51); //gir random tall mellom 0 og 51
		swap(Indeks1, Indeks2);
		AntallSwap += 1;
	}
}

const Card& CardDeck::drawCard() {
	if (currentCardIndex == 51) {
		cout << "Ingen kort igjen i kortstokken" << endl;
		return Card(); //returner et ugyldig kort.
	}
	else {
		Card draw = cards.at(currentCardIndex);
		currentCardIndex += 1;
		return draw;
	}
}


//funksjoner for Blackjack

vector<Card> CardDeck::Cards() {
	return cards;
}

Card CardDeck::CardB(int Indeks) {
	return cards.at(Indeks);
}

void CardDeck::append(Card card) {
	cards.push_back(card);
}

void CardDeck::Clear() {
	cards.clear();
}

int CardDeck::Size() {
	return cards.size();
}