#pragma once
class listWords
{
public:
	int i, numWords;

	listWords(void);
	~listWords(void);

	void printWordArray();
	void getUserLetters();  
	void printUserInput(); 
	int findWords(char startingLetter);  
	void findWords();
	void printUsersWords(); 

};

