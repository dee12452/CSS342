#pragma once
#include "Account.h"

class BSTree
{
	struct Node;

public:
	BSTree();
	~BSTree();
	bool Insert(Account *);
	// retrieve object, first parameter is the ID of the account
	// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const int &, Account * &) const;
	// displays the contents of a tree to std::cout
	void Display(ofstream &) const;
	void Empty();
	bool isEmpty() const;
private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
	Node *root;
	bool Insert(Account *, Node *);
	bool Retrieve(const int &, Account * &, Node *) const;
	void Empty(Node *);
	void Display(Node *, ofstream &) const;
};