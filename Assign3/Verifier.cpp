#include "Verifier.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::setw;
using std::left;

//***************************************************************************
//	FUNCTION: Verifier()

//	USE: Default constructor. Initializes all elements of the
//            grid array to 0.

//	ARGUMENTS: Takes no arguments and returns nothing.
//****************************************************************************

Verifier::Verifier()
{
	for(int i=0;i<9;i++)			//for loop goes through 
		for(int j=0;j<9;j++)		//each element of both arrays
                    grid[i][j]=0;		//and initializes them to 0.
}

//***************************************************************************
//	FUNCTION: void readGrid(const char* fileName)

//	USE: Reads the contents of an input file into the elements of the
//	     grid array.

//	ARGUMENTS: Takes one parameter, a pointer to a constant character 
//	           which will point to an array of characters that contains
//		   the name of a file to use as input. It returns nothing.
//***************************************************************************

void Verifier::readGrid(const char* fileName)
{

ifstream inFile(fileName);                         // Opening data file
if(!inFile)                                        // Checking if file was opened
{
cout << "Error" << endl;
exit (-1);
}

for(int row = 0; row < 9; row++)                   //Goes through each element 
   {
   for(int col = 0; col < 9; col++)
	{
	inFile >> grid[row][col];		   //Reads the file into each 
	}				           //element.
   }
}


//***************************************************************************
//	FUNCTION: void printGrid()
//
//	USE: Prints the Sudoku grid array to the screen.
//
//	ARGUMENTS: Takes no arguments and returns nothing.
//***************************************************************************

void Verifier::printGrid()
	{
	for(int row = 0; row < 9; row++)
		{
		for(int col = 0; col < 9; col++)
			{
			cout << setw(2) << grid[row][col];
			}
		cout << endl;
		}
	}

//****************************************************************************
//	FUNCTION: bool verifySolution()
//
//	USE: Verifies if the Sudoku grid array contains a valid solution.
//
//	ARGUMENTS: Takes no arguments.
//	           Returns a boolean value. True if the grid array contains
//		   a valid solution, false if not.
//***************************************************************************

bool Verifier::verifySolution()
	{
	for(int row = 0; row < 9; row++)
		{
		int rowArray[9] = {0};
		for(int col = 0; col < 9; col++)
			{
			int i = grid[row][col];
			if(rowArray[i-1] != 0)
				{
				return false;
				}
			else
				{
				rowArray[i-1] = i;
				}
			}
		}

	 for(int col = 0; col < 9; col++)
		{
		int colArray[9] = {0};
		for(int row = 0; row < 9; row++)
			{
			int j = grid[row][col];
			if(colArray[j-1] != 0)
				{
				return false;
				}
			else
				{
				colArray[j-1] = j;
				}
			}
		}

	for(int row = 0; row < 3; row++)
		{
		for(int col = 0; col < 3; col++)
			{
			int subGrid[9] = {0};
			for(int gridRow = row*3; gridRow < row*3+3; gridRow++)
				{
				for(int gridCol = col*3; gridCol < col*3+3; gridCol++)
					{
					int i = grid[gridRow][gridCol];
					if(subGrid[i-1] != 0)
						{
						return false;
						}
					else
						{
						subGrid[i-1] = i;
						}
					}
				}
			}
		}
	return true;
	}


