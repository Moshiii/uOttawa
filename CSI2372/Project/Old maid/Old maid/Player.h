#pragma once
#include <string>
#include "Hand.h"
using namespace std;
class Player
{
private:
	string name;
public:
	Hand hand;
	bool safe;
	Player();
	Player(string type, int tnum);
	void addToHand(Card tempCard);
	Card removeCard(int index);
	int numCardInHand();
	bool isHandEmpty();

	string getName();
	~Player(void);
};