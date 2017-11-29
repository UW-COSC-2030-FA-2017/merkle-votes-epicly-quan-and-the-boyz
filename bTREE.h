#pragma once
#include <string>

using namespace std;

class bTREE
{
    struct treeNode
	{
        string data;
        int time;

		// Variable to differentiable if node if leaf
		bool is_leaf;

		// Pointers to right and left children
		treeNode* right_child;
		treeNode* left_child;

		// Constructor for treeNode struct
		treeNode(bool new_leaf = true)
		{
			is_leaf = new_leaf;
			right_child = NULL;
			left_child = NULL;
		}

		// Sets data
		void set_data(string new_data, int new_time)
		{
			data = new_data;
			time = new_time;
		}
    };
    
private:

	// Pointer to treeNode
	treeNode* tree = NULL;

	int dataInserted_helper(treeNode*);
	int size(treeNode* tree);

	int insert_helper(string, int);
	
	int findPrivate(string);

	string locatePrivate(string);

	

	
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    
public:
    bTREE();
    ~bTREE();
    
	// What is it supposed to do?
    int dataInserted();
    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string);


    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);


	bool is_same(treeNode* lhs, treeNode* rhs);
    
};

