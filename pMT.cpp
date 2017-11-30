#include "pMT.h"

pMT::pMT(int hashSelect)
/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
	// Validate input
	// Default to hash_1
	if (hashSelect >= 1 && hashSelect <= 3)
	{
		hash = hashSelect;
	}
	else
	{
		hash = 1;
	}

}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
    
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
}



string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
}

string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
}

string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
}

bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
}

bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
    
}

pMT pMT::operator ^=(const pMT& lhs, const pMT& rhs)
/**
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
    
}


std::ostream& pMT::operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{
}


pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
{
}
