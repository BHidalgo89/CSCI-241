//**********************************************************************************************
//		FILE:		Queue.h
//
//		PROGRAMMER:	Branden Hidalgo
//
//		LOGON ID: 	Z1663752
//
//		DUE DATE:
//
//		PURPOSE:	Create and implement a class to represent the Qeue ADT using an
//				array
//*********************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::underflow_error;
using std::cout;
using std::endl;
using std::out_of_range;
using std::ostream;

//****************************************************************************
//
// Queue template class definition
//
//****************************************************************************/
template <class Q>
class Queue;

template <class Q>
ostream& operator<<(ostream&, const Queue<Q>&);

template <class Q>
class Queue

   {
   friend ostream& operator<< <>(ostream&, const Queue<Q>&);

   private:

     Q* qArray;
     size_t qSize, qCapacity;
     int qFront, qBack;

   public:

     Queue();
     ~Queue();
     Queue(const Queue<Q>&);
     Queue& operator=(const Queue<Q>&);
     void clear();
     size_t size() const;
     size_t capacity() const;
     bool empty() const;
     const Q& front() const;
     const Q& back() const;
     void push(const Q&);
     void pop();
     void reserve(size_t);
     };

//********************************************************************************
//
// Queue template class method definitions
//
//*******************************************************************************


/********************************************************************************
	FUNCTION:	Queue()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Default constructor initializes the data members of the
			Queue class to 0 and nullptr

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
Queue<Q>::Queue()
   {
   qArray = nullptr;
   qCapacity = 0;
   qSize = 0;
   qFront = 0;
   qBack = qCapacity - 1;
   }


/*********************************************************************************
	FUNCTION:	~Queue()

	ARGUMENTS:	N/A

	RETURNS: 	N/A

	PURPOSE:	Destructor deletes the dynamic memory for the queue array

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
Queue<Q>::~Queue()
   {
   delete[] qArray;
   }


/*********************************************************************************
	FUNCTION:	Queue(const Queue<Q>&)

	ARGUMENTS:	A reference to a constant Queue object

	RETURNS:	N/A

	PURPOSE:	Copy constructor initializes a new Queue object to the
			same capacity and array contents as the existing Queue
			object

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
Queue<Q>::Queue(const Queue<Q>& other)
   {
   qCapacity = other.qCapacity;
   qSize = other.qSize;
   if(qCapacity == 0)
     {
     qArray = nullptr;
     }
   else
     {
     qArray = new Q[qCapacity];
     for(size_t i = 0; i < qCapacity; i++)
       {
       qArray[i] = other.qArray[i];
       }
     qFront = other.qFront;
     qBack = other.qBack;
     }
   }

/*********************************************************************************
	FUNCTION:	Queue<Q>& operator=(const Queue<Q>&)

	ARGUMENTS:	A reference to a constant Queue object

	RETURNS:	A reference to a constant Queue object

	PURPOSE:	Overloaded copy assignment operator assigns a Queue object
			to another Queue object and deletes the queue array for
			the object pointed to by this

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
Queue<Q>& Queue<Q>::operator=(const Queue<Q>& other)
   {
   if(this != &other)
     {
     delete[] qArray;
     qCapacity = other.qCapacity;
     qSize = other.qSize;

     if(qCapacity == 0)
       {
       qArray = nullptr;
       }
     else
       {
       qArray = new Q[qCapacity];
       }
     for(size_t i = 0; i < qCapacity; i++)
       {
       qArray[i] = other.qArray[i];
       }

     qFront = other.qFront;
     qBack = other.qBack;
     }
    return *this;
   }

/*********************************************************************************
	FUNCTION: 	friend ostream& operator<<(ostream&, const Queue<Q>&)

	ARGUMENTS:	A reference to an ostream object and a reference to a
			constant Queue object

	RETURNS:	A reference to an ostream object

	PURPOSE:	Insetrion operator allows a Queue objec to be sent to the
			standard output

	NOTES:		A friend function to the Queue class
*********************************************************************************/
template <class Q>
ostream& operator<<(std::ostream& output, const Queue<Q>& rhs)
   {
   size_t current, i;
   for(current = rhs.qFront, i = 0; i < rhs.qSize; i++)
     {
     output << rhs.qArray[current] << ' ';
     current = (current + 1) % rhs.qCapacity;
     }
   return output;
   }


