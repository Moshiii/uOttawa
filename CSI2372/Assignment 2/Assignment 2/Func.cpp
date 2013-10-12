#include "StdAfx.h"
#include "Func.h"
#include <iostream>
using namespace std;

int findWord( char pointerTo2Darray[][10], int numWords, char startingLetter){
	for(int i=0;i<numWords;i++){
		if (pointerTo2Darray[i][0]==startingLetter) return i;
	}
	return -1;
}

void printWord(char pointerTo2Darray[][10], int nthWord){
	for (int i=0; (i<10)&(pointerTo2Darray[nthWord][i]!=NULL);i++){
		cout<<pointerTo2Darray[nthWord][i];
	}
	cout<<" ";
}



