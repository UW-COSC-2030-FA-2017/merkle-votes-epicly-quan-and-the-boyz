#include "pMT.h"
#include <string>

using namespace std;

pMT::pMT(int hashSelect)
/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
	myMerkle.tree = new bTREE::treeNode();
	myMerkle.tree->set_node(false);
	myMerkle.tree->set_empty_data();

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



// We can use postorder traversal 
int pMT::insert(string vote, int time)
/**
* @brief insert a vote and time into a leaf node of tree
* @param vote - a string
* @param time - an int representing the time
* @return the number of operations needed to do the insert, -1 if out of memory
*/

{
	// Subtree to iterate through tree
	int number = myMerkle.insert_leaf(vote, time);
		
	return number;
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

	count = 0;
	count = find_helper(vote, time, hash, myMerkle.tree);
	return count;
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	return myMerkle.find(mhash);
}



int pMT::find_helper(string vote, int time, int hashSelect, bTREE::treeNode* subtree) 
{
	if (subtree != NULL) 
	{
		if (vote == subtree->data && time == subtree->time) 
		{
			return count;
		}
		else 
		{
			if (subtree->left_child != NULL || subtree->right_child != NULL) 
			{
				count = count + (find_helper(vote, time, hashSelect, subtree->left_child) || find_helper(vote, time, hashSelect, subtree->right_child));
				if (count == myMerkle.bTREE::numberOfNodes() - 1) 
				{
					return 0;
				}
				count = 0;
				return count;
			}
		}
	}
}


string pMT::locateData(string vote)
/**
* @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param vote, the data to search for
* @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
*/
{
	return myMerkle.locate(vote);
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	return myMerkle.locate(mhash);
}


string pMT::hash_je(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
//Hash function from Lab09 on hashfunctions
{
	unsigned int hash = 11;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash ^= ((hash << 5) + key[i] + (hash >> 2));
	}

	return to_string(hash);
}



string pMT::hash_da(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
//Hash function from Lab09 on hashfunctions
{
	unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
	unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
	unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
	unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash << OneEighth) + key[i];
		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return to_string(hash);
}


string pMT::hash_ja(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
//Hash function from Lab09 on hashfunctions
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash * seed) + key[i];
	}

	return to_string(hash);
}



bool pMT::operator ==(const pMT& rhs) const
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	return (this->myMerkle == rhs.myMerkle);
}


bool pMT::operator !=(const pMT& rhs) const
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	return (this->myMerkle != rhs.myMerkle);
}


std::ostream& operator<<(std::ostream& out, const pMT& p)
/**
* @brief Print out a tree
* @param out
* @param p
* @return a tree to the screen
*/
{

	if (p.myMerkle.numberOfNodes() == 0)
	{
		out << "Empty";
	}
	else
	{
		out << p.myMerkle;
	}
	return out;
}


pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
* @brief Where do two trees differ
* @param lhs
* @param rhs
* @return a tree comprised of the right hand side tree nodes that are different from the left
*/
{
	// Return NULL if trees are equal
	if (lhs == rhs)
	{
		return NULL;
	}
	else
	{
		return NULL;
	}

	return lhs;
}
