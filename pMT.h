#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);

	int hash;
    
public:
    pMT(int);
    ~pMT();
    
    
    int insert(string, int);
    
    string locateData(string);
	int find(string vote, int time, int hashSelect);
    int findHash(string);
    
    string locateHash(string);
    

	bool operator==(const pMT& rhs);

	bool operator!=(const pMT& rhs);

	pMT operator^=(const pMT& rhs);
	friend std::ostream& operator<<(std::ostream& out, const pMT& p);
	friend pMT operator ^(const pMT& lhs, const pMT& rhs);

	/*
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
	*/
    
};

