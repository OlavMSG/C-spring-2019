#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <utility>

using namespace::std;

class Matrix 
{
private:
	int *Mrows;
	int *Ncols;
	double **matrix;

public:
	Matrix();
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows);
	~Matrix();

	double get(int row, int col) const;
	void set(int row, int col, double value);
	int getRows() const;
	int getCols() const;
	bool isValid() const;

	//kopikonstruktør
	Matrix(const Matrix & rhs);

	//operatorer
	double* operator[](int i) {
		return matrix[i];
	}

	Matrix& operator=(Matrix rhs)
	{
		swap(matrix, rhs.matrix);
		swap(Mrows, rhs.Mrows);
		swap(Ncols, rhs.Ncols);
		return *this;
	}

	Matrix& operator+=(Matrix rhs) 
	{
		if (*Mrows != *rhs.Mrows && *Ncols != *rhs.Ncols)
		{
			*this = Matrix();
		}
		else
		{
			for (int i = 0; i < *Mrows; i++)
			{
				for (int j = 0; j < *Ncols; j++)
				{
					matrix[i][j] += rhs.get(i, j);
				}
			}
		}
		return *this;
	}

	Matrix operator+(Matrix rhs)
	{
		//ops! this skal ikke endres, se operator +=
		return rhs += *this;
	}

	Matrix& operator-=(Matrix rhs)
	{
		if (*Mrows != *rhs.Mrows && *Ncols != *rhs.Ncols)
		{
			*this = Matrix();
		}
		else
		{
			for (int i = 0; i < *Mrows; i++)
			{
				for (int j = 0; j < *Ncols; j++)
				{
					matrix[i][j] -= rhs.get(i, j);
				}
			}
		}
		return *this;
	}

	Matrix operator-(Matrix rhs)
	{
		//ops! this skal ikke endres, se operator +=
		return - rhs += *this;
	}

	Matrix& operator*=(Matrix rhs)
	{
		if (*Ncols != *rhs.Mrows)
		{
			*this = Matrix();
		}
		else
		{
			Matrix lhs = Matrix(*Mrows, *rhs.Ncols);
			for (int k = 0; k < *Mrows; k++)
			{
				Matrix pholder = Matrix(*Mrows, *rhs.Ncols);
				for (int n = 0; n < *Ncols; n++)
				{
					for (int i = 0; i < *rhs.Ncols; i++)
					{
						pholder.set(n, i, matrix[k][n] * rhs.get(n, i));
					}
				}
				for (int i = 0; i < *pholder.Ncols; i++)
				{
					double value = 0;
					for (int j = 0; j < *pholder.Mrows; j++)
					{
						value += pholder.get(j, i);
					}
					lhs.set(k, i, value);
				}
			}
			*this = lhs;
		}
		return *this;
	}

	Matrix operator*(Matrix rhs)
	{
		Matrix lhs = Matrix();
		if (*Ncols == *rhs.Mrows)
		{
			lhs = Matrix(*Mrows, *rhs.Ncols);
			for (int k = 0; k < *Mrows; k++)
			{
				Matrix pholder = Matrix(*Mrows, *rhs.Ncols);
				for (int n = 0; n < *Ncols; n++)
				{
					for (int i = 0; i < *rhs.Ncols; i++)
					{
						pholder.set(n, i, matrix[k][n] * rhs.get(n, i));
					}
				}
				for (int i = 0; i < *pholder.Ncols; i++)
				{
					double value = 0;
					for (int j = 0; j < *pholder.Mrows; j++)
					{
						value += pholder.get(j, i);
					}
					lhs.set(k, i, value);
				}
			}
		}
		return lhs;
	}

	friend Matrix operator-(Matrix rhs);
	
	friend ostream& operator<<(ostream& os, Matrix& m);
};