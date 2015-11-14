#include "BSTree.h"


BSTree::BSTree()
{
}


BSTree::~BSTree()
{
}

bool BSTree::Insert(Account *insert)
{
	if (root != NULL)
	{
		return Insert(insert, root);
	}
	else
	{
		root = new Node;
		root->pAcct = insert;
		root->left = NULL;
		root->right = NULL;
	}
}

bool BSTree::Insert(Account *insert, Node *leaf)
{
	if (insert->getID() < leaf->pAcct->getID())
	{
		if (leaf->left != NULL)
		{
			Insert(insert, leaf->left);
		}
		else
		{
			leaf->left = new Node;
			leaf->left->pAcct = insert;
			leaf->left->left = NULL;   
			leaf->left->right = NULL;   
			return true;
		}
	}
	else if (insert->getID() >= leaf->pAcct->getID())
	{
		if (leaf->right != NULL)
		{
			Insert(insert, leaf->right);
		}
		else
		{
			leaf->right = new Node;
			leaf->right->pAcct = insert;
			leaf->right->left = NULL; 
			leaf->right->right = NULL; 
			return true;
		}
	}
}

bool BSTree::Retrieve(const int &accNum, Account * &acc) const
{
	return Retrieve(accNum, acc, root);
}

bool BSTree::Retrieve(const int &accNum, Account * &acc, Node *leaf) const
{

	if (leaf != NULL)
	{
		if (accNum == leaf->pAcct->getID())
		{
			acc = leaf->pAcct;
			return true;
		}
		if (accNum < leaf->pAcct->getID())
		{
			Retrieve(accNum, acc, leaf->left);
		}
		else
		{
			Retrieve(accNum, acc, leaf->right);
		}
	}
	else
	{
		return false;
	}
}

bool BSTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BSTree::Empty()
{
	Empty(root);
	root = NULL;
}

void BSTree::Empty(Node *leaf)
{
	if (isEmpty())
	{
		std::cerr << "No information in system" << endl;
		return;
	}
	if (leaf != NULL)
	{
		Empty(leaf->left);
		Empty(leaf->right);
		delete leaf;
	}
}

void BSTree::Display(ofstream &os) const
{
	Display(root, os);
}

void BSTree::Display(Node *leaf, ofstream &o) const
{
	if (isEmpty())
	{
		std::cerr << "ERROR: No accounts created" << '\n' << '\n';
		o << "ERROR: No accounts created" << '\n' << '\n';
		return;
	}
	if (leaf != NULL)
	{
		std::cout << *leaf->pAcct << '\n' << '\n';
		o << *leaf->pAcct << '\n' << '\n';
		Display(leaf->left, o);
		Display(leaf->right, o);
	}
}

