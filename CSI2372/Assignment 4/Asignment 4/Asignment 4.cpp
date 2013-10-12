#include "stdafx.h"
#include <iostream>
#include "Player_HighScore.h"
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HighScore table;
	for (;;)
	{
		cout<<"Input 'a' to add a player/score, 'r' to remove a player or 'x' to exit: "<<endl;
		char choice;
		cin>>choice;
		switch (choice)
		{
		case 'a':
			{
				cout<<"Please enter player name: "<<endl;
				string name;
				cin>>name;
				cout<<"Please enter the score: "<<endl;
				long score;
				cin>>score;
				bool added = table.addPlayer(name,score);
				if (added)
				{
					cout<<"Highscore: "<<endl;
					table.print();
					cout<<endl;
				} 
				else cout<<"New score not added! "<<endl<<endl;
			}
			break;
		case 'r':
			{
				cout<<"Please enter player name: "<<endl;
				string name;
				cin>>name;
				table.removePlayerScores(name);
				cout<<"Highscore: "<<endl;
				table.print();
				cout<<endl;
			}
			break;
		case 'x':
			return 0;
		default:
			cout<<"Invalid choice"<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}

