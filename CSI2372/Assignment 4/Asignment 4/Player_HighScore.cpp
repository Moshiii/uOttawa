#include "StdAfx.h"
#include "Player_HighScore.h"

Player::Player(string name, long score){
	this->name=name;
	this->score=score;
}

void Player::setName(string name){
	this->name=name;
}
void Player::setScore(long score){
	this->score=score;
}
string Player::getName() const{
	return name;
}
long Player::getScore() const{
	return score;
}


void HighScore::print() const {
	for (int i=0; i< nPlayers; i++)
		cout << "#" << i << ": " << players[i].getScore()
		<< " " << players[i].getName() << endl;
}

bool HighScore::addPlayer(const string& name, long score) {
	// New score must be inserted at its correct position.
	// The player record with the lowest score is dropped
	// when the array overflows. Returns true if the new
	// player has been added to the high score list

	Player p(name, score);

	if (nPlayers == size) {
		if (p.getScore() <	players[nPlayers-1].getScore())
			return false;
		else {
			players[nPlayers-1]= p;
			sort();
			return true;
		}
	}
	if (nPlayers==0) {
		players[0]= p;
		nPlayers++;
		return true;
	}
	players[nPlayers]=p;
	nPlayers++;
	sort();
	return true;
}

void HighScore::sort(){
	for (int i=0;i<size;i++)
		if (players[i].getName()=="") continue;//dummy player? if yes move on
		else
			for (int j=0;j<size;j++)
				if (players[j].getName()=="") continue;//dummy player? if yes move on
				else
				{
					if (players[i].getScore()>players[j].getScore()){
						Player temp = players[i];
						players[i] = players [j];
						players[j] = temp;
					}
				}
}

void HighScore::sortAfterRemove(){//make all dummy player go to the end
	for (int i=0; i<size-1;i++)
	{		
		int count = 0;
		while (players[i].getName()==""){

			for (int j=i; j<size-1;j++)
			{
				players[j]=players[j+1];
			}
			Player temp;
			players[size-1] = temp;
			count++;
			if (count==size) break;
		}
	}
}

void HighScore::removePlayerScores(const string& name){
	int temp = nPlayers;
	for (int i=0; i<temp;i++)
	{
		if (players[i].getName()==name)
		{
			Player temp2;
			players[i] = temp2;//replace with dummy player
			nPlayers--;
		}
	}
	sortAfterRemove();
}