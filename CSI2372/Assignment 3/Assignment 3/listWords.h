#pragma once
class listWords
{
public:
	int i, numWords;
	char (*array)[10];
	char* choice;

	listWords(void);
	~listWords(void);

	void printWordArray();
	void getUserLetters();  
	void printUserInput(); 
	int findWords(char startingLetter);  
	void findWords();
	void printUsersWords(); 

};