/********************************************************************************
	FUNCTION:	void clear();

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Sets the queue back to the empty state

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
void Queue<Q>::clear()
   {
   qSize = 0;
   qFront = 0;
   qBack = qCapacity - 1;
   }

/*********************************************************************************
	FUNCTION:	size_t size() const

	ARGUMENTS:	N/A

	RETURNS:	A size_t value

	PURPOSE: 	Returns the queue size

	NOTES:		Constant Queue method
*********************************************************************************/
template <class Q>
size_t Queue<Q>::size() const
   {
   return qSize;
   }


/*********************************************************************************
	FUNCTION:	size_t capacity() const

	ARGUMENTS:	N/A

	RETURNS:	A size_t value

	PURPOSE:	Returns the queue capacity

	NOTES:		Constant Queue method
*********************************************************************************/
template <class Q>
size_t Queue<Q>::capacity() const
   {
   return qCapacity;
   }

/*********************************************************************************
	FUNCTION:	bool empty() const

	ARGUMENTS:	N/A

	RETURNS: 	A boolean value

	PURPOSE:	Determines if a queue array is empty

	NOTES:		Constant Queue method
*********************************************************************************/
template <class Q>
bool Queue<Q>::empty() const
   {
   if(qSize == 0)
     {
     return true;
     }
   else
     {
     return false;
     }
   }

/*********************************************************************************
	FUNCTION:	const Q& front() const;

	ARGUMENTS:	N/A

	RETURNS:	A reference to a constant item of the Q template parameter
			type

	PURPOSE:	Returns the front element of a queue array

	NOTES:		Constant Queue method
*********************************************************************************/
template <class Q>
const Q& Queue<Q>::front() const
   {
   if(qSize == 0)
     {
     throw underflow_error("queue underflow on front()");
     }
   else
     {
     return qArray[qFront];
     }
   }

/*********************************************************************************
	FUNCTION:	const Q& back() const

	ARGUMENTS:	N/A

	RETURNS:	A reference to a constant item of the Q template parameter
			type

	PURPOSE:	Returns the back element of the queue array

	NOTES:		Constant Queue method
*********************************************************************************/
template <class Q>
const Q& Queue<Q>::back() const
   {
   if(qSize == 0)
     {
     throw underflow_error("queue underflow on back()");
     }
   else
     {
     return qArray[qBack];
     }
   }


/*********************************************************************************
	FUNCTION:	void push(const Q&)

	ARGUMENTS:	A reference to a constant item of the Q template parameter
			type

	RETURNS:	N/A

	PURPOSE:	Inserts a new item at the back of the queue

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
void Queue<Q>::push(const Q& val)
   {
   if (qSize == qCapacity)
     {
     if(qCapacity == 0)
       {
       reserve(1);
       }
     else
       {
       reserve(2*qCapacity);
       }
     }
  qBack = (qBack +1) % qCapacity;
  qArray[qBack] = val;
  ++qSize;

  }

/*********************************************************************************
	FUNCTION:	void pop()

	ARGUMENTS:	N/A

	RETURNS:	N/A

	PURPOSE:	Removes the front item from the queue

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
void Queue<Q>::pop()
   {
   if(empty())
     {
     throw underflow_error("queue underflow on pop()");
     }

   qFront = (qFront + 1) % qCapacity;
   --qSize;
   }

/*********************************************************************************
	FUNCTION:	void reserve(size_t)

	ARGUMENTS:	A size_t value

	RETURNS:	N/A

	PURPOSE:	Allocates a new capacity for a queue

	NOTES:		Queue method
*********************************************************************************/
template <class Q>
void Queue<Q>::reserve(size_t newCap)
   {
   if(newCap < qSize || newCap == qCapacity)
     return;

     Q* tempArray = new Q[newCap];

     int current = qFront;
     for(size_t i = 0; i < qSize; i++)
       {
       tempArray[i] = qArray[current];
       current = (current + 1) % qCapacity;
       }


   qCapacity = newCap;
   qFront = 0;
   qBack = qSize - 1;
   delete[] qArray;
   qArray = tempArray;
   }

#endif

