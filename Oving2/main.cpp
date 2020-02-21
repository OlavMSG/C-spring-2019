#include "std_lib_facilities.h"

//tar inn et heltall fra bruker og skriver det ut
void inputAndPrintInteger() {
	int x = 0;
	cout << "Skriv inn et heltall: ";
	cin >> x;
	cout << "Du skrev: " << x;
}

//tar inn et heltall fra bruker og returner det
int inputInteger() {
	int x = 0;
	cout << "Skriv inn et heltall: ";
	cin >> x;
	return x;
}

//tar inn to heltall fra bruker 
//og skriver ut summen av dem
void inputIntegersAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();
	cout << "Summen av heltallene er: " << x + y << '\n';
}

//tester om et tall er et oddetall
bool isOdd(int n) {
	if (n%2 != 0) {
		return true;
	}
	else {
		return false;
	}
}

//skriver ut tid i sekuder i timer, minutter, sekunder
void printHumanReadableTime(int sek) {
	int h = sek / 3600;
	sek -= h * 3600;
	int min = sek / 60;
	sek -= min * 60;
	cout << h << " timer, " << min << " minutter og " << sek << " sekunder \n";

}

//spør bruker om antall heltall som skal tas inn 
//og tar de inn fra bruker 
//og skriver ut summen av dem
void inputIntegersUsingLoopAndPrintSum() {
	int xi = -1;
	int sum = 0;
	cout << "Summer n antall heltall, 0 avslutter, og skriver ut summen \n";
	while (xi != 0) {
		xi = inputInteger();
		sum += xi;
	}
	cout << "Summen av heltallene er: " << sum << '\n';
}

//Tar inn et flyttall fra bruker og returner det
double inputDouble() {
	double x = 0;
	cout << "Skriv inn et desimatall: ";
	cin >> x;
	return x;

}

//konverter NOK til Euro
void NOKtilEuro() {
	double NOK = 0;
	const double Kurs = 9.75;
	cout << "Skriv inn antall NOK du vil konverter til Euro (Tallet må vaere positivt). \n";
	while (true) {
		NOK = inputDouble();
		if (NOK < 0) {
			cout << "Prøv igjen (Tallet maa vaere positivt). \n";
		}
		else {
			cout << "Det vekslede beløpet i Euro er: " << setprecision(2) << NOK / Kurs << '\n';
			break;
		}

	}
}


//finner discriminaten
double discriminant(double a, double b, double c) {
	return b * b - 4 * a*c;
}

//printer reelle røtter 
void printRealRoots(double a, double b, double c) {
	double D = discriminant(a, b, c);
	if (D < 0) {
		cout << "Likningen har ingen reell løsning.\n";
	}
	else if (D == 0) {
		cout << "Likningen har en løsning x=" << -b / (2 * a) << '\n';
	}
	else {
		cout << "Likningen har to løsninger x1=" << (-b - sqrt(D)) / (2 * a) << " og " << (-b + sqrt(D)) / (2 * a) << '\n';
	}
}

//løser andregradslikning
void solveQuadraticEquation() {
	cout << "Skriv inn a, b og c i a*x^2+b*x+c=0. \n";
	cout << "a: \n ";
	double a = inputDouble();
	cout << "b: \n ";
	double b = inputDouble();
	cout << "c: \n";
	double c = inputDouble();
	printRealRoots(a, b, c);
}


//serielån
vector<int> calculateSeries(int TotaltLån, int AntallAvdrag, int Rente) {
	vector<int> InnbetalingS(AntallAvdrag); // AntallAvdrag int av verdien 0
	int GjenståendeLån = TotaltLån;
	for (int i = 0; i < AntallAvdrag; i++) {
		InnbetalingS[i] = TotaltLån/AntallAvdrag + Rente/100.0 * GjenståendeLån;
		GjenståendeLån -= TotaltLån / AntallAvdrag;
	}
	return InnbetalingS;

}


//Annuitetslån
vector<int> calculateAnnuity(int TotaltLån, int AntallAvdrag, int Rente) {
	vector<int> InnbetalingA(AntallAvdrag); // AntallAvdrag int av verdien 0
	for (int i = 0; i < AntallAvdrag; i++) {
		InnbetalingA[i] = TotaltLån * (Rente/100.0)/(1 - pow(1+Rente/100.0,-AntallAvdrag));
	}
	return InnbetalingA;
}

//oppgave 5c
void printTabell(int TotaltLån, int AntallAvdrag, int Rente) {
	vector<int> InnbetalingS = calculateSeries(TotaltLån, AntallAvdrag, Rente);
	vector<int> InnbetalingA = calculateAnnuity(TotaltLån, AntallAvdrag, Rente);
	cout <<setw(6) << "År" << setw(15) << "Annuitet" << setw(15) << "Serie" << setw(15) << "Differanse" << '\n';
	int sumS = 0;
	int sumA = 0;
	for (int i = 0; i < AntallAvdrag; i++) {
		cout << setw(6) << i+1 << setw(15) << InnbetalingA[i] << setw(15) << InnbetalingS[i] << setw(15) << InnbetalingA[i] - InnbetalingS[i] << '\n';
		sumS += InnbetalingS[i];
		sumA += InnbetalingA[i];
	}
	cout << setw(6) << "Totalt" << setw(15) << sumA << setw(15) << sumS << setw(15) << sumA - sumS << '\n';
}

