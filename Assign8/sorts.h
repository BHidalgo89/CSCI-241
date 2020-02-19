/*****************************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Branden Hidalgo
   LOGON ID:   z1663752
   DUE DATE:
 
   FUNCTION:   This program builds and sorts lists using the quicksort
               algorithm.
*****************************************************************************/
#ifndef  SORTS_H
#define  SORTS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using std::cout; using std::endl;
using std::vector;
using std::setw;
using std::ifstream; using std::ofstream;

/*********************************************************************
Method:  void buildList(vector<T>&, const char*)
Use: read a file and put the items into a vector
Arguments: a reference to a vector<T> and the name of the file
Returns: nothing
*********************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{

 T item;
 ifstream inFile;
 inFile.open( fileName );

 if( inFile.fail() )
 {
 cout << "input file did not open" << endl;
 exit(-1);
  }

//read the file in infile  
 inFile >> item;
 while(!inFile.eof())

 {
   set.push_back(item);
   inFile >> item;
 }


inFile.close();		
}
		

/*********************************************************************
Method:  void printList(const vector<T>&, int, int)
Use: print vector's contents 
Arguments: a reference to a vector<T>, integer that represents the 
           spaces for setw, and an integer that represents how many
	   items to print per line
Returns: nothing
*********************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
 for(size_t i = 0; i < set.size(); i++)
 {
  if (i % numPerLine ==0 && i!=0)
  {
     cout<<"\n";
  }
  cout<< setw(itemWidth) << set[i]<< " "  ;
 }
}


template <class T>
bool lessThan(const T& item1, const T& item2)
{
 return (item1 < item2);
}


template <class T>
bool greaterThan(const T& item1, const T& item2)
{
 return (item1 > item2);
}


#endif
