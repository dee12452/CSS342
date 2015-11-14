#include "BankHandler.h"
#include <sstream>

BankHandler::BankHandler()
{
	if (generateBank("BankTransIn.txt"))
	{
		//std::cout << "Bank has been created" << endl;
		hasBank = true;
	}
	else
	{
		//std::cout << "Failed to create a bank" << endl;
		hasBank = false;
	}
}

BankHandler::BankHandler(const string &fileName)
{
	if (generateBank(fileName))
	{
		//std::cout << "Bank has been created" << endl;
		hasBank = true;
	}
	else
	{
		//std::cout << "Failed to create a bank" << endl;
		hasBank = false;
	}
}

BankHandler::~BankHandler()
{
}

bool BankHandler::generateBank(const string &fileName)
{
	ifstream f;
	char in[100];
	f.open(fileName, ios::in);
	while (!f.eof())
	{
		f.getline(in, 100);
		string insert = in;
		Transaction trans(insert);
		Tasks.push(trans);
	}
	return true;
}



void BankHandler::performTasks(ofstream &os)
{
	while (Tasks.size() != 0)
	{
		Transaction t = Tasks.front();
		string action = t.getAction();
		Tasks.pop();

		////////////////////////////////
		// CODE FOR OPENING AN ACCOUNT//
		////////////////////////////////

		if (t.getType() == 'O')
		{
			int accNum = 0;
			bool one = true, two = true;
			string firstName = "", lastName = "", number = "";
			for (int i = 0; i < t.getAction().size(); i++)
			{
				if (t.getAction()[i] == ' ')
				{
					if (one)
					{
						one = false;
						continue;
					}
					if (two)
					{
						two = false;
						continue;
					}
					else
					{
						istringstream buffer(number);
						buffer >> accNum;
					}
				}
				if (one)
				{
					lastName.push_back(t.getAction()[i]);
					continue;
				}
				else if (two)
				{
					firstName.push_back(t.getAction()[i]);
					continue;
				}
				else
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
			}
			if (number == "")
			{
				for (int i = 5; i > -1; i--)
				{
					number.push_back(t.getAction()[t.getAction().size() - i]);
				}
			}
			istringstream buffer(number);
			buffer >> accNum;
			if (accNum > 9999 || accNum < 1000)
			{
				std::cerr << "ERROR: The Account number " << accNum <<
					" is either too large or too small to create."
					<< " Account numbers must be between 1000 and 9999" <<
					'\n';
				os << "ERROR: The Account number " << accNum <<
					" is either too large or too small to create."
					<< " Account numbers must be between 1000 and 9999" <<
					'\n';
				continue;
			}
			Account *insertion;
			if (Bank.Retrieve(accNum, insertion))
			{
				//std::cout << "Error, account already exists!" << endl;
				std::cerr << "ERROR: Account " << accNum << " is already open. Transaction refused."
					<< '\n' << '\n';
				os << "ERROR: Account " << accNum << " is already open. Transaction refused."
					<< '\n' << '\n';
				insertion = NULL;
				delete insertion;
			}
			else
			{
				insertion = new Account(accNum, firstName, lastName);
				Bank.Insert(insertion);
				//std::cout << "Account creation successful!" << endl;
			}
		}

		////////////////////////////////
		// CODE FOR MAKING A TRANSFER///
		////////////////////////////////

		if (t.getType() == 'T')
		{
			string number = "";
			int accNum1 = 0, amount = 0, accNum2 = 0, index = 0, accSub1;
			bool one = true, two = true;
			for (int i = 0; i < t.getAction().size(); i++)
			{
				if (t.getAction()[i] == ' ')
				{
					if (one)
					{
						accSub1 = ((int)number[number.size() - 1] - 48);
						number.pop_back();
						istringstream buffer(number);
						buffer >> accNum1;
						one = false;
						index = 0;
						number = "";
					}
					else
					{
						istringstream buffer(number);
						buffer >> amount;
						two = false;
						index = 0;
						number = "";
					}
					continue;
				}
				if (one)
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
				else if (two)
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
				else
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
			}
			if (number == "")
			{
				for (int i = 6; i > -1; i--)
				{
					number.push_back(t.getAction()[t.getAction().size() - i]);
				}
			}
			while (number.size() > 5)
			{
				number.pop_back();
			}
			int accSub2 = ((int)number[number.size() - 1] - 48);
			number.pop_back();
			istringstream buffer(number);
			buffer >> accNum2;
			Account *acc1, *acc2;
			if (Bank.Retrieve(accNum1, acc1) && Bank.Retrieve(accNum2, acc2))
			{
				if (acc1->Withdrawal(amount, accSub1))
				{
					acc2->Deposit(amount, accSub2);
					acc1->getFund(accSub1).TransactionHistory.push_back("T " + t.getAction());
					acc2->getFund(accSub2).TransactionHistory.push_back("T " + t.getAction());
					acc2 = NULL; acc1 = NULL;
					delete acc2, acc1;
				}
				else
				{
					std::cerr << "ERROR: Not enough funds to withdraw " << amount
						<< " from " << acc1->getFirstName() << " " << 
						acc1->getLastName() << " " << acc1->getFund(accSub1).name
						<< '\n' << '\n';
					os << "ERROR: Not enough funds to withdraw " << amount
						<< " from " << acc1->getFirstName() << " " <<
						acc1->getLastName() << " " << acc1->getFund(accSub1).name
						<< '\n' << '\n';
					acc1->getFund(accSub1).TransactionHistory.push_back("T " + t.getAction() + " (Failed)");
					acc2->getFund(accSub2).TransactionHistory.push_back("T " + t.getAction() + " (Failed)");
					acc2 = NULL; acc1 = NULL;
					acc2 = NULL; acc1 = NULL;
					delete acc2, acc1;
				}
			}
			else
			{
				if (!Bank.Retrieve(accNum1, acc1) && Bank.Retrieve(accNum2, acc2))
				{
					std::cerr << "ERROR: Accounts " << accNum1 << " and " <<
						accNum2 << " not found. Transferral refused." << '\n' << '\n';
					os << "ERROR: Accounts " << accNum1 << " and " <<
						accNum2 << " not found. Transferral refused." << '\n' << '\n';
				}
				else if (!Bank.Retrieve(accNum1, acc1))
				{
					std::cerr << "ERROR: Account " << accNum1 <<
					 " not found. Transferral refused." << '\n' << '\n';
					os << "ERROR: Account " << accNum1 <<
						" not found. Transferral refused." << '\n' << '\n';
					acc2 = NULL;
					delete acc2;
				}
				else
				{
					std::cerr << "ERROR: Account " << accNum2 <<
						" not found. Transferal refused." << '\n' << '\n';
					os << "ERROR: Account " << accNum2 <<
						" not found. Transferral refused." << '\n' << '\n';
					acc1 = NULL;
					delete acc1;
				}
				
			}
		}


		///////////////////////////////////////////////
		// CODE FOR OPENING AN WITHDRAWS AND DEPos, std::coutITS//
		///////////////////////////////////////////////


		if (t.getType() == 'W' || t.getType() == 'D')
		{
			string number = "";
			bool one = true;
			int accNum, amount, index = 0, accSubNum;
			for (int i = 0; i < t.getAction().size(); i++)
			{
				if (t.getAction()[i] == ' ')
				{
					if (one)
					{
						char c = number[number.size() - 1];
						accSubNum = ((int)number[number.size() - 1] - 48);
						number.pop_back();
						istringstream buffer(number);
						buffer >> accNum;
						one = false;
						number = "";
					}
				}
				if (one)
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
				else
				{
					number.push_back(t.getAction()[i]);
					continue;
				}
			}
			istringstream buffer(number);
			buffer >> amount;
			Account *acc;
			if (t.getType() == 'W')
			{
				if (Bank.Retrieve(accNum, acc))
				{
					if (acc->Withdrawal(amount, accSubNum))
					{
						acc->getFund(accSubNum).TransactionHistory.push_back("W " + t.getAction());
						acc = NULL;
						delete acc;
					}
					else
					{
						std::cerr << "ERROR: Not enough funds to withdraw " << amount
							<< " from " << acc->getFirstName() << " " <<
							acc->getLastName() << " " << acc->getFund(accSubNum).name
							<< '\n' << '\n';
						os << "ERROR: Not enough funds to withdraw " << amount
							<< " from " << acc->getFirstName() << " " <<
							acc->getLastName() << " " << acc->getFund(accSubNum).name
							<< '\n' << '\n';
						acc->getFund(accSubNum).TransactionHistory.push_back("W " + t.getAction() + " (Failed)");
					}
				}
				else
				{
					std::cerr << "ERROR: Account " << accNum << " not found."
						<< "Transaction refused." << '\n' << '\n';
					os << "ERROR: Account " << accNum << " not found."
						<< "Transaction refused." << '\n' << '\n';
				}
			}
			else
			{
				if (Bank.Retrieve(accNum, acc))
				{
					acc->getFund(accSubNum).TransactionHistory.push_back("D " + t.getAction());
					acc->Deposit(amount, accSubNum);
					acc = NULL;
					delete acc;
				}
				else
				{
					std::cerr << "ERROR: Account " << accNum << " not found."
						<< "Transaction refused." << '\n' << '\n';
					os << "ERROR: Account " << accNum << " not found."
						<< "Transaction refused." << '\n' << '\n';
				}
			}
		}
		
		/////////////////////////////////////////////
		// CODE FOR PRINTING HISTORY FOR AN ACCOUNT//
		/////////////////////////////////////////////

		if (t.getType() == 'H')
		{
			string number;
			int accNum = 0;
			for (int i = 0; i < t.getAction().size(); i++)
			{
				if (t.getAction()[i] == ' ')
				{
					continue;
				}
				number.push_back(t.getAction()[i]);
			}
			if (number.size() > 4)
			{
				int numSub = ((int)number.back() - 48);
				number.pop_back();
				istringstream buffer(number);
				buffer >> accNum;
				Account *acc;
				if (Bank.Retrieve(accNum, acc))
				{
					std::cout << "Transaction History for " << acc->getFirstName()
						<< " " << acc->getLastName() << " " <<
						acc->getFund(numSub).name << ": $" << 
						acc->getFund(numSub).money << '\n';
					os << "Transaction History for " << acc->getFirstName()
						<< " " << acc->getLastName() << " " <<
						acc->getFund(numSub).name << ": $" <<
						acc->getFund(numSub).money << '\n';
					for (int i = 0; i < acc->getFund(numSub).TransactionHistory.size(); i++)
					{
						std::cout << "   " << acc->getFund(numSub).TransactionHistory[i] << '\n' << '\n';
						os << "   " << acc->getFund(numSub).TransactionHistory[i] << '\n' << '\n';
					}
					acc = NULL;
					delete acc;
					continue;
				}
				else
				{
					std::cerr << "ERROR: Account " << accNum << " not found. History refused." << '\n' << '\n';
					os << "ERROR: Account " << accNum << " not found. History refused." << '\n' << '\n';
					continue;
				}
			}
			istringstream buffer(number);
			buffer >> accNum;
			Account *acc;
			if (Bank.Retrieve(accNum, acc))
			{
				std::cout << "Transaction History for " << acc->getFirstName()
					<< " " << acc->getLastName() << " by fund." << '\n' << '\n';
				os << "Transaction History for " << acc->getFirstName()
					<< " " << acc->getLastName() << " by fund." << '\n' << '\n';
				for (int i = 0; i < 10; i++)
				{
					std::cout << acc->getFund(i);
					os << acc->getFund(i);
				}
				acc = NULL;
				delete acc;
			}
			else
			{
				std::cerr << "ERROR: Account " << accNum << " not found. History refused." << '\n' << '\n';
				os << "ERROR: Account " << accNum << " not found. History refused." << '\n' << '\n';
			}
		}
	}
}

void BankHandler::processAccounts(ofstream &os)
{
	std::cout << '\n' << '\n';
	os << '\n' << '\n';
	std::cout << "Processing Done. Final Balances" << '\n' << '\n';
	os << "Processing Done. Final Balances" << '\n' << '\n';
	Bank.Display(os);
}