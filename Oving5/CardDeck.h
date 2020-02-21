#pragma once


int randomWithLimits(int nedreGrense, int ovreGrense);

class CardDeck {
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle(); //vi kan bruke swap() i shuffle()
	const Card& drawCard();

	//for Blackjack
	vector<Card> Cards();
	Card CardB(int Indeks);
	void append(Card card);
	void Clear();
	int Size();
	
	
private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int Indeks1, int Indeks2);
	//swap er privat fordi vi ikke ønsker at spilleren skal bytte om på ett og ett kort.


};