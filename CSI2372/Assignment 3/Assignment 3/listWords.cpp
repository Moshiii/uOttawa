#include "StdAfx.h"
#include "listWords.h"
#include <iostream>
using namespace std;

char database[11][10] = {{'c','+','+'}, {'f','a','n','t','a','s','t','i','c'}, {'g','a','n','g','n','a','m'}, 
{'h','o','w'},  {'i','s'}, {'l','o','v','e'}, {'m','u','c','h'}, 
{'s','t','y','l','e'},  {'v','e','r','y'}, {'w','e'}, {'y','o','u'}};

listWords::listWords(void)
{
	array=database;
	choice = new char[100];//array to hold user input
	numWords = sizeof(database)/10;
	i=0;
}


listWords::~listWords(void)
{
	delete choice;
}

void listWords::printWordArray(){
	cout<<"printWordArray():"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"***** OUR WORDBANK CONTAINS THE FOLLOWING WORDS: *****"<<endl;
	for (int k=0; k<numWords; k++)
	{
		cout<<array[k]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Number of words in our wordbank: "<<numWords;
	cout<<endl<<endl;
}
void listWords::getUserLetters(){
	cout<<"getUserLetters():"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Please input the starting letters: (input x to stop)"<<endl;

	while (true){
		char temp;
		cin>>temp;
		if (temp!='x')
		{
			choice[i] = temp;
			i++;			
		} else break;		
	}
	cout<<endl;
}

void listWords::printUserInput(){
	cout<<"printUserInput():"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"You entered "<<i<<" letters and they are: "<<endl;

	for (int j=0; j<i; j++)
	{
		cout<<choice[j]<<" ";
	}
	cout<<endl<<endl;

}


void listWords::findWords(){
	cout<<"findWords():"<<endl;
	cout<<"-----------------"<<endl;

	//print out valid letters
	for (int j=0; j<i; j++)
	{
		int nthWord = findWords(choice[j]);
		if (nthWord!=-1){			
			cout<<"FOUND: "<<choice[j]<<" is "<<nthWord<<"th"<<endl;
		}
	}

	//print out invalid letters
	bool found = false;
	for (int j=0; j<i; j++)
	{
		int nthWord = findWords(choice[j]);
		if (nthWord==-1){
			if (!found){
				found = true;
				cout<<endl<<endl;
				cout<<"Invalid letters: "<<endl;
			}
			cout<<choice[j]<<" ";
		}
	}
	cout<<endl<<endl;


}   

int listWords::findWords(char startingLetter){
	for(int i=0;i<numWords;i++){
		if (array[i][0]==startingLetter) return i;
	}
	return -1;
}


void listWords::printUsersWords(){
	cout<<"printUserWords():"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"The corresponding words are: "<<endl;
	for (int j=0; j<i; j++)
	{
		{
			int nthWord = findWords(choice[j]);
			if (nthWord!=-1) {
				for (int i=0; (i<10)&(array[nthWord][i]!=NULL);i++){
					cout<<array[nthWord][i];
				}
				cout<<" ";
			}
		}	
	}

	cout<<endl<<endl;
} 
