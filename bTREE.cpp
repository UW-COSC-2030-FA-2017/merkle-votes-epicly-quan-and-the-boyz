#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	// Construct root
	tree = new treeNode();
	tree->time = 0;
	tree->data = "";
	
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
	
	return -1;
}


int bTREE::numberOfNodes()
{
	// Call private size() function
	return size(tree);
}

int bTREE::size(treeNode* tree)
{

	// Store size number
	int size_tree = 0;

	// If node is empty, return zero for size
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		// If node is not empty, add one to size
		// Find size of left and rigth subtrees of node
		size_tree = 1 + size(tree->left_child) + size(tree->right_child);
	}

	return size_tree;
}

int bTREE::insert(string data, int time)
{
	// Call helper function insert_helper()
	return insert_helper(data, time);
}


// Insert data and time into binary tree
// Return number of operations for insertion
int bTREE::insert_helper(string data_insert, int time_insert)
{
	// Count number of operations
	int number = 0;

	// Keep track of subtree
	treeNode* subtree = tree;

	// Insert if root's data is empty
	if (subtree->data.length() == 0)
	{
		subtree->set_data(data_insert, time_insert);
		number++;
	}
	else
	{
		// Count for comparing with root
		number++;

		// Iterate through tree
		while (subtree != NULL)
		{
			// Reset leaf to false
			subtree->is_leaf = false;

			// Insert in left child if empty
			if (subtree->left_child == NULL)
			{
				subtree->left_child = new treeNode();
				subtree->left_child->set_data(data_insert, time_insert);
				number++;
				break;
			}
			// Insert in right child if empty
			else if(subtree->right_child == NULL)
			{
				subtree->right_child = new treeNode();
				subtree->right_child->set_data(data_insert, time_insert);
				number++;
				break;
			}

			// Go to left child by default
			subtree = subtree->left_child;
			number++;
		}
	}


	return number;
}

// Binary search tree (NOT what we need)
/*
int bTREE::insert_helper(string data_insert, int time_insert)
{
	// Count number of operations
	int number = 0;

	treeNode* subtree = tree;
	treeNode* prevNode = NULL;

	// Insert at root, if empty
	if (subtree->data.length() == 0)
	{
		subtree->set_data(data_insert, time_insert);
		number++;
	}
	else
	{
		// Iterate through tree
		while (subtree != NULL)
		{
			subtree->is_leaf = false;
			prevNode = subtree;
			if (data_insert <= subtree->data)
			{
				subtree = subtree->left_child;
			}
			else
			{
				subtree = subtree->right_child;
			}
			number++;
		}

		// Create new leaf
		if (data_insert <= prevNode->data)
		{
			prevNode->left_child = new treeNode();
			prevNode->left_child->set_data(data_insert, time_insert);
		}
		else
		{
			prevNode->right_child = new treeNode();
			prevNode->right_child->set_data(data_insert, time_insert);
		}
		number++;
	}


	return number;
}
*/

// Insert data and time into binary tree using recursion
/*
int bTREE::insert_helper(string data_insert, int time_insert, treeNode* prevNode,  treeNode* subtree)
{
	// Count number of operations
	int number = 0;

	// Base case for recursion
	// Create leaf with data and time
	if (subtree == NULL)
	{
		treeNode* subtree = new treeNode();

		// Check if node was not created
		if (subtree == NULL)
		{
			return -1;
		}
		else
		{
			subtree->set_data(data_insert, time_insert);

			if (data_insert <= prevNode->data)
			{
				prevNode->left_child = subtree;
			}
			else
			{
				prevNode->right_child = subtree;
			}
			return 1;
		}
	}
	else if (subtree != NULL && subtree->data.length() == 0)
	{
		// Case when root is empty
		subtree->data = data_insert;
		subtree->time = time_insert;
		return 1;
	}
	else
	{
		// Insert data into leaf
		// Iterate through tree 
		if (data_insert <= tree->data)
		{
			// Call function recursively and pass left child
			subtree->is_leaf = false;
			number = 1 + insert_helper(data_insert, time_insert, subtree, subtree->left_child);
		}
		else
		{
			subtree->is_leaf = false;
			number = 1 + insert_helper(data_insert, time_insert, subtree, subtree->right_child);
		}
	}

	return number;
}
*/

int bTREE::find(string)
{
	// Stub
	return -1;
}

string bTREE::locate(string search_string)
{
	// Stub
	return "string";
}

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	// Stub
	return true;
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	// Stub
	return true;
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	// Stub
	return out;
}
