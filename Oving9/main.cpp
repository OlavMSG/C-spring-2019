#include "Fibonacci.h"
#include "Matrix.h"
#include "Intermezzo.h"
#include "test.h"

int main() 
{
	//for switch
	int valg = -1;
	//switchen
	while (valg != 0) 
	{
		cout << "0) Avslutt \n1) Fibonacci\n2) Test Matrix\n3) Intermezzo"
			<< "\n4) Test kopi og lik for Matrix\n5) Test pluss(loesning 5c) for Matrix"
			<< "\n6) Test minus for Matrix\n7) Test gangelik for Matrix\n8)"
			<< " Test gange for Matrix" << endl;
		cout << "valg (0-8): ";
		cin >> valg;

		switch (valg)
		{
		case 0:
			break;
		case 1:
			createFibonacci();
			break;
		case 2:
			testMatrixA();
			testMatrixB();
			testMatrixC();
			break;
		case 3:
			dummyTest();
			break;
		case 4:
			testKopiOgLik();
			break;
		case 5:
			testLosning();
			break;
		case 6:
			testminus();
			break;
		case 7:
			testGangeLik();
			break;
		case 8:
			testGange();
			break;
		default:
			break;
		}
		cout << endl;
	}
	

	return 0;
}

