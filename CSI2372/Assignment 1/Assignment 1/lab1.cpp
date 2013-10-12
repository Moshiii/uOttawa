#include "stdafx.h"
#include <iostream>
#include "vector3.h"
using namespace std;
using namespace vctr;

int _tmain(int argc, _TCHAR* argv[])
{
	Vector3* array = new Vector3[5];
	for (int i=0;i<5;i++){
		
		cout<<"Run "<<i+1<<" :"<<endl;
		double a,b,c;
		cout<<"Please enter 3 points: "<<endl;
		cin>>a>>b>>c;
		array[i].x=a;
		array[i].y=b;
		array[i].z=c;
		cout<<"The input vector: "<<a<<"   "<<b<<"   "<<c<<endl;
		cout<<"The length is: "<<norm(array[i])<<endl;
		normalize(&array[i]);
		cout<<"The normalized vector: "<<array[i].x<<"   "<<array[i].y<<"   "<<array[i].z<<endl;
		cout<<endl;
	}

	system("pause");


	return 0;
}

