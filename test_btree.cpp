// test_btree.cpp
// November 11, 2017
// Damir Pulatov
// Test Binary Tree implemented in bTREE.h and bTREE.cpp



#include "bTREE.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{

	// Test constructor
	bTREE test_tree;

	// Test numberOfNodes() function
	// Should be 1 by default (root only)
	cout << "Testing numberOfNodes() function" << endl;
	cout << test_tree.numberOfNodes() << endl;
	cout << endl;

	cout << "Testing dataInserted() function" << endl;
	cout << test_tree.dataInserted() << endl;
	cout << endl;

	// Test insert() function
	cout << "Testing insert(string, int) function" << endl;
	cout << test_tree.insert("c", 10) << endl;
	cout << endl;

	cout << test_tree.insert("b", 20) << endl;
	cout << endl;

	cout << test_tree.insert("d", 30) << endl;
	cout << endl;

	cout << test_tree.insert("a", 40) << endl;
	cout << endl;


	cout << "Counting size" << endl;
	cout << test_tree.numberOfNodes() << endl;
	cout << endl;


	cout << "Testing dataInserted() function" << endl;
	cout << test_tree.dataInserted() << endl;
	cout << endl;

	cout << "Testing find(string) function" << endl;
	// Should return true (1)
	cout << test_tree.find("a") << endl;
	// Should return false (0)
	cout << test_tree.find("Damir") << endl;
	cout << endl;


	// Testing locate(string) function
	// Should return R
	cout << "Testing locate(string) function" << endl;
	cout << test_tree.locate("d") << endl;
	cout << endl;

	cout << test_tree.locate("a") << endl;
	cout << endl;


	cout << "Testing is_same() function" << endl;
	bTREE test_tree2;
	//test_tree.is_same(test_tree, test_tree2);
	

	return 0;
}