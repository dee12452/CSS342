#pragma once
#include "BSTree.h"
class Transaction
{
public:
	Transaction();
	Transaction(string);
	~Transaction();

	const string getAction();
	const char getType();
private:
	char type;
	string action;
};

