#include "test.h"

void testMatrixA()
{
	Matrix A = Matrix();
	cout << A;
}

void testMatrixB()
{
	Matrix B = Matrix(3, 4);
	cout << B.getRows() << ' ' << B.getCols() << endl;
	cout << B[0][0] << endl;
	cout << B << endl;
}

void testMatrixC()
{
	Matrix C = Matrix(3);
	C.set(1, 2, 3);
	cout << C << endl;
}

void testKopiOgLik() {
	Matrix A = Matrix(4, 2);
	A.set(0, 1, 50);
	cout << "Matrise A" << endl;
	cout << A << endl;
	cout << "Lager B = A, og skriver ut" << endl;
	Matrix B = A;
	cout << B << endl;
	cout << "Endrer i B, og skriver ut" << endl;
	B.set(0, 1, 100);
	cout << B << endl;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut A[0][1] og B[0][1]" << endl;
	cout << A[0][1] << " og " << B[0][1] << endl;
}

void testLosning() 
{
	//lager A
	Matrix A = Matrix(2);
	A.set(0, 1, 2.0);
	A.set(1, 0, 3.0);
	A.set(1, 1, 4.0);
	//lager B
	Matrix B = Matrix(2);
	B.set(0, 0, 4.0);
	B.set(0, 1, 3.0);
	B.set(1, 0, 2.0);
	//lager C
	Matrix C = Matrix(2);
	C.set(0, 1, 3.0);
	C.set(1, 0, 1.5);
	C.set(1, 1, 2.0);
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "Skriver ut C" << endl;
	cout << C << endl;
	cout << "Gjoer beregning" << endl;
	A += B + C;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "Skriver ut C" << endl;
	cout << C << endl;
}

void testminus()
{
	Matrix A = Matrix(3);
	Matrix B = Matrix(3);
	B.set(0, 0, 9.0);
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "Setter A -= B" << endl;
	A -= B;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "Setter C = -A" << endl;
	Matrix C = -A;
	cout << "Skriver ut C" << endl;
	cout << C << endl;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "setter D = A - C" << endl;
	Matrix D = A - C;
	cout << "Skriver ut D" << endl;
	cout << D << endl;
	cout << "Skriver ut C" << endl;
	cout << C << endl;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
}

void testGangeLik()
{
	Matrix A = Matrix(2);
	A.set(0, 0, 11);
	A.set(0, 1, 3);
	A.set(1, 0, 7);
	A.set(1, 1, 11);
	Matrix B = Matrix(2, 3);
	B.set(0, 0, 8);
	B.set(0, 2, 1);
	B.set(1, 1, 3);
	B.set(1, 2, 5);
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "A *= B" << endl;
	A *= B;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
}

void testGange()
{
	Matrix A = Matrix(2);
	A.set(0, 0, 11);
	A.set(0, 1, 3);
	A.set(1, 0, 7);
	A.set(1, 1, 11);
	Matrix B = Matrix(2, 3);
	B.set(0, 0, 8);
	B.set(0, 2, 1);
	B.set(1, 1, 3);
	B.set(1, 2, 5);
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
	cout << "C = A * B" << endl;
	Matrix C = A * B;
	cout << "Skriver ut C" << endl;
	cout << C << endl;
	cout << "Skriver ut A" << endl;
	cout << A << endl;
	cout << "Skriver ut B" << endl;
	cout << B << endl;
}