#include "std_lib_facilities.h"
#include "utilities.h"


int main() {
	setlocale(LC_ALL, "norwegian");
	CourseCatalog Fag;
	vector<Temps> t;
	int valg = -1;
	while (valg != 0) {
		cout << "0) Avslutt \n1) Les ord fra bruker og skriv de til fil\n2) Les fra fil og skriv til fil med linjenummer \n3) Tegnstatistikk i en fil \n"
			"4) Emnekatalog \n5) Emnekatalog fra fil til fil \n6) strukturet fil \n";
		cout << "Valg (0-6): ";
		cin >> valg;
		cout << '\n';
		switch (valg) {
		case 0:
			break;
		case 1:
			LesFraBrukerOgSkrivTilFil("test1.txt");
			break;
		case 2:
			LesFraFilOgSkrivTilFilMedLinjenummer("test2.txt", "test3.txt");
			break;
		case 3:
			LagTekst100charPerBokstav();
			TegnstatisikkIEnFil("test4.txt");
			TegnstatisikkIEnFil("grunnlov.txt");
			break;
		case 4:
			cout << "Skriver nå ut emnekatalogen: " << endl << Fag << endl;
			Fag.addCourse("TDT4110", "Informasjonsteknologigrunnkurs");
			Fag.addCourse("TDT4102", "Prosedyre - og objektorientert programmering");
			Fag.addCourse("TMA4100", "Matematikk 1");
			cout << "Skriver nå ut emnekatalogen: " << endl << Fag << endl;;
			Fag.addCourse("TDT4102", "C++");
			//det skjer ingen ting ved bruk av insert. Ved bruk av [] endrer oppførselen seg ved at faget legges til, 
			//men det gamle eksister forsatt. 
			//Dette er fordi TDT4102 alt eksisterer i mapen.
			//men insert(pair) gir ok utskrift, mens [] gir gal utskrift.
			cout << "Skriver nå ut emnekatalogen: " << endl << Fag << endl;
			break;
		case 5:
			Fag.getCourseCatalogFromFile("Fag1.txt");
			cout << "Skriver nå ut emnekatalogen Lest fra fil: " << endl << Fag << endl;
			Fag.saveCourseCatalogToFile("Fag2.txt");
			break;
		case 6:
			LesTempsFraFil("temperatures.txt", true); //bool-verdi for printing av vector
			break;

		default:
			break;

		}
		cout << '\n';
	}
	// Your code here



	return 0;
}