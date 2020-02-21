#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "Mastermind.h"

int main(){
	setlocale(LC_ALL, "norwegian");
	int valg = -1;
	while (valg != 0) {
		cout << "0) Avslutt \n1) testCallByValue \n2) testCallByReference \n3) testswapNumbers \n4) testVectorSorting \n"
			<< "5) testString \n6) playMastermind \n";
		cout << "Valg (0-6): ";
		cin >> valg;
		cout << '\n';
		switch (valg) {
		case 0: 
			break;
		case 1:
			testCallByValue();
			//oppgave 1a) Verdien 5 skrives ut for vO.
			break;
		case 2:
			testCallByReference();
			break;
		case 3:
			testswapNumbers();
			//funksjonen bruker referanser fordi den skal gjøre endringer på to variable
			break;
		case 4:
			srand(static_cast<unsigned int>(time(nullptr)));
			testVectorSorting();
			break;
		case 5:
			testString();
			break;
		case 6:
			srand(static_cast<unsigned int>(time(nullptr)));
			playMastermind();
			break;
		default:
			break;
		
		}
		cout << '\n';
	}


	return 0;
}