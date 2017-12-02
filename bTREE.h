#pragma once
#include <string>
#include <vector>
#include "stack.h"

using namespace std;

class bTREE
{
public:
	struct treeNode
	{
		string data;
		int time;

		// Variable to differentiable if node if leaf
		bool is_leaf;

		// Pointers to right and left children
		treeNode* right_child;
		treeNode* left_child;

		// Function to set node
		void set_node(bool leaf = true)
		{
			is_leaf = leaf;
			right_child = NULL;
			left_child = NULL;
		}

		void set_empty_data()
		{
			data = "";
		}

		// Sets data
		void set_data(string new_data, int new_time)
		{
			data = new_data;
			time = new_time;
		}
	};


	int insert_leaf(string, int);
	

	treeNode* tree = NULL;
    
private:

	// Pointer to treeNode
	int postorder_insert(string, int, treeNode*);
	int insert_leaf_helper(string, int);

	int dataInserted_helper(treeNode*);
	int size(treeNode* tree) const;

	treeNode* insert_helper(string, int, treeNode*);
	
	bool find_helper(string, treeNode*);

	bool locate_helper(string, treeNode*, vector<string>&, string);

	void preorder(vector<string>& traversal, const treeNode* subtree) const;

    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    
public:

	bTREE();
    ~bTREE();
    
	// What is it supposed to do?
    int dataInserted();
    int numberOfNodes() const;
    
    bool insert(string, int);
    
    bool find(string);
    
    string locate(string);
	    
	bool is_same(treeNode* lhs, treeNode* rhs) const;
	treeNode* not_same_nodes(treeNode* lhs, treeNode* rhs) const;

	// Set root of tree
	void set_root(string, int);

    bool operator==(const bTREE& rhs) const;
	bool operator!=(const bTREE& rhs) const;

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

