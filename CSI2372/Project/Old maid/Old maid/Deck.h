#pragma once
#include "Card.h"
#include <vector>
class Deck
{
public:
	//Card deck[51];
	vector <Card> deck;
	Deck(void);
	~Deck(void);
	Card draw();
};

