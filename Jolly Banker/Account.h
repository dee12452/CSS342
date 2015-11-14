#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Funds
{
	string name;
	int money = 0;
	int subNumber;
	vector<string> TransactionHistory;
};

class Account
{
	friend ostream& operator<<(ostream& o, const Account& acc);
	friend ostream& operator<<(ostream& o, const Funds&);
	friend ofstream& operator<<(ofstream& o, const Funds& f);
	friend ofstream& operator<<(ofstream& o, const Account& acc);

public:
	Account();
	Account(int, const string &, const string &);
	~Account();

	const int getID();
	void setID(int);

	const string getFirstName();
	void setFirstName(const string &);

	const string getLastName();
	void setLastName(const string &);

	const int getMoney();
	void Deposit(int, int);
	bool Withdrawal(int, int);

	Funds& getFund(int);

private:
	int ID;
	string firstName;
	string lastName;
	vector<Funds> funds;
};

