#pragma once

enum class Suit {
	clubs, diamonds, hearts, spades
};

enum class Rank {
	two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

class Card {
public:
	Card();
	Card(Suit suit, Rank rank);
	Suit suit();
	Rank rank();
	bool isValid();
	string toString();
	string toStringShort();
private:
	Suit s;
	Rank r;
	bool valid;

};



struct CardStruct {
	Suit s;
	Rank r;
};

const map<Suit, string> Cardsuits {
		{Suit::clubs, "Clubs"}, {Suit::diamonds, "Diamonds"},
		{Suit::hearts, "Hearts"}, {Suit::spades, "Spades"}
};

const map<Rank, string> Cardranks{
	{Rank::two, "Two"}, {Rank::three, "Three"}, {Rank::four, "Four"},
	{Rank::five, "Five"}, {Rank::six, "Six"}, {Rank::seven, "Seven"},
	{Rank::eight, "Eight"}, {Rank::nine, "Nine"}, {Rank::ten, "Ten"},
	{Rank::jack, "Jack"}, {Rank::queen, "Queen"}, {Rank::king, "King"},
	{Rank::ace, "Ace"}
};

string suitToString(Suit type);
string rankToString(Rank rank);
string toString(CardStruct card);
string toStringShort(CardStruct card);

