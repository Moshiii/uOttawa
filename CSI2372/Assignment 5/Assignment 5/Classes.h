#pragma once
#include <string>
using namespace std;

class Employee
{
public:
	string surname;
	string first_name;
	double salary;

	Employee();
	Employee(string surname, string first_name, double salary);
	~Employee();
	virtual void print() const= 0;
};

class Clerk : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;

	Clerk(string surname, string first_name, string profession, double salary, string responsibility);
	~Clerk();
	void print() const;

};

class Engineer : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;

	Engineer(string surname, string first_name, string profession, double salary, string responsibility);
	~Engineer();
	void print() const;

};

class Manager : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;
	int num_of_team_members;

	Manager(string surname, string first_name, string profession, double salary, string responsibility, int team);
	~Manager();
	void print() const;
};

class Programmer : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;

	Programmer(string surname, string first_name, string profession, double salary, string responsibility);
	~Programmer();
	void print() const;

};

class Accountant : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;

	Accountant(string surname, string first_name, string profession, double salary, string responsibility);
	~Accountant();
	void print() const;

};

class Electrician : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;

	Electrician(string surname, string first_name, string profession, double salary, string responsibility);
	~Electrician();
	void print() const;

};

class Scientist : public Employee
{
public:
	string description;
	string profession;
	string personalResponsibility;
	int num_of_publications;

	Scientist(string surname, string first_name, string profession, double salary, string responsibility, int num_of_publications);
	~Scientist();
	void print() const;

};

void report(const Employee& foo);
