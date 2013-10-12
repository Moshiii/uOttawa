/************************************************************************/
/*					Old maid
/* Student: Trung Do (6701991) (individually)
/************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <ctime>
#include <iomanip>
using namespace std;

void printInstruction()
{
	cout<<endl;
	cout<<"-This game can be played by two or more players"<<endl;
	cout<<"-From a standard 52 card pack, remove one queen leaving 51 cards"<<endl;
	cout<<"-The dealer deals out all the cards to the players"<<endl;
	cout<<"-The players all look at their cards and discard any pairs they have"<<endl;
	cout<<"-The dealer begins. At your turn you must offer your cards spread face down "<<endl;
	cout<<" to the player to your left"<<endl;
	cout<<"-That player selects a card from your hand without seeing it, and adds it to her hand"<<endl;
	cout<<"-If it makes a pair in her hand she discards the pair"<<endl;
	cout<<"-The player who just took a card then offers her hand to the next player to her ";
	cout<<" left, and so on"<<endl;
	cout<<"-If you get rid of all your cards you are safe and you take no further part"<<endl;
	cout<<"-The turn passes to the next player to your left, who spreads his or her cards "<<endl;
	cout<<" for the following player to draw one"<<endl;
	cout<<"-Eventually all cards will have been discarded except one queen (the old maid) "<<endl;
	cout<<" and the holder of this queen loses"<<endl<<endl;
	cout<<"*****************************************************************************";
}
void printAllHand(int nPlayer, Player* player)
{
	for (int i=0; i<nPlayer; i++)
	{
		cout<<"Player "<<player[i].getName()<<"'s hand: "<<endl;
		player[i].hand.printHand();
		cout<<endl<<endl;
	}
}

void printOldMaid()
{
	cout<<setw(49)<<"       ___  _     ____    __  __    _    ___ ____  "<<endl;
	cout<<setw(49)<<"      / _ \\| |   |  _ \\  |  \\/  |  / \\  |_ _|  _ \\ "<<endl;
	cout<<setw(49)<<"     | | | | |   | | | | | |\\/| | / _ \\  | || | | |"<<endl;
	cout<<setw(49)<<"     | |_| | |___| |_| | | |  | |/ ___ \\ | || |_| |"<<endl;
	cout<<setw(49)<<"      \\___/|_____|____/  |_|  |_/_/   \\_\\___|____/ "<<endl;

}

void startGameDebug()
{
	Deck deck;
	//print the deck (for debug)
	//cout<<"The deck's content: "<<endl;
	//for (int i=0;i<51;i++)
	//{
	//	cout<<deck.deck[i].getCard()<<endl;
	//}

	//create players
	int nPlayer;
	cout<<"Please enter number of players (2 or more): ";
	cin>>nPlayer;
	while (nPlayer<2)
	{
		cout<<"Invalid number of players. Try again: ";
		cin>>nPlayer;
	}
	cout<<endl;
	Player *player = new Player[nPlayer];
	for (int i=1; i<=nPlayer; i++) player[i-1] = Player("com", i);
	player[nPlayer-1] = Player ("man", nPlayer);

	//deal card
	for (int i=0; i<51; i++)
	{
		player[i%nPlayer].addToHand(deck.draw());
	}

	//print all players' hands (for debug)
	printAllHand(nPlayer, player);

	//discard all pairs initially
	for (int i=0; i<nPlayer; i++)
	{
		cout<<"Removing pairs from "<<player[i].getName()<<"'s hand:"<<endl;
		player[i].hand.discardPair();
		cout<<endl;
	}

	//print all players' hands (for debug)
	printAllHand(nPlayer, player);

	//setting up a new game
	system("pause");
	bool gameEnded = false;
	int currentPlayer = 0;
	int numPlayerSafe=0;//number of safe players
	int userChoiceOfCard[30];//array for user's choice of card
	for (int i=0;i<30; i++) userChoiceOfCard[i] = i;
	int i = 0;

	while (!gameEnded){
		cout<<endl;
		int leftPlayer = (currentPlayer+1)%nPlayer;//the player on the left
		while (player[leftPlayer].safe) leftPlayer=(leftPlayer+1)%nPlayer;//if that next player is already safe, go to the next one (and so on)

		int choice =  userChoiceOfCard[i]%player[currentPlayer].numCardInHand();//card to take
		Card tempCard = player[currentPlayer].removeCard(choice);//take a card from curernt player
		cout<<"Player "<<player[leftPlayer].getName()<<" chose card number "<<choice<<endl;
		cout<<"Moving card: "<<tempCard.getCard()<<" from "<<player[currentPlayer].getName()<<" to "<<player[leftPlayer].getName()<<": "<<endl<<endl;
		player[leftPlayer].addToHand(tempCard);//player on the left add card to hand
		player[leftPlayer].hand.discardPair();//check if a pair exists, if yes discard it
		if (player[leftPlayer].isHandEmpty()) //if the left player's hand is empty, he's safe
		{
			player[leftPlayer].safe=true;
			numPlayerSafe ++;
		}
		if (player[currentPlayer].isHandEmpty()) //if the current player's hand is empty, he's safe
		{
			player[currentPlayer].safe=true;
			numPlayerSafe ++;
		}
		cout<<endl;

		printAllHand(nPlayer,player);//debug

		if (numPlayerSafe==nPlayer-1)//if only one player's left
		{
			cout<<"Game ended! "<<endl;
			string loser;
			if (player[currentPlayer].isHandEmpty()) loser=player[leftPlayer].getName();
			else loser = player[currentPlayer].getName();
			cout<<loser<<" is the Old Maid!"<<endl<<endl;
			cout<<"************************************************************"<<endl<<endl;
			gameEnded = true;
		}
		else
		{
			system("pause");
			i= (i+1)%30;
			currentPlayer = ++currentPlayer%nPlayer;//go to the next player
			while (player[currentPlayer].safe) currentPlayer = (currentPlayer+1)%nPlayer;//if that next player is already safe, go to the next one (and so on)
		}
	}
}

void startGameNormal()
{
	Deck deck;

	//create players
	int nPlayer;
	cout<<"Please enter number of players (2 or more): ";
	cin>>nPlayer;
	while (nPlayer<2)
	{
		cout<<"Invalid number of players. Try again: ";
		cin>>nPlayer;
	}
	cout<<endl;
	Player *player = new Player[nPlayer];
	for (int i=1; i<=nPlayer; i++) player[i-1] = Player("com", i);
	player[nPlayer-1] = Player ("man", nPlayer);

	//deal card
	for (int i=0; i<51; i++)
	{
		player[i%nPlayer].addToHand(deck.draw());
	}

	//print your hand
	cout<<"Your hand:"<<endl;
	player[nPlayer-1].hand.printHand();
	cout<<endl<<endl;

	//discard all pairs initially
	for (int i=0; i<nPlayer; i++)
	{
		cout<<"Removing pairs from "<<player[i].getName()<<"'s hand:"<<endl;
		player[i].hand.discardPair();
		cout<<endl;
	}

	//print your hand after discarding
	cout<<"Your hand:"<<endl;
	player[nPlayer-1].hand.printHand();
	cout<<endl<<endl;

	//setting up a new game
	system("pause");
	bool gameEnded = false;
	int currentPlayer = 0;
	int numPlayerSafe=0;//number of safe players
	int userChoiceOfCard[30];//array for user's choice of card
	for (int i=0;i<30; i++) userChoiceOfCard[i] = i;
	int i = 0;

	while (!gameEnded){
		cout<<endl;
		int leftPlayer = (currentPlayer+1)%nPlayer;//the player on the left
		while (player[leftPlayer].safe) leftPlayer=(leftPlayer+1)%nPlayer;//if that next player is already safe, go to the next one (and so on)

		int choice =  userChoiceOfCard[i]%player[currentPlayer].numCardInHand();//card to take
		Card tempCard = player[currentPlayer].removeCard(choice);//take a card from curernt player
		cout<<"Player "<<player[leftPlayer].getName()<<" chose card number "<<choice<<endl;
		cout<<"Moving card: "<<tempCard.getCard()<<" from "<<player[currentPlayer].getName()<<" to "<<player[leftPlayer].getName()<<": "<<endl<<endl;
		player[leftPlayer].addToHand(tempCard);//player on the left add card to hand
		player[leftPlayer].hand.discardPair();//check if a pair exists, if yes discard it
		if (player[leftPlayer].isHandEmpty()) //if the left player's hand is empty, he's safe
		{
			player[leftPlayer].safe=true;
			numPlayerSafe ++;
		}
		if (player[currentPlayer].isHandEmpty()) //if the current player's hand is empty, he's safe
		{
			player[currentPlayer].safe=true;
			numPlayerSafe ++;
		}
		cout<<endl;

		if ((leftPlayer==nPlayer-1)||(currentPlayer==nPlayer-1))//if player's turn, print hand
		{
			cout<<"Your hand:"<<endl;
			player[nPlayer-1].hand.printHand();
			cout<<endl<<endl;
		}

		if (numPlayerSafe==nPlayer-1)//if only one player's left
		{
			cout<<"Game ended! "<<endl;
			string loser;
			if (player[currentPlayer].isHandEmpty()) loser=player[leftPlayer].getName();
			else loser = player[currentPlayer].getName();
			cout<<loser<<" is the Old Maid!"<<endl<<endl;
			cout<<"************************************************************"<<endl<<endl;
			gameEnded = true;
		}
		else
		{
			system("pause");
			i= (i+1)%30;
			currentPlayer = ++currentPlayer%nPlayer;//go to the next player
			while (player[currentPlayer].safe) currentPlayer = (currentPlayer+1)%nPlayer;//if that next player is already safe, go to the next one (and so on)
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));//seed random
	printOldMaid();
	cout<<endl<<"                    Let's play Old Maid!"<<endl<<endl;
	int choice=0;
	while (choice!=4)
	{
		cout<<"1. Instruction"<<endl;
		cout<<"2. Start new game"<<endl;
		cout<<"3. Start new game (debug mode)"<<endl;
		cout<<"4. Quit"<<endl;
		cout<<"Please enter your choice: ";
		cin>>choice;
		switch (choice)
		{
		case 1:
			printInstruction();
			cout<<endl<<endl;
			break;
		case 2:
			startGameNormal();
			break;
		case 3:
			startGameDebug();			
			break;
		case 4:
			return 0;
			break;
		default:
			cout<<"Invalid choice!"<<endl<<endl;
			break;
		}
	}

	system("pause");
	return 0;
}



