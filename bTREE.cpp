#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	// Construct root
	tree = NULL;
	
	/*new treeNode();

	// Default values
	tree->is_leaf = true;
	tree->right_child = NULL;
	tree->left_child = NULL;
	tree->time = 0;
	tree->data = "";
	*/
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
	// 
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

	// Call helper function insertPrivate()
	return insertPrivate(data, time);
}


int bTREE::insertPrivate(string data_insert, int time_insert)
{
	// Subtree to iterate through tree
	treeNode* subtree = tree;

	// Count number of operations
	int number = 0;

	// Call constructor if tree is empty
	if (tree == NULL)
	{
		tree = new treeNode();
		tree->set_data(data_insert, time_insert);
	}
	else
	{
		// Insert data into leaf
		// Iterate through tree 
		while (subtree != NULL)
		{
			// Go left, if data is less than root's data
			if (data_insert <= tree->data)
			{
				// Make node non leaf
				subtree->is_leaf = false;
				subtree = subtree->left_child;
				number++;
			}
			else
			{
				subtree->is_leaf = false;
				subtree = subtree->right_child;
				number++;
			}
		}


		// Make new node

		subtree = new treeNode();

		if (subtree != NULL)
		{
			subtree->set_data(data_insert, time_insert);
			number++;
		}
		else
		{
			number = -1;
		}

		
		/*
		// Insert if node created
		else
		{

			// Insert time and data
			treeNode* temp = new treeNode();

			temp->data = data_insert;
			temp->time = time_insert;
			temp->is_leaf = true;
		
			// Insert new node
			subtree->is_leaf = true;

			subtree = temp;
			

			// Insert left if less
			if (data_insert <= subtree->data)
			{
				subtree->left_child = temp;
			}
			else
			{
				subtree->right_child = temp;
			}
			
			number++;
		}
		
		
		else
		{
			// Return -1 if out of memory
			number = -1;
		}
		*/
	}
	

	return number;

}

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
