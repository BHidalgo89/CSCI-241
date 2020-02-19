#include "Book.h"
#include "BookStore.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
using std::cout;
using std::string;
using std::endl;
using std::ifstream;

//**************************************************************************
//	FUNCTION: Bookstore()

//	USE: Creates an empty database.

//	ARGUMENTS: Takes no arguments and returns nothing.
//**************************************************************************

BookStore::BookStore()
{
}

//*************************************************************************
//	FUNCTION: Bookstore(const char &string)

//	USE: Alternate constructor. Contains the name of an existing
//	     database file. Declares an input file stream variable.
//	     Opens the file stream for binary input. Reads the database
//	     file into a Bookstore object.

//	ARGUMENTS: Takes a reference to a constant sting object (const string&)
//		   and returns nothing.
//**************************************************************************

BookStore::BookStore(const std::string& fileName)
{
ifstream inFile(fileName);

//inFile.open(fileName);

if(!inFile)
{
cout << "Error: No Valid File Found" << endl;
exit(-1);
}

inFile.read((char*) this, sizeof(BookStore));
//cout<<"File Read"<<endl;
inFile.close();

sortByISBN();
}

//**************************************************************************
//	FUNCTION: void print()

//	USE: Displays output from the program.

//	ARGUMENTS: Takes no arguments and returns nothing.
//*************************************************************************

void BookStore::print()
{
cout << "***Book Inventory Listing***" << endl;

for(int i=0; i<numBooks; i++)
{
	cout<<endl;
bookSpace[i].print();
}
}

//********************************************************************************************
//	FUNCTION: void sortByISBN()

//	USE: Sorts the bookSpace array in ascending order by ISBN using the insertion sort
//	     algorithm.

//	ARGUMENTS: Takes no arguments and returns nothing.
//********************************************************************************************

void BookStore::sortByISBN()
{
int i, j;
Book bucket;

   for ( i = 1; i < numBooks; i++)
      {
      bucket = bookSpace[i];

      for (j = i; (j > 0) && (strcmp(bookSpace[j-1].getISBN(), bucket.getISBN()) > 0); j--)
         bookSpace[j] = bookSpace[j-1];

      bookSpace[j] = bucket;
      }
   }

//*********************************************************************************************
//	FUNCTION: int searchForISBN(char* searchISBN)

//	USE: Uses the ISBN of the Book to conduct a binary search.

//	ARGUMENTS: Takes one parameter, a character array containing the ISBN of the Book to
//	           search for. Returns an integer.
//*********************************************************************************************

int BookStore::searchForISBN(char* searchISBN)
{
int low = 0;
int high = numBooks - 1;
int mid;

  while (low <= high)
    {
      mid = (low + high) / 2;

      if (strcmp(searchISBN, bookSpace[mid].getISBN()) == 0)
         return mid;

      if (strcmp(searchISBN, bookSpace[mid].getISBN()) < 0)
         high = mid - 1;
      else
         low = mid + 1;
      }

   return -1;
	}

//********************************************************************************************
//	FUNCTION: void processOrders(char* const string&)

//	USE: Reads a series of order records. For each order record it searches for the ISBN
//	     and either passes the order quantity to the fulfillOrder() method or displays
//	     an error message if an ISBN is not found.

//	ARGUMENTS: Takes one parameter, a reference to a constant string object tat contains
//	           the name of a file of order records. Returns nothing.
//********************************************************************************************

void BookStore::processOrders(const std::string& fileName1)
{
ifstream inFile;
char orderNumber[7];
char ISBN[11];
int orderQuantity;
int numShipped;

inFile.open(fileName1);

if(!inFile)
{
cout << "Error: No Valid File Found" << endl;
}


while(inFile >> orderNumber)
{
inFile >> ISBN;
inFile >> orderQuantity;

int i = searchForISBN(ISBN);
if(i==-1)
{
cout << "Error: Unable to fulfill your order." << endl;
}
else
{
numShipped = bookSpace[i].fulfillOrder(orderQuantity);

cout << "The Order Number Is " << orderNumber << "." << endl;
cout << "The ISBN Is: " << ISBN << "." << endl;
cout << "The Order Quantity Is: " << orderQuantity << "." << endl;
cout << "The Number of Shipments Is: " << numShipped << "." << endl;
}

//inFile >> orderNumber;
}

inFile.close();
	}








