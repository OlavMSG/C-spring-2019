#include "std_lib_facilities.h"
#include "cannonball.h"

//akselrasjon i Y-retning
double acclY() { 
	return -9.81; 
}

//fart i Y-retning
double velY(double initVelocity, double time) {
	return initVelocity + acclY() * time;
}

//x-posisjon etter tiden time
double posX(double initPosition, double initVelocity, double time) {
	return initPosition + initVelocity * time;
}

//y-posisjon etter tiden time
double posY(double initPosition, double initVelocity, double time) {
	return initPosition + initVelocity * time + acclY() * pow(time, 2) / 2;
}

//printer lesbar tid
void printTime(double time) {
	int h = static_cast<int>( time / 3600);
	time -= h * 3600;
	int min = static_cast<int>(time / 60);
	time -= min * 60;
	cout << h << " timer, " << min << " minutter og " << time << " sekunder ";
}

//flytid
double flightTime(double initVelocity) {
	return -2 * initVelocity / acclY();
}

// Ber brukeren om to tall, en vinkel (i grader) og en fart.
// Formålet er å endre verdien på argumentene.
// theta og absVelocity er referanser til objektene funksjonen kalles med.
void getUserInput(double& theta, double& absVelocity) {
	//Tatt fra Github i faget
	{theta = -1;
	while ((theta <= 0) or (theta >= 90)) {
		cout << "Skriv inn vinkel mellom 0 og 90 grader: ";
		cin >> theta;
		if (cin) { // we got an integer since cin returns true, now check it
			if ((theta >= 0) and (theta <= 90)) {
				break;
			}
			else {
				cout << "Prøv igjen. \n";
				;
				break;
			}
			break;
		}
		else if (cin.fail()) {
			cin.clear(); // set the state back to good
			cout << "ikke et tall, prøv igjen\n";
			for (char c; (cin >> c) && !isdigit(c); ) // throw away non-digits 
				/* do nothing */;  // for loop terminates when first digit is read
			cin.unget(); // put digit back, so that we can read the number
		}
	}

	}



	theta = degToRad(theta);
	//Tatt fra 
	{absVelocity = -1;
	while (absVelocity < 0) {
		cout << "Skriv inn fart (positiv): ";
		cin >> absVelocity;
		if (cin) { // we got an integer since cin returns true, now check it
			if (absVelocity >= 0) {
				break;
			}
			else {
				cout << "Prøv igjen. \n";
				break;
			}
			break;
		}
		else if (cin.fail()) {
			cin.clear(); // set the state back to good
			cout << "ikke et tall, prøv igjen\n";
			for (char c; (cin >> c) && !isdigit(c); ) // throw away non-digits 
				/* do nothing */;  // for loop terminates when first digit is read
			cin.unget(); // put digit back, so that we can read the number
		}
	}

	}


}

// Konverterer fra grader til radianer
double degToRad(double deg) {
	const double pi{ 3.14159 };
	return deg * pi / 180;
}

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
	return absVelocity * cos(theta);
}
double getVelocityY(double theta, double absVelocity) {
	return absVelocity * sin(theta);
}

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Komponentene oppdateres gjennom referansene.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) {
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}

// Gir lengden kanonkulla fløy i x-retning
double getDistanceTraveled(double velocityX, double velocityY) {
	return velocityX * flightTime(velocityY);
}

//returer avviket i avstand mellom mål og der kanonkulla landet
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}


