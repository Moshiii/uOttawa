#include "StdAfx.h"
#include "Player.h"
#include <sstream>
#include <algorithm>
#define toString( x ) dynamic_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) ).str()
Player::Player()
{

}
Player::Player(string type, int num)
{
	if (type=="com")
	{
		this->name = "COM" + toString(num);
		safe= false;
	}
	else if (type == "man")
	{
		this->name = "Batman";
		safe = false;
	}
}

void Player::addToHand(Card tempCard)
{
	hand.hand.push_back(tempCard);
	random_shuffle ( hand.hand.begin(), hand.hand.end() );//shuffle hand
}

Card Player::removeCard(int index)
{
	Card temp;
	temp = hand.hand.at(index);
	hand.hand.erase(hand.hand.begin()+index);
	return temp;
}

int Player::numCardInHand()
{
	return hand.hand.size();
}
bool Player::isHandEmpty()
{
	if (hand.hand.size()==0) return true;
	else return false;
}

string Player::getName()
{
	return name;
}

Player::~Player(void)
{
}
