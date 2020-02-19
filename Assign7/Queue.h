/*****************************************************************************
	PROGRAM:	Assignment 7

	PROGRAMMER:	Branden Hidalgo

	FILE:		Queue.h

	DATE DUE:

	PURPOSE:	Creates and implements a class to represent the Queue
			ADT using a singly linked list
*****************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
using std::out_of_range;
using std::underflow_error;

template <class T>
struct Node
{
   T value;
   Node<T>* next;
   Node(const T& = T(), Node<T>* next = nullptr);
};


template <class T>
class Queue;


template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);


template <class T>
class Queue
{
   friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

private:

       Node<T>* qFront;
       Node<T>* qBack;
       size_t qSize;

public:
     Queue();
     ~Queue();
     Queue(const Queue<T>&);
     Queue<T>& operator=(const Queue<T>&);
     void clear();
     void copyList(const Queue<T>&);
     size_t size() const;
     bool empty() const;
     const T& front() const;
     const T& back() const;
     void push(const T&);
     void pop();
};


/***************************************************************************************

	Queue template method definitions

***************************************************************************************/

/*********************************************************************************
	FUNCTION:	Node(const T&);

	ARGUMENTS:	A constant reference to an item of the template parameter
			type

	RETURNS:	N/A

	PURPOSE:	Constructor copies argument into the queue node and sets
			the node's pointer to nullptr

	NOTES:		Node struct constructor
*********************************************************************************/
template <class T>
Node<T>::Node(const T& newVal, Node<T>* newNext)
   {
   value = newVal;
   next = newNext;
   }


/**************************************************************************************
	FUNCTION:	Queue()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Constructor sets pointer data members to nullptr and queue size
			to 0

	NOTES:		Queue method
***************************************************************************************/
template <class T>
Queue<T>::Queue()
   {
   qFront = nullptr;
   qBack = nullptr;
   qSize = 0;
   }

/***************************************************************************************
	FUNCTION:	~Queue()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Destructor delets the dynamic memory for the queue array

	NOTES:		Queue method
*********************************************************************************/
template <class T>
Queue<T>::~Queue()
   {
   clear();
   }

/**************************************************************************************
	FUNCTION:	Queue(const Queue<T>& other)

	ARGUMENTS:	A reference to a constant Queue object

	RETURNS:	N/A

	PURPOSE:	Copy constructor initializes a new Queue object to the same
			capacity and array contents as the existing Queue object

	NOTES:		Queue method
*********************************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
   {
   qFront = qBack = nullptr;
   qSize = 0;
   copyList(other);
   }

/*********************************************************************************
	FUNCTION:	Queue<T>& operator=(const Queue<T>&)

	ARGUMENTS:	A reference to a constant Queue objecct

	RETURNS:        A reference to a constant Queue object

	PURPOSE:        Overloaded copy assignment operator assigns a Queue
			object to another Queue object and deletes the Queue
			array for the object pointed to by this

	NOTES:		Queue method
********************************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
   {
   if(this != &other)
     {
     clear();
     copyList(other);
     }
   return *this;
   }

/*********************************************************************************
	FUNCTION:	void clear()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Deletes all nodes in the queue, setting it
			to an empty state

	NOTES:		Queue method
*********************************************************************************/
template <class T>
void Queue<T>::clear()
   {
   qSize = 0;
   qFront = nullptr;
   qBack = nullptr;
   }

/*****************************************************************************
	FUNCTION:	size_t size() const

	ARGUMENTS:	N/A

	RETURNS:	A size_t value

	PURPOSE:	Returns the number of data items currently stored in the
			queue

	NOTES:		Queue method
*****************************************************************************/
template <class T>
size_t Queue<T>::size() const
   {
   return qSize;
   }

/********************************************************************************
	FUNCTION:	bool empty() const

	ARGUMENTS:	N/A

	RETURNS:	A boolean value

	PURPOSE:	Tells the user if a queue is empty or not

	NOTES:		Queue method
*********************************************************************************/
template <class T>
bool Queue<T>::empty() const
   {
   if(qSize == 0)
     return true;
   else
     return false;
   }

/********************************************************************************
	FUNCTION:	const T& front() const

	ARGUMENTS:	N/A

	RETURNS:	A reference to a constant item of the template parameter
			type

	PURPOSE:	Returns the data storeed in the front node of the queue
			unless the queue is empty. In which case the method
			throws an underflow_error exception

	NOTES:		Constant Queue method
*********************************************************************************/
template <class T>
const T& Queue<T>::front() const
   {
   if (empty())
     {
     throw underflow_error("Exception: Queue underflow on front()");
     }
   else
     {
     return qFront->value;
     }
   }

/********************************************************************************
	FUNCTION:	const T& back() const

	ARGUMENTS:	N/A

	RETURNS:	A reference to a constant item of the template parameter
			type

	PURPOSE:	Returns the data stored in the back node of the queue
			unless the queue is empty. In which case, the method
			throws an underflow error exception

	NOTES:		Constant Queue method
*********************************************************************************/
template <class T>
const T& Queue<T>::back() const
   {
   if(qSize == 0)
     {
     throw underflow_error("Exception: Queue underflow on back()");
     }
   else
     {
     return qBack->value;
     }
   }

/********************************************************************************
	FUNCTION:	void push(const T&)

	ARGUMENTS:	A reference to a constant item of the template parameter
			type

	RETURNS:	N/A

	PURPOSE:	Inserts an item at the back of the queue and increments
			the queue size unless the queue is empty. In which case,
			the method throws an underflow error exception

	NOTES:		Queue method
*********************************************************************************/
template <class T>
void Queue<T>::push(const T& val)
   {
   Node<T>* newNode = new Node<T>(val);

   if(empty())
     {
     qFront = newNode;
     }
   else
     {
     qBack->next = newNode;
     }

   qBack = newNode;
   ++qSize;
   }

/********************************************************************************
	FUNCTION:	void pop()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Removes the item stored at the front of the and decrements
			the size of the queue unless the queue is empty. In which
			case, the method throws an underflow error exception

	NOTES:		Queue method
*********************************************************************************/
template <class T>
void Queue<T>::pop()
   {
   if(empty())
     {
     throw underflow_error("Exception: underflow on pop()");
     }

   Node<T>* tempNode = qFront;
   qFront = qFront->next;

   if(qFront == nullptr)
     qBack = nullptr;

   delete tempNode;
   --qSize;
   }

/********************************************************************************
	FUNCTION:	friend ostream& operator<<(ostream&, const Queue<T>&)

	ARGUMENTS:	A reference to an ostream object and a reference to a
			constant Queue object

	RETURNS:	A reference to an ostream object

	PURPOSE:	Inserion operattor allows a Queue object to be sent to the
			standard output

	NOTES:		friend function to the Queue class
*********************************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& output, const Queue<T>& rhs)
   {
   Node<T>* ptr;


   for(ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
     {
     output << ptr->value << ' ';
     }

   return output;
   }

/********************************************************************************
	FUNCTION:	void copyList(const Queue<T>& other)

	ARGUMENTS:	A reference to a constant Queue<T> object

	RETURNS:	N/A

	PURPOSE:	Copies the linked list from one Queue<T> object to another

	NOTES:		Queue method
********************************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
   {
   Node<T>* ptr;

   for(ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
     push(ptr->value);
   }

#endif /* QUEUE_H */
