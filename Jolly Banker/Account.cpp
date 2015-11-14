#include "Account.h"

Account::Account()
{
}

Account::Account(int x, const string &f, const string &l)
{
	ID = x;
	firstName = f;
	lastName = l;
	for (int i = 0; i < 10; i++)
	{
		Funds fund;
		fund.subNumber = i;
		switch (i)
		{
		case 0:
			fund.name = "Money Market";
			funds.push_back(fund);
			continue;
		case 1:
			fund.name = "Prime Money Market";
			funds.push_back(fund);
			continue;
		case 2:
			fund.name = "Long-Term Bond";
			funds.push_back(fund);
			continue;
		case 3:
			fund.name = "Short-Term Bond";
			funds.push_back(fund);
			continue;
		case 4:
			fund.name = "500 Index Fund";
			funds.push_back(fund);
			continue;
		case 5:
			fund.name = "Capital Value Fund";
			funds.push_back(fund);
			continue;
		case 6:
			fund.name = "Growth Equity Fund";
			funds.push_back(fund);
			continue;
		case 7:
			fund.name = "Growth Index Fund";
			funds.push_back(fund);
			continue;
		case 8:
			fund.name = "Value Fund";
			funds.push_back(fund);
			continue;
		case 9:
			fund.name = "Value Stock Index";
			funds.push_back(fund);
			continue;
		default:
			continue;
		}
	}
}

Account::~Account()
{
}

const int Account::getID()
{
	return ID;
}

const string Account::getFirstName()
{
	return firstName;
}

const string Account::getLastName()
{
	return lastName;
}

void Account::setID(int x)
{
	ID = x;
}

void Account::setFirstName(const string &f)
{
	firstName = f;
}

void Account::setLastName(const string &l)
{
	lastName = l;
}

ostream& operator<<(ostream& o, const Account& acc)
{
	o << acc.firstName << " " << acc.lastName << " Account ID: " << acc.ID << '\n' << '\n';
	for (int i = 0; i < 10; i++)
	{
		o << "     " << acc.funds[i].name << ": $" << acc.funds[i].money
			<< '\n';
	}
	return o;
}

ofstream& operator<<(ofstream& o, const Funds& f)
{
	if (f.TransactionHistory.size() != 0)
	{
		o << f.name << ": $" << f.money << '\n';
		for (int i = 0; i < f.TransactionHistory.size(); i++)
		{
			o << "   " << f.TransactionHistory[i] << '\n';
		}
		o << '\n';
	}
	return o;
}

ostream& operator<<(ostream& o, const Funds& f)
{
	if (f.TransactionHistory.size() != 0)
	{
		o << f.name << ": $" << f.money << '\n';
		for (int i = 0; i < f.TransactionHistory.size(); i++)
		{
			o << "   " << f.TransactionHistory[i] << '\n';
		}
		o << '\n';
	}
	return o;
}


ofstream& operator<<(ofstream& o, const Account& acc)
{
	o << acc.firstName << " " << acc.lastName << " Account ID: " << acc.ID << '\n' << '\n';
	for (int i = 0; i < 10; i++)
	{
		o << "     " << acc.funds[i].name << ": $" << acc.funds[i].money
			<< '\n';
	}
	return o;
}

void Account::Deposit(int amount, int subAccount)
{
	funds[subAccount].money += amount;
}

bool Account::Withdrawal(int amount, int subAccount)
{
	if (funds[subAccount].money >= amount)
	{
		funds[subAccount].money -= amount;
		return true;
	}
	else
	{
		return false;
	}
}

Funds& Account::getFund(int subNum)
{
	return funds[subNum];
}