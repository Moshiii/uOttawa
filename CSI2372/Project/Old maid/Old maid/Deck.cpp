#include "StdAfx.h"
#include "Deck.h"
#include <algorithm>


Deck::Deck(void)//create a deck, remove the queen of heart
{
	for (int i=0; i<13; i++)
		deck.push_back(Card ("Diamond", i+1));
	for (int i=13; i<25; i++)
		deck.push_back(Card("Club", (i+1)%13));
	deck.push_back(Card ("Club", 13));
	for (int i=26; i<39; i++)
		deck.push_back(Card("Spade", (i+1)%26));
	for (int i=39; i<50; i++)
		deck.push_back(Card("Heart", (i+1)%39));
	deck.push_back(Card("Heart", 13));
	random_shuffle ( deck.begin(), deck.end() );
}

Card Deck::draw()
{
	Card tempCard = deck.back();
	deck.pop_back();
	return tempCard;
}

Deck::~Deck(void)
{
}
