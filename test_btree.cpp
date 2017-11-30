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
	cout << "Number of nodes - " << test_tree.numberOfNodes() << endl;;
	cout << endl;

	cout << "Testing dataInserted() function" << endl;
	cout << "Number of nodes with data - " << test_tree.dataInserted() << endl;
	cout << endl;

	// Test insert() function
	cout << "Testing insert(string, int) function" << endl;
	cout << "Inserting 'c' - ";
	test_tree.insert("c", 10) ? (cout << "success!") : (cout << "failure!");
	cout << endl;
	
	cout << "Inserting 'b' - ";
	test_tree.insert("b", 20) ? (cout << "success!") : (cout << "failure!");
	cout << endl;

	cout << "Inserting 'd' - ";
	test_tree.insert("d", 30) ? (cout << "success!") : (cout << "failure!");
	cout << endl;

	cout << "Inserting 'a' - ";
	test_tree.insert("a", 40) ? (cout << "success!") : (cout << "failure!");
	cout << endl;
	cout << endl;

	cout << "Number of nodes - " << test_tree.numberOfNodes() << endl;


	cout << "Number of nodes with data - " << test_tree.dataInserted() << endl;
	cout << endl;

	cout << "Testing find(string) function" << endl;
	// Should return true (1)
	cout << "Finding 'a' - ";
	test_tree.find("a") == true ? (cout << "found!") : (cout << "not found!");
	cout << endl;

	cout << "Finding 'Damir' - ";
	test_tree.find("Damir") == true ? (cout << "found!") : (cout << "not found!");
	cout << endl;
	cout << endl;

	// Testing locate(string) function
	// Should return R
	cout << "Testing locate(string) function" << endl;
	cout << "Path for 'd' - " << test_tree.locate("d") << endl;
	cout << "Path for 'a' - " << test_tree.locate("a") << endl;
	cout << "Path for 'something' - " << test_tree.locate("something") << endl;
	cout << "Path for 'c' - " << test_tree.locate("c") << endl;
	cout << endl;


	bTREE test_tree2;
	// Testing << operator
	cout << "Testing overloaded << operator" << endl;
	cout << "Printing test_tree - " << test_tree << endl;
	cout << "Printing test-tree2 - " << test_tree2 << endl;
	cout << endl;


	// Testing == and !=
	cout << "Testing overloaded operators == and !=" << endl;
	cout << "test_tree == test_tree2 - ";
	(test_tree == test_tree2) ? (cout << "true") : (cout << "false");
	cout << endl;

	cout << "test_tree != test_tree2 - ";
	(test_tree != test_tree2) ? (cout << "true") : (cout << "false");
	cout << endl;

	bTREE test_tree3;
	test_tree3.insert("c", 10);
	test_tree3.insert("b", 20);
	test_tree3.insert("d", 30);
	test_tree3.insert("a", 40);
	cout << "test_tree == test_tree3 (copy of test_tree) - ";
	(test_tree == test_tree3) ? (cout << "true") : (cout << "false");
	cout << endl;

	cout << "test_tree != test_tree3 (copy of test_tree) - ";
	(test_tree != test_tree3) ? (cout << "true") : (cout << "false");
	cout << endl;
	
	return 0;
}