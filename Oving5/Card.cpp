#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit suit) {
	
	return Cardsuits.at(suit);
}

string rankToString(Rank rank) {

	return Cardranks.at(rank);
}

string toString(CardStruct card1) {
	string s1 = suitToString(card1.s);
	string s2 = rankToString(card1.r);
	return s2 + " of " + s1;
}

string toStringShort(CardStruct card1) {
	string s1 = suitToString(card1.s);
	int s3 = int(card1.r);
	string s2 = to_string(s3);
	return s1.at(0) + s2;
}

Card::Card() {
	valid = false;
}

Card::Card(Suit suit, Rank rank) {
	s = suit;
	r = rank;
	valid = true;
}

Suit Card::suit() {
	return s;
}

Rank Card::rank() {
	return r;
}

bool Card::isValid() {
	return valid;
}

string Card::toString() {
	if (isValid()) {
		string s1 = suitToString(suit());
		string s2 = rankToString(rank());
		return s2 + " of " + s1;
	}
	else {
		return "Ugyldig kort";
	}
}

string Card::toStringShort() {
	if (isValid()) {
		string s1 = suitToString(suit());
		int s3 = int(rank());
		string s2 = to_string(s3);
		return s1.at(0) + s2;
	}
	else {
		return "Ugyldig kort";
	}
}
