#pragma once

class Blackjack {//Støtter sålangt kun et spill per kjøring/kortstokk.
public:
	void Game();

private:
	CardDeck Deck;
	bool ShallDealerDraw;
	char Stand;
	CardDeck PlayersHand;
	CardDeck DealersHand;
	int findHandValue(CardDeck Hand);
	void Draw(CardDeck& Hand);
	void ShallDealerDrawTest();
	void testForWin();

};

const map<Rank, int> RanksValue{
	{Rank::two, 2}, {Rank::three, 3}, {Rank::four, 4},
	{Rank::five, 5}, {Rank::six, 6}, {Rank::seven, 7},
	{Rank::eight, 8}, {Rank::nine, 9}, {Rank::ten, 10},
	{Rank::jack, 10}, {Rank::queen, 10}, {Rank::king, 10},
	{Rank::ace, 11}
};