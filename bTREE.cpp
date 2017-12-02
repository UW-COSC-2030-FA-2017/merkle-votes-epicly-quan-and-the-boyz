#include "bTREE.h"
#include <iostream>

using namespace std;


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	// Construct root
	tree = NULL;	
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
	treeNode* subtree = tree;
	return dataInserted_helper(subtree);
}


// Count number of data nodes inserted into tree with recursion
int bTREE::dataInserted_helper(treeNode* subtree)
{

	// Store number of inserted nodes
	int number_inserted = 0;

	// If node is empty, return zero for size
	if (subtree == NULL)
	{
		return 0;
	}
	else
	{
		// If node is not empty, add one to number of nodes
		// Find number data nodes of left and rigth subtrees of node
		number_inserted = 1 + dataInserted_helper(subtree->left_child) + dataInserted_helper(subtree->right_child);
	}

	return number_inserted;
}


int bTREE::numberOfNodes() const
{
	// Call private size() function
	return size(tree);
}

int bTREE::size(treeNode* tree) const
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

bool bTREE::insert(string data, int time)
{
	// Call helper function insert_helper()
	treeNode* leaf = insert_helper(data, time, tree);

	// If tree is empty, insert in root
	if (tree == NULL && leaf != NULL)
	{
		tree = leaf;
		return true;
	}
	else if(tree != NULL && leaf != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// Insert data and time into binary tree
// Return true/false for success/failure
bTREE::treeNode* bTREE::insert_helper(string data_insert, int time_insert, treeNode* subtree)
{

	// Insert if node is empty
	if (subtree == NULL)
	{
		//subtree = new treeNode();
		subtree = new treeNode();
		subtree->set_node(true);
		subtree->set_data(data_insert, time_insert);
		return subtree;
	}
	else
	{
		// Insert in left child if empty
		subtree->is_leaf = false;
		if (subtree->left_child == NULL)
		{
			subtree->left_child = insert_helper(data_insert, time_insert, subtree->left_child);
		}
		else
		{
			subtree->right_child = insert_helper(data_insert, time_insert, subtree->right_child);
		}
	}
	return subtree;
}


// Insert into leaf of binary tree
int bTREE::insert_leaf(string vote, int time)
{
	return insert_leaf_helper(vote, time);
}


int bTREE::insert_leaf_helper(string vote, int time)
{

	// Stack to keep track of paths 
	Stack<treeNode*> path;
	int number = 0;

	treeNode* subtree = tree;
	
	// Search for leaf where we can insert data
	while (subtree->is_leaf == false && subtree->data.length() == 0)
	{
		if (subtree != NULL && subtree->left_child != NULL)
		{
			subtree = subtree->left_child;
			path.push(subtree);
			number++;
		}
		else if (subtree != NULL && subtree->right_child != NULL)
		{
			subtree = subtree->right_child;
			path.push(subtree);
			number++;
		}
		else if (subtree != NULL && subtree->data.length() > 0)
		{
			subtree = *path.top();
			path.pop();
			number++;
		}
	}

	
	// Insert data
	if (subtree != NULL && subtree->is_leaf == true && subtree->data.length() == 0)
	{
		subtree->set_data(vote, time);
		number++;
	}

	return number;
}


/*
// Do postorder traversal to find leaf and insert into it
int bTREE::postorder_insert(string vote, int time, treeNode* subtree)
{

	int number = 0;
	// Iterate through tree and find leftmost leaf
	if (subtree->is_leaf == false)
	{

		number = number + postorder_insert(vote, time, subtree->left_child);
		postorder_insert(vote, time, subtree->right_child);

	}
	else
	{
		// Create temp treeNode to store data in
		subtree->set_data(vote, time);
		return 1;
	}


	return;

	*/


void bTREE::set_root(string data_hash, int time_set)
{

	// Set root, if empty
	if (tree != NULL)
	{
		tree->data = data_hash;
		tree->time = time_set;
	}
	
	return;
}




// Find data within tree
// If found return 
bool bTREE::find(string data_find)
{
	// Call helper function
	return find_helper(data_find, tree);
}


// Helper function for find(string)
// Implemented with recursion
bool bTREE::find_helper(string data_find, treeNode* subtree)
{
	
	// Check if subtree is empty
	// Base case for recursion
	if (subtree == NULL)
	{
		return false;
	}
	// Check if subtree's data is data_find
	// Return 1 if it is
	else if (subtree->data == data_find)
	{
		return true;
	}
	// If data not found yet, keep looking
	else
	{
		return (find_helper(data_find, subtree->left_child) || find_helper(data_find, subtree->right_child));
	}
}



// Return path to locate node with data
string bTREE::locate(string data_find)
{
	// Create vector to store path
	vector<string> path;

	// If there is path to node with data, print it
	if (locate_helper(data_find, tree, path, ""))
	{
		string path_string;

		// Iterate through vector and store path as one string
		for (int i = 0; i < path.size(); i++)
		{
			// Append directions into one string
			path_string.append(path[i]);
		}
		
		// Return root if data located in root
		return (path_string.empty() ? ("Root") : (path_string));
	}
	else
	{
		return "No Path (data not found)";
	}


}


// Helper function for locate(string)
// Inspired by:
// http://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
bool bTREE::locate_helper(string data_find, treeNode* subtree, vector<string>& path, string direction)
{
	// Return false if node is empty
	if (subtree == NULL)
	{
		return false;
	}

	// Push direction (left/right) into path vector
	path.push_back(direction);

	
	// Return true if data is found in node
	if (subtree->data == data_find)
	{
		return true;
	}

	// Visit left and right children 
	if (locate_helper(data_find, subtree->left_child, path, "L") || locate_helper(data_find, subtree->right_child, path, "R"))
	{
		return true;
	}

	// Pop out of vector if this path led to empty node
	// And return false to indicate that
	path.pop_back();

	return false;
}


// Compare two trees
bool bTREE::operator ==(const bTREE& rhs) const
{
	// Set is_equal to true by default
	// Call is_same() helper function
	return is_same(this->tree, rhs.tree);

}

bool bTREE::operator !=( const bTREE& rhs) const
{
	// Call helper function
	return !is_same(this->tree, rhs.tree);
}

// Checks if two trees are same
// Two trees are same if they have the same data, time stamps and structure
// Implemented with recursion
bool bTREE::is_same(treeNode* lhs, treeNode* rhs) const
{
	// If both trees are empty, they are same
	if (lhs == NULL && rhs == NULL)
	{
		return true;
	}
	// Both are non empty check data and time
	// Call function recursively with left and right children
	else if (lhs != NULL && rhs != NULL)
	{
		return (lhs->data == rhs->data) && is_same(lhs->left_child, rhs->left_child) && is_same(lhs->right_child, rhs->right_child);
	}
	else
	{
		return false;
	}

}


// Return tree composed of nodes that are different in lhs and rhs
bTREE::treeNode* bTREE::not_same_nodes(treeNode* lhs, treeNode* rhs) const
{

	return NULL;

}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	// Check tree's size
	if (p.numberOfNodes() == 0)
	{
		out << "Empty";
	}
	else
	{
		vector<string> traversal;
		p.preorder(traversal, p.tree);

		for (int i = 0; i < traversal.size(); i++)
		{
			out << traversal[i];
		}
	}
	
	return out;
}


// Helper function for preoder traversal
void bTREE::preorder(vector<string>& traversal, const treeNode* subtree) const
{
	if (subtree != NULL)
	{
		traversal.push_back(subtree->data);
		preorder(traversal, subtree->left_child);
		preorder(traversal, subtree->right_child);
	}

}