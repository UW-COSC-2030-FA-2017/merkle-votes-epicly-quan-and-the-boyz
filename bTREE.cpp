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


// Return queue size
int bTREE::getQueueSize()
{
	return queue_size;
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
	return insert_helper(data, time);
	/*
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
	}*/
}



int bTREE::insert_helper(string data_insert, int time_insert)
{
	// Count number of operations
	int number = 0;

	// Create a new tree and node
	bTREE* new_tree = new bTREE();
	treeNode* new_node = new treeNode();
	
	if (new_tree == NULL || new_node == NULL)
	{
		return -1;
	}

	// Set data
	new_node->set_node();
	new_node->set_data(data_insert, time_insert);

	// Make new tree's root newly set node
	new_tree->tree = new_node;
		

	// If current tree's root is empty, then make node with data its root
	if (tree->data.length() == 0)
	{	
		tree = new_node;
		queue_trees.push(new_tree);
		queue_size++;
		number++;
	}
	// Insert into left subtree if it's empty
	else if (queue_trees.front()->left_subtree == NULL)
	{
		queue_trees.front()->left_subtree = new_tree;
		queue_trees.push(new_tree);
		//left_subtree = new_tree;
		queue_size++;

		number = number + 2;
		tree->is_leaf = false;
	}
	// Insert into right subtree if it's empty
	else if(queue_trees.front()->right_subtree == NULL)
	{ 
		// Make new tree the right subtree of first tree in queue
		queue_trees.front()->right_subtree = new_tree;
		queue_trees.push(new_tree);

		// Remove oldest element of queue so we can keep inserting nodes
		queue_trees.pop();

		number = number + 3;
		tree->is_leaf = false;
	}

	return number;
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