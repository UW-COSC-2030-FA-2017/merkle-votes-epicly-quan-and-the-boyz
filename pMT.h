#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;

    
    string hash_je(string);
    string hash_da(string);
    string hash_ja(string);

	int find_helper(string vote, int time, int hashSelect, bTREE::treeNode* subtree);

	int hash;
	int count;
    
public:

	bTREE myMerkle;
    pMT(int);
    ~pMT();
    
    
    int insert(string, int);
    
    string locateData(string);
	int find(string vote, int time, int hashSelect);
    int findHash(string);
    
    string locateHash(string);
    

	bool operator==(const pMT& rhs) const;
	bool operator!=(const pMT& rhs) const;
	friend std::ostream& operator<<(std::ostream& out, const pMT& p);
	pMT operator ^(const pMT& rhs) const;

	//pMT operator^=(const pMT& rhs) const;
};

