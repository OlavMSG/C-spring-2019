#include "std_lib_facilities.h"
#include "Card.h"
#include "tests.h"
#include "CardDeck.h"

void testsuitToString() {
	Suit noe = Suit::spades;
	string s = suitToString(noe);
	cout << s << endl;
}

void testrankToString() {
	Rank noen = Rank::ace;
	string sen = rankToString(noen);
	cout << sen << endl;
}

void testtoString() {
	CardStruct card1;
	card1.s = Suit::diamonds;
	card1.r = Rank::four;
	string s90 = toString(card1);
	cout << s90 << endl;
}

void testtoStringShort() {
	CardStruct card1;
	card1.s = Suit::diamonds;
	card1.r = Rank::four;
	string s80 = toStringShort(card1);
	cout << s80 << endl;
}

void testClassCard() {
	Card s1 = Card(Suit::hearts, Rank::queen);
	string s2 = s1.toString();
	cout << s2 << endl;
	string s3 = s1.toStringShort();
	cout << s3 << endl;
	Card s4 = Card();
	string s5 = s4.toString();
	cout << s5 << endl;
	string s6 = s4.toStringShort();
	cout << s6 << endl;
}

void testCardDeck() {
	CardDeck black1 = CardDeck();
	black1.print();
	cout << endl;
	black1.printShort();
	cout << endl;
	black1.shuffle();
	black1.printShort();
	cout << endl;
	Card kort1 = black1.drawCard();
	string s1 = kort1.toStringShort();
	cout << "kort1 " << s1 << endl;
	Card kort2 = black1.drawCard();
	string s2 = kort2.toStringShort();
	cout << "kort2 " << s2 << endl;
	for (int i = 0; i < 50; ++i) {
		Card kort = black1.drawCard();
		string s = kort.toStringShort();
		cout << "kort " << s << endl;
	}
}
	