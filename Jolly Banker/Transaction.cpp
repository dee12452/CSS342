#include "Transaction.h"

Transaction::Transaction()
{

}

Transaction::Transaction(string line)
{
	type = line[0];
	if (type == 'O') //Open account
	{
		action = line.substr(2, line.size() - 2);
	}
	else if (type == 'D') //Depos, std::coutit money
	{
		action = line.substr(2, line.size() - 2);
	}
	else if (type == 'W') //Withdraw money
	{
		action = line.substr(2, line.size() - 2);
	}
	else if (type == 'T') //Transfer
	{
		action = line.substr(2, line.size() - 2);
	}
	else if (type == 'H') //H?
	{
		action = line.substr(2, line.size() - 2);
	}
	else
	{
		int x;
		type = 'E';
		std::cerr << "Error in file or file not found, closing program after you enter a character." << endl;
		cin >> x;
		exit(EXIT_FAILURE);
		return;
	}
}


Transaction::~Transaction()
{
}

const string Transaction::getAction()
{
	return action;
}

const char Transaction::getType()
{
	return type;
}