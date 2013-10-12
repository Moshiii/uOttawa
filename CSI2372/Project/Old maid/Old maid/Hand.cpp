#include "StdAfx.h"
#include "Hand.h"
#include <iomanip>

Hand::Hand(void)
{
}

void Hand::printHand()
{
	int i= 0;
	vector<Card>::iterator it;
	for (it=hand.begin(); it<hand.end(); it++)
		{
			cout<<setw(18)<<it->getCard()<<" ";
			if (i%3==2) cout<<endl;
			i++;
		}
}

void Hand::discardPair()
{
	vector<Card>::iterator it1,it2,it3;
	for (it1=hand.begin(); it1<hand.end(); it1++)
		for (it2=hand.begin(); it2<hand.end(); it2++)
			if ((it1->value==it2->value)&&(it1->isInPair==false)&&(it2->isInPair==false)&&(it1!=it2))
			{
				it1->isInPair = true;
				it2->isInPair = true;
				cout<<"Removing "<<it1->getCard()<<" and "<<it2->getCard()<<endl;
			}
	for (it1=hand.begin(); it1<hand.end();)
	{
		if (it1->isInPair==true)
		{
			it1 = hand.erase(it1);
		}
		else it1++;
	}
}
Hand::~Hand(void)
{
}