void runprintTabell() {
	int TotaltLån = 0;
	int AntallAvdrag = 0;
	int Rente = 0;
	cout << "Skriv inn TotaltLån: \n";
	TotaltLån = inputInteger();
	cout << "Skriv inn AntallAvdrag: \n";
	AntallAvdrag= inputInteger();
	cout << "Skriv inn Rente: \n";
	Rente = inputInteger();
	printTabell(TotaltLån, AntallAvdrag, Rente);
}

//kjører oppgaver
void Oppgaver() {
	cout << "Velg oppgave: \n0) Tilbake til hovedmeny \n1) oppgave 1a \n2) oppgave 1b \n3) oppgave 1c \n4) oppgave 1d \n5)"
		"oppgave 1e \n6) oppgave 1f \n7) oppgave 2b\n8) oppgave 2e\n9) oppgave 4e\n10) oppgave 10c \n";
	cout << "Angi valg (1-9): ";
	int valg2 = -1;
	int number = 0;
	cin >> valg2;
	cout << '\n';
	switch (valg2) {
	case 0:
		cout << "Går tilbake til hovedmeny \n";
		break;
	case 1:
		cout << "Oppgave 1a)\n";
		inputAndPrintInteger();
		cout << '\n';
		break;
	case 2:
		cout << "Oppgave 1b)\n";
		number = inputInteger();
		cout << "Du skrev: " << number << '\n';
		break;
	case 3:
		cout << "Oppgave 1c)\n";
		inputIntegersAndPrintSum();
		break;
	case 4:
		cout << "Oppgave 1d)\n";
		cout << "Teori: Valgte å bruke inputInteger i deloppgave c) \n" <<
			"fordi inputAndPrintInteger også skriver ut hva du skrev og dette ønsket jeg ikke her. \n";
		break;
	case 5:
		cout << "Oppgave 1e \n";
		for (int i = 0; i < 16; ++i) {
			if (isOdd(i)) {
				cout << i << " er et oddetall \n";
			}
			else {
				cout << i << " er et partall \n";
			}
		}
		break;
	case 6:
		cout << "oppgave 1f) \n";
		printHumanReadableTime(10000);
		break;
	case 7:
		cout << "oppgave 2b) \n";
		cout << "Teori: Valgte å avslutt hvis 0 tastes inn \n fordi" 
			"bruker ofte ikke har helt kontroll på antall heltall" 
			"som skal summeres, \n i hvert fall hvis det er snakk om mange.";
			break;
	case 8:
		cout << "oppgave 2e) \n";
		cout << "Teori: Valgte inputDouble fremfor inputInteger fordi dette funger bedre ved at vi noen ganger ikke har et helt antall NOK. \n"
			"Valgte returtypen void og utskrift i funksjonen fordi jeg så dette som mest praktiskt.\n";
		break;
	case 9:
		cout << "oppgave 4e \n";
		cout << "x^2+2x+4=0";
		printRealRoots(1, 2, 4);
		cout << "4x^2+4x+1=0";
		printRealRoots(4, 4, 1);
		cout << "8x^2+4x-1=0";
		printRealRoots(8, 4, -1);
		break;
	case 10:
		cout << "oppgave 5c \n";
		printTabell(10000, 10, 3);
		break;
	default:
		cout << "Ugyldig valg \n";
	}
}



int main() {
	setlocale(LC_ALL, "norwegian");
	int  valg = -1; //seter valg til noe ikke lik 0
	
	while (valg != 0) {
		cout << "Velg funksjon: \n0) Avslutt \n1) Summer to tall \n2) Summer flere tall \n3) Konverter NOK til Euro \n4)"
			" Løs andregradslikning \n5) Serie og Annuitetslån \n6) Test andre oppgaver \n";
		cout << "Angi valg (0-6): ";
		cin >> valg;
		switch (valg) {
		case 0: 
			cout << '\n';
			cout << "Avslutter \n";
			break;
		case 1:
			cout << '\n';
			inputIntegersAndPrintSum();
			cout << '\n';
			break;
		case 2:
			cout << '\n';
			inputIntegersUsingLoopAndPrintSum();
			cout << '\n';
			break;
		case 3:
			cout << '\n';
			NOKtilEuro();
			cout << '\n';
			break;
		case 4:
			cout << '\n';
			solveQuadraticEquation();
			cout << '\n';
			break;
		case 5:
			cout << '\n';
			runprintTabell();
			cout << '\n';
			break;
		case 6:
			Oppgaver();
			break;
		default:
			cout << "Ugyldig valg \n";
		}
	}


	return 0;
}