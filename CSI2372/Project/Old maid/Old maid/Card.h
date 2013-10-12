#pragma once
#include <string>
using namespace std;
class Card
{
public:
	bool isInPair;
	int value;//from 1(ace) to 13 (king)
	string type;//heart, club, spade, diamond
	Card();
	Card(string type, int value);
	string getCard();
	~Card(void);
};

