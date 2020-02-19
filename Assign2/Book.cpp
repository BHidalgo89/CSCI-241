#include "Book.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
using std::cout;

//*****************************************************************************
//	FUNCTION: Book()

//	USE: Default constructor. Initializes a Book object to the default values.

//	ARGUMENTS: None.
//****************************************************************************
Book::Book()
{
ISBN[0] = '\0';
title[0] = '\0';
}

//****************************************************************************
//	FUNCTION: Book()

//	USE: Alternate constructor. Initializes the data members of a Book object to the supplied
//	     arguments.

//	ARGUMENTS: 1. isbnNew: A character array containing the new ISBN.
//		   2. titleNew: A character array containing the new title name
//****************************************************************************

Book::Book(char isbnNew[], char titleNew[], double priceNew, int quantityNew)
{
strcpy(ISBN, isbnNew);
strcpy(title, titleNew);
setPrice(priceNew);
setQuantity(quantityNew);
}

//*************************************************************************************
//	FUNCTION: char* getISBN()

//	USE: Returns the ISBN data member. Data type for the return value is char.

//	ARGUMENTS: None
//************************************************************************************

char* Book::getISBN()
{
return ISBN;
}


//************************************************************************************
//	FUNCTION: char* getTitle()

//	USE: Returns the title data member. Data type for the return value is char.

//	ARGUMENTS: None
//**************************************************************************************

char* Book::getTitle()
{
return title;
}

//*************************************************************************************
//	FUNCTION: double getPrice()

//	USE: Returns the price data member

//	ARGUMENTS: None
//************************************************************************************

double Book::getPrice()
{
return price;
}

//************************************************************************************
//	FUNCTION: int getQuantity()

//	USE: Returns the quantity data member

//	ARGUMENTS: None
//***********************************************************************************

int Book::getQuantity()
{
return quantity;
}

//***********************************************************************************
//	FUNCTION: void setPrice()

//	USE: Checks if the new price is greater than or equal to 0. If it is,
//	     it should set the price data member to the new price. Otherwise, it should set the
//	     price data member to 0.

//	ARGUMENTS: Takes a double argument (a new price). It returns nothing.
//***********************************************************************************

void Book::setPrice(double priceNew)
{
if(priceNew >= 0)
{
price = priceNew;
}
else
price = 0;
}

//***********************************************************************************
//	FUNCTION: void setQuantity()

//	USE: Checks if the new quantity is greater than or equal to 0. If it is,
//	     it sets the quantity data member to the new quantity. Otherwise, it
//	     sets the quantity data member to 0.

//	ARGUMENTS: Takes an integer argument (a new quantity). It returns nothing.
//***********************************************************************************

void Book::setQuantity(int quantityNew)
{
if(quantityNew >= 0)
{
quantity = quantityNew;
}
else
{
quantity = 0;
}
}

//***********************************************************************************
//	FUNCTION: int fulfillOrder()

//	USE: Returns an integer which represents the quantity of the book that the
//	     that the bookstore is actually able to ship out at this time.

//	ARGUMENTS: Takes one integer which represents the quantity of the books
//	           that has been ordered.
//***********************************************************************************

int Book::fulfillOrder(int demanded)
{
int shipped = 0;
if(demanded < 0)
{
return 0;
}
else if(demanded <= quantity)
{
quantity = (quantity - demanded);
return demanded;
}
else
{
shipped = quantity;
quantity = 0;
return shipped;
}
}


//***********************************************************************************
//	FUNCTION: void print()

//	USE: Prints the ISBN, title, price, and quantity members.

//	ARGUMENTS: Takes no parameters and returns nothing.
//**********************************************************************************

void Book::print()
{
cout << left << setw(14) << ISBN ;
cout << left << setw(44) << title ;
cout << fixed << setprecision(2) << right << setw(5) << price ;
cout << right << setw(6) << quantity << endl;
}

