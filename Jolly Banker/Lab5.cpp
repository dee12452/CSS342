// Lab5.cpp : Defines the entry point for the console application.
//
//No use of precompiled headers for this program
#include "BankHandler.h"

int main(int argc, char* argv[])
{
	int x;
	BankHandler Bank;
	ofstream os;
	os.open("BankTransOut.txt");
	os.clear();
	Bank.performTasks(os);
	Bank.processAccounts(os);
	std::cout << "BankTransOut.txt has been created." << endl;
	os << "BankTransOut.txt has been created." << '\n';
	os.close();
	cin >> x;
	return 1;
}

