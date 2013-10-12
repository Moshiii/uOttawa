#pragma once
#include <fstream>
#include <iostream>
using namespace std;

//****************
//general template
//****************
template <class T, int const ROWNUM, int const COLNUM> 
class Matrix
{
private:
	T** arr;
	int row, col;
public:
	Matrix();
	Matrix(T** array);
	void print();
};

//******************************
//partial specialization for 2x2
//******************************
template <class T> 
class Matrix<T,2,2>
{
private:
	T** arr;
	int row, col;
public:
	Matrix();
	Matrix(T** array);
	void print();
	T determinant();
};

//*******************************
//partial specialization for char
//*******************************
template <int const ROWNUM, int const COLNUM> 
class Matrix<char, ROWNUM, COLNUM>
{
private:
	char** arr;
	int row, col;
public:
	Matrix();
	Matrix(char** arr);
	void print();
};

//***************************
//specialization for char 2x2
//***************************
template <> 
class Matrix<char,2,2>
{
private:
	char** arr;
	int row, col;
public:
	Matrix();
	Matrix(char** array);
	string determinant();
	void print();
};

#include "MatrixChar.cpp"
#include "Matrix2.cpp"
#include "Matrix.cpp"

//*******************
//load matrix from file
//*******************

void loadMatrixToArray() {
	ifstream in("myMatrixInput.txt");

	if (!in) {
		cout << "Cannot open file.\n";
		return;
	}
	int** givenArray = new int* [4];
	for (int i=0; i<4; i++)
	{
		givenArray[i] = new int [5];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			in >> givenArray[i][j];
		}
	}
	in.close();
	Matrix<int,4,5> matrix (givenArray);
	matrix.print();

}
