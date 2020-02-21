#include "Matrix.h"


// Implementasjon av Matrix-klassen
//
// Konstruktører og destruktører

Matrix::Matrix() : Mrows{ nullptr }, Ncols{ nullptr }, matrix{ nullptr } {}

Matrix::Matrix(int nRows, int nColumns) : Mrows{ new int{nRows} }, Ncols{ new int{nColumns} }, matrix{ new double*[nRows] } 
{
	for (int i = 0; i < *Mrows; i++)
	{
		matrix[i] = new double[*Ncols];
		for (int j = 0; j < *Ncols; j++)
		{
			matrix[i][j] = 0.0;
		}
	}
}

Matrix::Matrix(int nRows) : Matrix{ nRows, nRows } {
	for (int i = 0; i < *Mrows; i++) {
		matrix[i][i] = 1.0;
	}
}

Matrix::~Matrix() 
{
	if (isValid())
	{

		for (int i = 0; i < *Mrows; i++) {
			delete[] matrix[i];
			matrix[i] = nullptr;
		}
		delete[] matrix;
		matrix = nullptr;
		delete Mrows;
		Mrows = nullptr;
		delete Ncols;
		Ncols = nullptr;
	}
}


// Medlemsfunksjoner

double Matrix::get(int row, int col) const 
{
	return matrix[row][col];
}

void Matrix::set(int row, int col, double value) 
{
	matrix[row][col] = value;
}

int Matrix::getRows() const 
{
	return *Mrows;
}

int Matrix::getCols() const 
{
	return *Ncols;
}

bool Matrix::isValid() const 
{
	return matrix && Mrows && Ncols;
}



// Operatorer

ostream& operator<<(ostream& os, Matrix& m) 
{
	if (!m.isValid()) 
	{
		os << "Ugyldig matrise" << endl;
		return os;
	}
	else
	{
		string s = "[";
		for (int i = 0; i < m.getRows(); i++)
		{
			s += "[ ";
			for (int j = 0; j < m.getCols(); j++)
			{
				s += to_string(m.get(i, j)) + ' ';
			}
			s += "]\n";
		}
		s.erase(s.size() - 1);
		s += "]";
		os << s << endl;
		return os;
	}
}

Matrix operator-(Matrix rhs)
{
	Matrix lhs = Matrix(*rhs.Mrows, *rhs.Ncols);
	lhs -= rhs;
	return lhs;
}

//kopikonstruktøren

Matrix::Matrix(const Matrix & rhs): Mrows{ nullptr }, Ncols{ nullptr }, matrix{ nullptr }
{
	this->Mrows = new int{};
	*Mrows = rhs.getRows();
	this->Ncols = new int{};
	*Ncols = rhs.getCols();
	this->matrix = new double*[*Mrows]{};
	for (int i = 0; i < *Mrows; i++)
	{
		matrix[i] = new double[*Ncols]{};
		for (int j = 0; j < *Ncols; j++)
		{
			matrix[i][j] = rhs.get(i, j);
		}
	}

}
