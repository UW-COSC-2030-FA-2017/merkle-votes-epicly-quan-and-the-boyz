// Node.h
// Damir Pulatov, Jesse Cornejo, James Hoffman
// 10/02/2017
// Nodes for linked list

#ifndef NODE_H
#define NODE_H

template<class Object>
class Node
{
public:
	Node(Object entry, Node *next);
	Node(Object entry);
	~Node();

	// Fields 

	// Store data
	Object data;

	// Point to next and previous nodes
	Node *next;
	Node *prev;

};


// Constructor for Node class
// Accept data and next node
template<class Object>
Node<Object>::Node(Object entry, Node *nextNode)
{
	data = entry;
	next = nextNode;
}


// Another contructor for Node class
// Accept data and assumes next node points to NULL
template <class Object>
Node<Object>::Node(Object entry)
{
	data = entry;
	next = NULL;

}


// Destructor for Node class
template<class Object>
Node<Object>::~Node()
{
	// Ask about destructor

	next = NULL;
	prev = NULL;

}



#endif