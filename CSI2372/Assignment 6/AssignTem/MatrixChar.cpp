#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//**********************************
//definition for char specialization
//**********************************
template <int const ROWNUM, int const COLNUM> Matrix<char, ROWNUM, COLNUM>::Matrix()//default constructor
{
	row = ROWNUM;
	col = COLNUM;
	arr = new char* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new char [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]='A';
}
template <int const ROWNUM, int const COLNUM> Matrix<char, ROWNUM, COLNUM>::Matrix(char** array)//second constructor
{
	row = ROWNUM;
	col = COLNUM;
	arr = new char* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new char [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=array[i][j];
}

template <int const ROWNUM, int const COLNUM> void Matrix<char, ROWNUM, COLNUM>::print()//print method
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

//*************************************
//definition for char 2x2 specialization
//*************************************

Matrix<char,2,2>::Matrix()//default constructor
{
	row = 2;
	col = 2;
	arr = new char* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new char [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=0;
}

Matrix<char,2,2>::Matrix(char** array)//second constructor
{
	row = 2;
	col = 2;
	arr = new char* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new char [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=array[i][j];
}

string Matrix<char,2,2>::determinant()//determinant
{
	return "No determinant exists for Char type matrix";
}

void Matrix<char,2,2>::print()//print method
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}