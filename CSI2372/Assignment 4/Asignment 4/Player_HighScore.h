#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player {
	string name;
	long score;
public:
	Player(string name="", long score=0);
	void setName(string name);
	void setScore(long score);
	string getName() const;
	long getScore() const;
};

class HighScore {
	int nPlayers;     // number of players in HighScore
	static const int size=8;   // (fixed) size of array
	Player players[size];  // Array of player records
public:
	HighScore() : nPlayers (0) {}

	void print() const;

	bool addPlayer(const string& name, long score);

	void removePlayerScores(const string& name);

	void sort();
	void sortAfterRemove();//make all dummy player go to the end

};