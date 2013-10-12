#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;
class Hand
{
public:
	vector<Card> hand;
	Hand(void);
	void discardPair();
	void printHand();
	~Hand(void);
};

