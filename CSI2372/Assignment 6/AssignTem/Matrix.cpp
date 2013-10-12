#include "stdafx.h"
#include <iostream>
using namespace std;

//*******************************
//definition for general template
//*******************************
template <class T, int const ROWNUM, int const COLNUM>//default constructor
Matrix<T, ROWNUM, COLNUM>::Matrix(){
	row = ROWNUM;
	col = COLNUM;
	arr = new T* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new T [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=0;		
}

template <class T, int const ROWNUM, int const COLNUM>//second constructor
Matrix<T, ROWNUM, COLNUM>::Matrix(T** array){
	row = ROWNUM;
	col = COLNUM;
	arr = new T* [row];
	for (int i=0; i<row; i++)
	{
		arr[i] = new T [col];
	}
	for (int i=0; i<row; i++)
		for (int j=0; j<col;j++)
			arr[i][j]=array[i][j];		
}

template <class T, int const ROWNUM, int const COLNUM> //print method
void Matrix<T, ROWNUM, COLNUM>::print(){
	for (int i=0; i<row; i++)
		{
			for (int j=0; j<col;j++)
			cout<<arr[i][j]<<" ";
			cout<<endl;
		}
}
