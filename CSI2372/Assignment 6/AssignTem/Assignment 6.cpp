#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"*******************************************"<<endl;
	cout<<"5x6 double matrix with default constructor:"<<endl;
	cout<<"*******************************************"<<endl;
	Matrix<double,5,6> matrix1;
	matrix1.print();
	cout<<endl<<endl;

	cout<<"*******************************************"<<endl;
	cout<<"10x15 char matrix with default constructor:"<<endl;
	cout<<"*******************************************"<<endl;
	Matrix<char,10,15> matrix2;
	matrix2.print();
	cout<<endl<<endl;

	cout<<"************************************"<<endl;
	cout<<"2x3 double matrix with given values:"<<endl;
	cout<<"************************************"<<endl;
	double** givenArray = new double* [2];
	for (int i=0; i<2; i++)
	{
		givenArray[i] = new double [3];
	}
	givenArray[0][0]=1.2;givenArray[0][1]=3.4;givenArray[0][2]=5.6;
	givenArray[1][0]=2.1;givenArray[1][1]=2.4;givenArray[1][2]=4.2;
	Matrix<double,2,3> matrix3(givenArray);
	matrix3.print();
	cout<<endl<<endl;

	cout<<"************************************"<<endl;
	cout<<"2x2 integer matrix with given value:"<<endl;
	cout<<"************************************"<<endl;
	int** givenArray2 = new int* [2];
	for (int i=0; i<2; i++)
	{
		givenArray2[i] = new int [2];
	}
	givenArray2[0][0]=3; givenArray2[0][1]=5;
	givenArray2[1][0]=7; givenArray2[1][1]=4;
	Matrix<int,2,2> matrix4 (givenArray2);
	matrix4.print();
	cout<<"The determinant is: "<<matrix4.determinant();
	cout<<endl<<endl;

	cout<<"*********************************"<<endl;
	cout<<"2x2 char matrix with given value:"<<endl;
	cout<<"*********************************"<<endl;
	char** givenArray3 = new char* [2];
	for (int i=0; i<2; i++)
	{
		givenArray3[i] = new char [2];
	}
	givenArray3[0][0]='A'; givenArray3[0][1]='B';
	givenArray3[1][0]='C'; givenArray3[1][1]='D';
	Matrix<char,2,2> matrix5 (givenArray3);
	matrix5.print();
	cout<<"The determinant is: "<<matrix5.determinant();
	cout<<endl<<endl;

	cout<<"*************************"<<endl;
	cout<<"Matrix loaded from file: "<<endl;
	cout<<"*************************"<<endl;
	loadMatrixToArray();

	system("pause");
	return 0;
}
