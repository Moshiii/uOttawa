#include "StdAfx.h"
#include "Classes.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{
	surname="";
	first_name="";
	salary=0;
}
Employee::Employee(string surname, string first_name, double salary)
{
	this->surname = surname;
	this->first_name = first_name;
	this->salary = salary;
}
Employee::~Employee(void)
{
}

Clerk::Clerk(string surname, string first_name, string profession, double salary, string responsibility) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->salary = salary;
	description = "Clerk task";
}

void Clerk::print() const
{
	cout<<first_name<<" "<<surname<<" is a "<<profession<<", the responsibility is "<<personalResponsibility<<" and the salary is "<<salary<<endl;
}

Engineer::Engineer(string surname, string first_name, string profession, double salary, string responsibility) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->salary = salary;
	description = "Engineer task";
}

void Engineer::print() const
{
	cout<<first_name<<" "<<surname<<" is an "<<profession<<", the responsibility is "<<personalResponsibility<<" and the salary is "<<salary<<endl;
}

Manager::Manager(string surname, string first_name, string profession, double salary, string responsibility, int team) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->num_of_team_members = team;
	this->salary = salary;
	description = "Manager task";
}

void Manager::print() const
{
	cout<<first_name<<" "<<surname<<" is a "<<profession<<", the responsibility is "<<personalResponsibility<<", the salary is "<<salary<<" and has "<<num_of_team_members<<" members on the team"<<endl;

}

Programmer::Programmer(string surname, string first_name, string profession, double salary, string responsibility) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->salary = salary;
	description = "Programmer task";
}

void Programmer::print() const
{
	cout<<first_name<<" "<<surname<<" is a "<<profession<<", the responsibility is "<<personalResponsibility<<" and the salary is "<<salary<<endl;
}

Accountant::Accountant(string surname, string first_name, string profession, double salary, string responsibility) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->salary = salary;
	description = "Accountant task";
}

void Accountant::print() const
{
	cout<<first_name<<" "<<surname<<" is an "<<profession<<", the responsibility is "<<personalResponsibility<<" and the salary is "<<salary<<endl;
}

Electrician::Electrician(string surname, string first_name, string profession, double salary, string responsibility) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->salary = salary;
	description = "Electrician task";
}

void Electrician::print() const
{
	cout<<first_name<<" "<<surname<<" is an "<<profession<<", the responsibility is "<<personalResponsibility<<" and the salary is "<<salary<<endl;
}

Scientist::Scientist(string surname, string first_name, string profession, double salary, string responsibility, int num_of_publications) : Employee(surname,first_name,salary)
{
	this->profession=profession;
	this->personalResponsibility=responsibility;
	this->num_of_publications=num_of_publications;
	this->salary = salary;
	description = "Scientist task";
}

void Scientist::print() const
{
	cout<<first_name<<" "<<surname<<" is a "<<profession<<", the responsibility is "<<personalResponsibility<<", the salary is "<<salary<<" and has "<<num_of_publications<<" publications"<<endl;
}

void report(const Employee& foo)
{
	foo.print();
}