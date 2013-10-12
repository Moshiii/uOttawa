#include "stdafx.h"
#include "Classes.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Employee **array = new Employee*[12];
	array[0]= new Clerk("Johnson", "Alan", "Clerk", 25100, "telelphone");
	array[1]= new Engineer("Lockers", "Daniel", "Engineer", 53500, "car");
	array[2]= new Manager("Adamson", "John","Manager",77500,  "meetings", 12);
	array[3]= new Programmer("Newhall", "Bob","Programmer",40000, "c++");
	array[4]= new Clerk("Brown", "James","Clerk",28000, "visitors");
	array[5]= new Accountant("Cheng", "Linda","Accountant",35500, "bonus");
	array[6]= new Programmer ("Lipmann", "Charles","Programmer",45500, "data structure");
	array[7]= new Electrician("Watt", "James","Electrician",30000, "switch");
	array[8]= new Manager("Jones", "Mary","Manager",70500, "hiring",7);
	array[9]= new Programmer("Lockers", "Dennis","Programmer",41000, "hacker hunting");
	array[10]= new Clerk("Green", "Sylvester","Clerk",30000, "documents");
	array[11]= new Scientist("Lubbers", "Pieter","Scientist",60000, "Big Bang", 40);
	for (int i=0; i<12; i++)
	{
		report(*array[i]);
	}
	system("pause");
	return 0;
}

