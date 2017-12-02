// list.h
// Damir Pulatov, Jesse Cornejo, James Hoffman
// 10/04/2017
// Linked list class to use for stack.h


#ifndef LIST
#define LIST


#include <iostream>
using namespace std;

#include"node.h"

template<class Object>
class LinkedList
{
public:
	LinkedList();

	~LinkedList();
	void insertLast(Object element);
	void insertFirst(Object element);
	bool removeLast();
	bool removeFirst();
	Object* peekFirst();
	Object* peekLast();
	bool isEmpty() const;
	void makeEmpty();

	// Method to test elements
	void print() const;

	// Can also overload << operator

private:
	// Keep track of both head and tail nodes for queues
	Node<Object> *head;
	Node<Object> *tail;

};


// Constructor for LinkedList class
template<class Object>
LinkedList<Object>::LinkedList()
{
	head = NULL;
	tail = NULL;
}


// Destructor for LinkedList class
// Inspired by: http://faculty.lasierra.edu/~ehwang/courses/cptg122/Notes/Linked%20List%20Destructor.pdf
// Point head and tail to NULL to make list O(1)
template<class Object>
LinkedList<Object>::~LinkedList()
{

	makeEmpty();

}


// Check if list is empty
// If head points to NULL, list is empty
template <class Object>
bool LinkedList<Object>::isEmpty() const
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}



// Insert an element at the end of list
template<class Object>
void LinkedList<Object>::insertLast(Object element)
{

	// Create new node to insert
	Node<Object> *tmp = new Node<Object>(element);
	if (!isEmpty())
	{

		// Insert node after current tail and update tail
		tmp->next = NULL;
		tail->next = tmp;
		tmp->prev = tail;
		tail = tail->next;
		
	}
	else
	{
		// If list is empty, make head and tail equal to new node
		// Point tail to NULL
		head = tmp;
		head->prev = NULL;
		head->next = NULL;

		tail = tmp;
	}

	return;
}


// Insert an element at the beginning of stack
template<class Object>
void LinkedList<Object>::insertFirst(Object element)
{
	// If list is empty, store element as head
	// Otherwise, insert a new node before head
	if (isEmpty())
	{
		head = new Node<Object>(element);
		head->next = NULL;
		head->prev = NULL;

		tail = head;
	}
	else
	{
		// Create a new node
		// Point new head's prev to NULL
		// Point old head's prev to new head
		// Point new head's next to old head
		// Update head
		Node<Object> *newHead = new Node<Object>(element);
		newHead->prev = NULL;
		head->prev = newHead;
		newHead->next = head;
		head = head->prev;
		
	}

	return;
}


// Remove last element of list
// Return true if removed successfully
// Return false if not
template<class Object>
bool LinkedList<Object>::removeLast()
{
	// Check if list is empty
	if (!isEmpty())
	{

		// Check if there is more than one element in list
		// If only one element in list
		// Make head and tail NULL
		if (head == tail)
		{
			Node <Object>* tmp = head;
			head = NULL;
			tail = NULL;
			delete tmp;
		}
		else
		{
			// If more than one element, update tail
			Node<Object>* tmp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete tmp;

		}
		return true;
	}
	else
	{
		return false;
	}

}


// Remove a node from the beginning
// Return true if removed successfully
// Return false if not
// Delete old head?
template <class Object>
bool LinkedList<Object>::removeFirst()
{

	// Delete first node if list is not empty
	if (!isEmpty())
	{
		// If there is more than one node
		// Update heads
		if (head != tail)
		{
			Node<Object>* tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else
		{
			// If there is only one node
			// Make head and tail NULL
			// Delete old head
			Node <Object>* tmp = head;
			head = NULL;
			tail = NULL;
			delete tmp;
		}
		return true;
	}
	else
	{
		return false;
	}



}


// Return element from head of list
template<class Object>
Object* LinkedList<Object>::peekFirst()
{
	// Return head's data if list is not empty
	// Return NULL if list is empty
	if (!isEmpty())
	{
		return &(head->data);
	}
	else
	{
		return NULL;
	}

}


// Return element from tail of list
template<class Object>
Object* LinkedList<Object>::peekLast()
{

	// Return last element if list is not empty
	// Return tail's data if tail is not NULL
	// Return head's data if tail is NULL
	// Return NULL if list is empty
	if (!isEmpty())
	{
		if (tail != NULL)
		{
			return &(tail->data);
		}
		else
		{
			return &(head->data);
		}
	}
	else
	{
		return NULL;
	}


}


// Print method to test results
template<class Object>
void LinkedList<Object>::print() const
{

	// Check if list is empty
	if (!isEmpty())
	{
		cout << head->data;
		Node<Object> *tmp = head->next;

		// Iterate through list and put every element into outfile
		while (tmp != NULL)
		{
			cout << ", " << tmp->data;
			tmp = tmp->next;
		}

	}

	return;
}


// Make list empty by making head point to NULL
// Erase nodes to make list empty?
template <class Object>
void LinkedList<Object>::makeEmpty()
{
	head = NULL;
	tail = NULL;
	return;
}


#endif