// stack.h
// Damir Pulatov, Jesse Cornejo, James Hoffman
// 10/02/2017
// COSC 2030
// List implementation of stack
// The contract is taken from course slides


#ifndef STACK
#define STACK

#include"list.h"

template<class Object>
class Stack
{
public:
	Stack();
	~Stack();
	void push(Object data);
	bool pop();
	Object* top();
	void clear();
	bool isEmpty();

private:
	LinkedList<Object> list;
	
};


// Constructor for StackList class
template<class Object>
Stack<Object>::Stack()
{
	// Initialize an empty list
	LinkedList<Object> list;

}


// Destructor for StackList class
template<class Object>
Stack<Object>::~Stack()
{
	list.makeEmpty();
}


// Push element at the end of stack
template<class Object>
void Stack<Object>::push(Object data)
{
	// Call insertFirst() method in LinkedList class
	list.insertFirst(data);
}


// Pop last element of stack
template <class Object>
bool Stack<Object>::pop()
{
	// Remove first element of list
	return list.removeFirst();
}


// Peek into top of stack
template <class Object>
Object* Stack<Object>::top()
{

	if (!isEmpty())
	{
		return list.peekFirst();
	}
	else
	{
		return NULL;
	}

}


// Clear stack
// Make head of list point to NULL
// Is there a better way?
template<class Object>
void Stack<Object>::clear()
{
	list.makeEmpty();
	return;
}


// Check if stack is empty
template<class Object>
bool Stack<Object>::isEmpty()
{
	return list.isEmpty();
}






#endif