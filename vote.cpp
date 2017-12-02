#include <iostream>
#include <fstream>
#include <stdio.h>
#include "pMT.h"
using namespace std;

int main(int argc, char **argv)
{

	//Declaration of needed variables
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
	cout << "2. Sam Goering's hash " << endl;
	cout << "3. Oyedola Ajao's hash" << endl;

	// Get the user's input and pass it into the merkle tree constructor.
	cin >> hash;
	if (hash > 0 && hash < 4){ 
	}
	else {
		cout << "sorry hash out of range, set to hash #1" << endl;
		hash = 1;
	}

	pMT merkleTree = pMT(hash);
	pMT compTree = pMT(hash); //Make the compare tree's hash the same as the origial

	while (fOne.eof() == false)
	{
		fOne >> vote >> time;
		merkleTree.insert(vote, time);
	}
	cout << merkleTree;

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
		//Build a new merkel tree 
		while (fTwo.eof()==false)
		{
			fTwo >> vote >> time;
			compTree.insert(vote, time);
		}
		fOne.close();
		fTwo.close();
		if (merkleTree == compTree) {
			cout << "Validated" << endl;
		}
		else {
			cout << "Not Validatede" << endl;
		}
	//If N was inputed exit program
	fOne.close();
	return 0;
}
