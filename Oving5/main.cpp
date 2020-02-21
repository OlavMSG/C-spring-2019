#include "std_lib_facilities.h"
#include "Card.h"
#include "tests.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main(){
	setlocale(LC_ALL, "norwegian");
	Blackjack Game1;
	int valg = -1;
	while (valg != 0) {
		cout << "0) Avslutt \n1) test suitToString \n2) test rankToString \n3) test toString \n4) test toStringShort \n"
			<< "5) test class Card \n6) test CardDeck \n7) Play Blackjack \n";
		cout << "Valg (0-7): ";
		cin >> valg;
		cout << '\n';
		switch (valg) {
		case 0:
			break;
		case 1:
			//skriver ut Spades
			testsuitToString();
			break;
		case 2:
			//skriver ut Ace
			testrankToString();
			//fordeler ved å representere farge og verdi på kort som symboler er at representasjon med tall fort blir uoversiktlig.
			break;
		case 3:
			//Skriver ut Four of Diamonds
			testtoString();
			break;
		case 4:
			//skriver ut D4
			testtoStringShort();
			break;
		case 5:
			//skriver ut Queen of Hearts, H12 og feil, feil
			testClassCard();
			//ønsker å representere kort som en klasse fordi da kan jeg tildele dem funksjoner lett.
			//klassen invariant ???
			break;
		case 6:
			srand(static_cast<unsigned int>(time(nullptr)));
			testCardDeck();
			break;
		case 7:
			srand(static_cast<unsigned int>(time(nullptr)));
			Game1.Game();
			break;
			
		default:
			break;

		}
		cout << '\n';
	}
	// Your code here
	

	
	return 0;
}