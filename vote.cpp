#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "pMT.h"
using namespace std;

int main(int argc, char **argv)
{

	// Declaration of needed variables
	ifstream fTwo;
	ifstream fOne;
	string fileName;
	int hash;
	string vote;
	int time;

	// Get file name from the user.
	cout << "file 1: ";
	getline(cin, fileName);
	fOne.open(fileName);

	// If the file name is invalid, loop until valid.
	while (fOne.fail())
	{
		cout << "The file could not be opened." << endl;
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		fOne.open(fileName);
	}

	// Ask the user to select a hash function.
	cout << "chose a hash to use" << endl;
	cout << "1. James Hoffmans hash" << endl;
	cout << "2. Damir Pulatov's hash " << endl;
	cout << "3. Jesse Cornejo's hash" << endl;

	// Get the user's input and pass it into the merkle tree constructor.
	cin >> hash;
	if (hash <=0 || hash >= 4)
	{
		cout << "sorry hash out of range, set to hash #1" << endl;
		hash = 1;
	}

	pMT merkleTree = pMT(hash);
	//pMT compTree = pMT(hash); //Make the compare tree's hash the same as the origial

	// Keep track of number of votes = number of leaves
	int number_nodes = 0;
	string line;
	getline(fOne, line);

	// Store votes and time stamps in vectors
	vector<string> votes;
	vector<int> timestamps;

	while (fOne.eof() == false)
	{
		fOne >> vote;
		votes.push_back(vote);

		fOne >> time;
		timestamps.push_back(time);

		number_nodes++;
	}

	// Here we call function that will create an empty tree with number_nodes of leaves
	// merkleTree.create_tree(number_nodes + 1);

	// A 'for' loop to populate leaves with data
	/*
	for (int i = 0; i < number_nodes; i++)
	{
		merkleTree.insert(votes[i], timestamps[i]);	
	}
	*/

	// merkleTree.insert(vote, time);
	cout << number_nodes << endl;
	//cout << merkleTree;

	//Ask the user if they want to compare the first merkel tree
	// to another tree and the file name
	cout << "file 2: ";
	getline(cin, fileName);
	fTwo.open(fileName);

	while (fTwo.fail())
	{
		cout << "The file could not be opened." << endl;
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		fTwo.open(fileName);
	}



	// Reset number of nodes
	number_nodes = 0;

	// Clear votes and timestamps to reuse it 
	votes.clear();
	timestamps.clear();
	
	//Build a new merkel tree 
	while (fTwo.eof() == false)
	{
		fOne >> vote;
		votes.push_back(vote);

		fOne >> time;
		timestamps.push_back(time);

		number_nodes++;
	}
	
	// Close files
	fOne.close();
	fTwo.close();

	// Compare trees
	/*
	if (merkleTree == compTree) 
	{
		cout << "Validated" << endl;
	}
	else
	{
		cout << "Not Validatede" << endl;
	}
	*/
	//If N was inputed exit program
	fOne.close();
	return 0;
}