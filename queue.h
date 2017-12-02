// queue.h
// Damir Pulatov, Jesse Cornejo, James Hoffman
// COSC 2030 
// 10/05/2017
// Implementation of Queues with linked lists

#ifndef QUEUE
#define QUEUE

#include"list.h"

template<class Object>
class Queue
{
public:
	Queue();
	~Queue();

	// Insert a new element on the rear
	void enqueue(Object elemenet);

	// Remove from the front
	bool dequeue();

	bool isEmpty();

	// Add top method that returs first element in queue
	Object* top();

private:
	LinkedList<Object> list;

};


// Constructor for Queue
// Initialize both front and rear to NULL
template<class Object>
Queue<Object>::Queue()
{
	LinkedList<Object> list;

}


// Destructor for Queue
template<class Object>
Queue<Object>::~Queue()
{

	list.makeEmpty();

}


// Add element on the rear of queue
template<class Object>
void Queue<Object>::enqueue(Object element)
{
	list.insertLast(element);
}



// Remove element from front
template<class Object>
bool Queue<Object>::dequeue()
{
	return list.removeFirst();

}


// Return first element in queue
template<class Object>
Object* Queue<Object>::top()
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


// Check if queue is empty
template<class Object>
bool Queue<Object>::isEmpty()
{

	return list.isEmpty();

}



#endif