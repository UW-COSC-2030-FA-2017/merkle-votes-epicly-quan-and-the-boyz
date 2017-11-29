# MerkleVotes

Merkle Is Voting - And it's going to be epic.

This homework counts for your 4th 5th and 6th homeworks.

## Part One
1. Implement a binary tree (NOT a search tree)
2. Nodes must -
  * hold a pseudo-time stamp (integer, non-unique)[5]
  * hold a 128 bit data component (string of 32 characters)[5]
  * have 2 pointers to type node [5]
  * be differentiable if they are a leaf node or not [5]
3. A bTREE.h file and bTREE.cpp file are included but are incomplete
4. Complete the functions required [30]
  * Add any additional functions that might want

## Part Two
1. Use the binary tree created in part one to implement a pseudo-MerkleTree Class
2. Your Merkle Trees have some special properties:
  * Manually inserted data can only exist as leaf nodes
  * Non-Leaf nodes are the hashes of the child nodes below them
  * Our nodes should be ordered by a 'fake' time stamp
3. You must create at least 3 types of hash functions each group memeber is responsible for at least one
  * (they are listed at hash_1, hash_2 and hash_3).
4. pMT.h and pMT.cpp are provided but incomplete
5. Complete the functions provided [30]

### Individual Submission
1. Compute the number of operations it takes to:
  * Insert a new data node [4]
  * Recompute hashes upon entry of a new node [4]
  * Compare if two trees are identical [4]
  *  Determine where two trees differ [4]
2. Describe your hash function in detail [4]

Submit your answers on WyoCourses

## Part Three
1. Create a vote.cc with a main function that stores 'time stamped' votes into your pmTree data structure
2. Vote Data will be a string in the following format RANDOM:CANDIDATE
3. You will be provided with sample voterFiles.
4. Your program should be able to:
  * Read in a single file with timestamped votes and output the value of the root node 
  * Read in two sets of time stamped vote files, and:
  * If identical, print "Validated"
  * If not identical, print the sub-trees that differ, along with the offending vote data 

## Final Project (more details forthcoming)
Create a poster using the template provided, describing your design decisions, lessons learned, future extension ideas, ...
Poster will be due at the time of final code submission

You must change this readme file to contain the names of your group members as well as the mathematical functions you have each implemented for your hash functions.




int bTREE::insertPrivate(string data_insert, int time_insert)
{
	// Subtree to iterate through tree
	treeNode* subtree = tree;

	// Count number of operations (starts at 2 because it will always get entered and will be checked at least once.)
	int number = 2;

	// Call constructor if tree is empty
	if (tree == NULL){
		tree = new treeNode();
		tree->set_data(data_insert, time_insert);
		tree->left_child = NULL;
		tree->right_child = NULL;
		//this is because there is no check
		number--;
	}
	else{
		// Insert data into leaf
		// Iterate through tree 
		while (subtree != NULL){
			// Go left, if data is less than root's data
			if (data_insert <= tree->data){
				if (subtree->left_child == NULL) {
					subtree->is_leaf = false;
					subtree = subtree->left_child;
					number++;
				}
				else {
					subtree->left_child = new treeNode();
					subtree->left_child->set_data(data_insert, time_insert);
					subtree->left_child->is_leaf = false;
					subtree->left_child->right_child = NULL;
					subtree->left_child->left_child = NULL;
					subtree = subtree->left_child->left_child;
				}
			}
			else{
				if (subtree->right_child != NULL) {
					subtree->is_leaf = false;
					subtree = subtree->right_child;
					number++;
				}
				else {
					subtree->right_child = new treeNode();
					subtree->right_child->set_data(data_insert, time_insert);
					subtree->right_child->is_leaf = false;
					subtree->right_child->right_child = NULL;
					subtree->right_child->left_child = NULL;
					subtree = subtree->right_child->right_child;
				}
			}
		}
	}
	return number;
}