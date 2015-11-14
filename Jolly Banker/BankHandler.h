#pragma once
#include "Transaction.h"
class BankHandler
{
public:
	BankHandler();
	BankHandler(const string &);
	~BankHandler();

	bool generateBank(const string &);
	void performTasks(ofstream &);
	void processAccounts(ofstream &);

private:
	queue<Transaction> Tasks;
	BSTree Bank;
	bool hasBank = false;
};

