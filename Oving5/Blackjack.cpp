#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

//finner håndens verdi
int Blackjack::findHandValue(CardDeck Hand) {
	int Handsum = 0;
	for (Card x : Hand.Cards()) {
		int xValue = RanksValue.at(x.rank());
		if ((xValue == 11) and ((Handsum + 11) > 21)) {//Har trukket ess på siste trekk
			xValue = 1;
		}
		Handsum += xValue;
	}
	return Handsum;
}

void Blackjack::Draw(CardDeck& Hand) {
	Card kort = Deck.drawCard();
	Hand.append(kort);
}


//skal dealer trekke kort
void Blackjack::ShallDealerDrawTest() {
	int Handsum = findHandValue(DealersHand);
	if (Handsum >= 17) {
		ShallDealerDraw = false;
	}
	else {
		ShallDealerDraw = true;
	}
}

//Har du vunnet???
void Blackjack::testForWin() {
	int PlayerHandsum = findHandValue(PlayersHand); //spillers score
	int DealerHandsum = findHandValue(DealersHand); //Dealers score
	//Ser om du har vunnet
	cout << endl;
	if ((PlayerHandsum == 21) and (DealerHandsum != 21) and (PlayersHand.Size() == 2)) {
		cout << "Congratulations you won with a true Blackjack." << endl;
	}
	else if ((PlayerHandsum == 21) and (DealerHandsum != 21)) {
		cout << "Congratulations you won." << endl;
	}
	else if ((PlayerHandsum <= 21) and (DealerHandsum <= PlayerHandsum)) {
		cout << "Congratulations you won." << endl;
	}
	else if ((PlayerHandsum < 21) and (DealerHandsum > 21)) {
		cout << "Congratulations you won." << endl;
	}
	else {
		cout << "Dealer won , better luck next time" << endl;
	}
	cout << "Dealers Hand was: ";
	DealersHand.print();
	DealersHand.printShort(); //Skriver ut dealears kort
	cout << "Dealers Hands totalvalue was: " << DealerHandsum << endl; //skriver ut dealers håndsverdi.
	cout << "Your Hand was: ";
	PlayersHand.print();
	PlayersHand.printShort(); //skriver ut din hånd.
	cout << "Your Hands totalvalue was: " << PlayerHandsum << endl; //skriver ut din håndsverdi.
}


//Spillet
void Blackjack::Game() {
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "Welcome to Blackjack." << endl << "The game were you want to get 21." << endl << "The dealer must stand if (s)he has 17 or more." << endl << endl;
	cout << "The Deck consists of: " << endl;
	Deck = CardDeck();
	Deck.print(); //skriver ut ublanda kortstokk slik at spiller kan se at alle kort er der
	cout << endl << "In short format: " << endl;
	Deck.printShort(); //skriver ut dette slik at spiller blir kjent med notasjonen
	cout << endl;
	Deck.shuffle();
	//Deck.printShort(); //Hvis du vil jukse
	PlayersHand.Clear();
	DealersHand.Clear();
	Draw(PlayersHand); //spiller får 1. kort i kortstokken
	Draw(DealersHand); //Dealer får 2. kort i kortstokken
	cout << "Dealers 1. Card: ";
	DealersHand.print();
	DealersHand.printShort(); //Skriver ut dealears kort
	int DealerHandvalue = findHandValue(DealersHand); //Dealers score
	cout << "Dealers Hands totalvalue is: " << DealerHandvalue << endl; //skriver ut spillers håndsverdi.
	Draw(PlayersHand);  //spiller får 3. kort i kortstokken
	Draw(DealersHand); //Dealer får 4. kort i kortstokken
	cout << "Your Hand: ";
	PlayersHand.print();
	PlayersHand.printShort(); //skriver ut spillers hånd.
	int PlayerHandvalue = findHandValue(PlayersHand);
	cout << "Your Hands totalvalue is: " << PlayerHandvalue<< endl; //skriver ut spillers håndsverdi.
	cout << endl;

	Stand = 'Q'; // setter stand til noe ikke lik Y eller N
	bool Firstround = true;
	while (true) {
		if ((Stand == 'Y') and (PlayerHandvalue < 21)) {
			Stand = 'Q'; //resete stand hvis du svarte Y sist 
		}

		while (((Stand != 'Y') and (Stand != 'N') and (PlayerHandvalue <= 21)) or Firstround) { //Ta inn Stand
			cout << "Do you want a card(Y/N): ";
			cin >> Stand;
			cout << endl;
			Stand = toupper(Stand);
			Firstround = false;
		}

		if ((Stand == 'Y') and (PlayerHandvalue <= 21)) {
			Draw(PlayersHand);
			cout << "Your Hand: ";
			PlayersHand.print();
			PlayersHand.printShort(); //skriver ut din hånd.
			PlayerHandvalue = findHandValue(PlayersHand);
			cout << "Your Hands totalvalue is: " << PlayerHandvalue << endl; //skriver ut din håndsverdi.
		}

		ShallDealerDrawTest(); //Har dealer 17 eller over på hånden
		
		if (ShallDealerDraw) {
			Draw(DealersHand); //Dealer får  ett kort.
		}

		if (((not ShallDealerDraw) and (Stand == 'N')) or (PlayerHandvalue >= 21)) {//Du vil ikke ha kort og dealer har 17 eller mer.
			break;
		}
	}
	testForWin();

}

