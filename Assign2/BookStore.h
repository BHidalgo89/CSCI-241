#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include "Book.h"
#include <string>
//**************************************************************************
//	FILE:		Bookstore.h
//	Author:		Branden Hidalgo
//	LOGON ID:	z1663752
//	DUE DATE:	03/13/18
//
//	PURPOSE:	Contains the declaration for the Bookstore class.
//**************************************************************************
//using std::string;
class BookStore
	{
	//  Data Members
	private:

		Book bookSpace[30];
		int  numBooks = 0;

	public:

		BookStore();
		BookStore(const std::string&);
		void print();
		void sortByISBN();
		int searchForISBN(char*);
		void processOrders(const std::string&);

		};

#endif
