#ifndef BOOK_H
#define BOOK_H

//**************************************************************************************
//	FILE:		Book.h
//	AUTHOR:		Branden Hidalgo
//	LOGON ID:	z1663752
//	DUE DATE:	02/13/18
//
//	PURPOSE:	Contains the declaration for the Book class.
//***************************************************************************************/

class Book
	{
	// Data Members
	private:

	char ISBN[11];
	char title[41];
	double price = 0;
	int quantity = 0;

	public:

	Book();
	Book(char*, char*, double, int);
	char* getISBN();
	char* getTitle();
	double getPrice();
	int getQuantity();
	void setPrice(double);
	void setQuantity(int);
	int fulfillOrder(int);
	void print();

	};

#endif /* BOOK_H */
