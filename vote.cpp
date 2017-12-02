#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "pMT.h"
using namespace std;

int main(int argc, char **argv)
{
	ifstream fTwo;
	ifstream fOne;
	string fileName;
	int hash;
	string vote;
	int time;

	// select a hash
	cout << "chose a hash to use" << endl;
	cout << "1. James Hoffman's hash" << endl;
	cout << "2. Damir Pulatov's hash " << endl;
	cout << "3. Jesse Cornejo's hash" << endl;
	cin >> hash;
	if (hash <= 0 || hash >= 4)
	{
		cout << "sorry hash out of range, set to hash #1" << endl;
		hash = 1;
	}

	pMT treeOne = pMT(hash);
	pMT treeTwo = pMT(hash);

	// ask for file name
	cout << "file 1: ";
	getline(cin, fileName);
	fOne.open(fileName);

	//loop untill no fail
	while (fOne.fail())
	{
		cout << "The file could not be opened." << endl;
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		fOne.open(fileName);
	}

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
	cout << number_nodes << endl;

	//close fOne
	fOne.close();
	
	//get second file to read from
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
	getline(fTwo, line);
	
	//Build a new merkel tree 
	while (fTwo.eof() == false)
	{
		fTwo >> vote;
		votes.push_back(vote);

		fTwo >> time;
		timestamps.push_back(time);

		number_nodes++;
	}
	
	// Close fTwo
	fTwo.close();

	// Compare treeOne and treeTwo
	if (treeOne == treeTwo) 
	{
		cout << "Validated" << endl;
	}
	else
	{
		cout << "Not Validatede" << endl;
	}
	int a;
	cin >> a;
	return 0;
}
