#include "stdafx.h"
#include <iostream>
#include "Func.h"
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	char array[11][10] = {{'c','+','+'}, {'f','a','n','t','a','s','t','i','c'}, {'g','a','n','g','n','a','m'}, 
						 {'h','o','w'},  {'i','s'}, {'l','o','v','e'}, {'m','u','c','h'}, 
						 {'s','t','y','l','e'},  {'v','e','r','y'}, {'w','e'}, {'y','o','u'}};
	char choice[100];
	int numWords = sizeof(array)/10;
	int i=0;
	
	cout<<"***** OUR WORDBANK CONTAINS THE FOLLOWING WORDS: *****"<<endl;
	for (int k=0; k<numWords; k++)
	{
		cout<<array[k]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Number of words in our wordbank: "<<numWords;
	cout<<endl<<endl;
	
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

	cout<<endl<<"You entered "<<i<<" letters and they are: "<<endl;

	for (int j=0; j<i; j++)
	{
		cout<<choice[j]<<" ";
	}
	
	bool found = false;
	for (int j=0; j<i; j++)
	{
		int nthWord = findWord( array, numWords, choice[j]);
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
	
	cout<<"The corresponding words are: "<<endl;
	for (int j=0; j<i; j++)
	{
			{
				int nthWord = findWord( array, numWords, choice[j]);
				if (nthWord!=-1) printWord(array, nthWord);
			}	
	}

	cout<<endl<<endl;
	system("pause");
	return 0;
}

