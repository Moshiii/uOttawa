#include "stdafx.h"
#include <iostream>
using namespace std;

//******************************
//partial specialization for 2x2
//******************************

template <class T> Matrix<T,2,2>::Matrix()//default constructor
{
	row = 2;
	col = 2;
	arr = new T* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new T [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=0;		
}

template <class T> Matrix<T,2,2>::Matrix(T** array)//second constructor
{
	row=2;
	col=2;
	arr = new T* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new T [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=array[i][j];
}

template <class T> void Matrix<T,2,2>::print()//print method
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

template <class T> T Matrix<T,2,2>::determinant()//return determinant
{
	return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
}

