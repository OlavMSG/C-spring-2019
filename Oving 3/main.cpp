#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

void playTargetPractice();

int main() {
	setlocale(LC_ALL, "norwegian");
	int  valg = -1; //seter valg til noe ikke lik 0

	double maxError{ 0.0001 }; // set error her 
	cout << "Velg funksjon: \n0) Avslutt \n1) Play Target Practice \n2) Test acclY, velY, posX og posY \n";
	cout << "Angi valg (0-4): ";
	cin >> valg;
	switch (valg) {
		case 0:
			cout << '\n';
			cout << "Avslutter \n";
			break;
		case 1:
			cout <<'\n';
			srand(static_cast<unsigned int>(time(nullptr)));
			playTargetPractice();
			cout << '\n';
			break;
		case 2:
			cout << '\n';
			testDeviation(acclY(), -9.81, maxError, "accelY()");
			testDeviation(velY(25.0, 0), 25.0, maxError, "velY(25.0,0.0)");
			testDeviation(velY(25.0, 0), 25.0, maxError, "velY(25.0,0.0)");
			testDeviation(velY(25.0, 0), 25.0, maxError, "velY(25.0,0.0)");

			testDeviation(posX(0.0, 50.0, 0.0), 0.0, maxError, "posX(0.0,50.0,0.0)");
			testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0,50.0,2.5)");
			testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");

			testDeviation(posY(0.0, 25.0, 0.0), 0.0, maxError, "posY(0.0,50.0,0.0)");
			testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0,50.0,2.5)");
			cout << "Dette er trolig pga avrundingsfeil i orginalverdi. \n";
			testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0,50.0,5.0)");
			cout << '\n';
			
			break;
		default:
			cout << "Ugyldig valg prøv igjen. \n";
			return 0;
	
	}
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if (abs(compareOperand - toOperand) <= maxError) {
		cout << name << " er innenfor feiltoleransen. " << " Testverdi = " << compareOperand << " , orginalverdi = " << toOperand << " , maxerror = " << maxError <<'\n';
	}
	else {
		cout << name << " er ikke innenfor feiltoleransen. " << " Testverdi = " << compareOperand << " , orginalverdi = " << toOperand << " , maxerror = " << maxError << '\n';
	}
}

void playTargetPractice() {
	cout << "Target Practice \n \nI dette spillet skal du treffe en blink mellom 100 og 1000 meter unna med en kanonkulle skutt fra en kanon. \n"
		"Dette gjøres ved å oppgi en vinkle theta (i grader) på kanonen og en startfart til kanonkulla. \nDu har 10 forsøk, lykke til! \n \n";
	//setter avstand til blink mellom 100 og 1000 meter unna
	int Blink = randomWithLimits(100, 1000);
	//spiller har 10 forsøk
	for (int i = 1; i < 11; ++i) {
		cout << "Forsøk " << i << "\n \n";
		//oppretter variabler
		double theta{};
		double absVelocity{};
		double velocityX{};
		double velocityY{};
		//tar inn data fra spiller
		getUserInput(theta, absVelocity);
		//får tak i fart i x- og y-retning
		getVelocityVector(theta, absVelocity, velocityX, velocityY);
		//finner avstand til blink
		double AvstandTilBlink = targetPractice(Blink, velocityX, velocityY);
		//finner flytid
		double flytid = flightTime(velocityY);
		//kjører tester
		if (abs(AvstandTilBlink) < 5) {
			double DuTraff = velocityX * flytid;
			cout << "Treff, gratuler du har vunnet! Blinken var ved x = " << Blink << " meter. Skudde ditt traff " << DuTraff << " meter. \nKanonkulen brukte " << "på reisen \n";
				printTime(flytid);
			cout << "på reisen \n";
			break;
		}
		else {
			cout << "Bom, prøv igjen. \n";
			if (i == 10) {
				cout << "Tap, å nei du har brukt 10 forsøk, bedre lykke neste gang. \n Blinken var ved " << Blink << " meter. \n";
			}
			if (AvstandTilBlink < 0) {
				cout << "Skuddet var for langt. Kanonkulen brukte ";
				printTime(flytid);
				cout << "på reisen \n";
			}
			else {
				cout << "Skuddet var for kort. Kanonkulen brukte " << "på reisen \n";
				printTime(flytid);
				cout << "på reisen \n";
			} 
		}

	}

}

	

