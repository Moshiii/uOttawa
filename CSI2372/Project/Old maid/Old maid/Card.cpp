#include "StdAfx.h"
#include "Card.h"
#include <sstream>
#define toString( x ) dynamic_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) ).str()

Card::Card()
{
}
Card::Card(string type, int value)
{
	this->type=type;
	this->value=value;
	isInPair = false;
}


Card::~Card(void)
{
	isInPair = false;
}

string Card::getCard()
{
	string value;
	if (this->value==1) value="Ace";
	else if (this->value>=2&&this->value<=10) value = toString(this->value);
	else if (this->value==11) value = "Jack";
	else if (this->value==12) value = "Queen";
	else if (this->value==13) value = "King";
	return value + " of " + this->type;
}
