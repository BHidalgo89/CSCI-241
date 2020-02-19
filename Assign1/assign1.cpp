/*******************************************************************************
   PROGRAM:    CSCI 241 Assignment 1 SPRING 2018
   PROGRAMMER: Branden Hidalgo
   LOGON ID:   z1663752
   DUE DATE:   2/1/2018

   FUNCTION:   This program tests functions for manipulating C
               strings.
*******************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here

bool equals(const char*,const char*);
bool equalsIgnoreCase(const char*, const char*);
int indexOf(const char*, char);
int lastIndexOf(const char*, char);
bool startsWith(const char*, const char*);
bool endsWith(const char*, const char*);

int main()
   {
   int index;

   // Tests 1a - 1d: Test the equals() function
   cout << "Test 1a: ";
   if (equals("catapult", "catapult"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1b: ";
   if (!equals("catapult", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1c: ";
   if (!equals("cat", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1d: ";
   if (!equals("catapult", "cat"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;

   // Tests 2a - 2d: Test the equalsIgnoreCase() function
   cout << "Test 2a: ";
   if (equalsIgnoreCase("catapult", "CATAPULT"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2b: ";
   if (!equalsIgnoreCase("catapult", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2c: ";
   if (!equalsIgnoreCase("Cat", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2d: ";
   if (!equalsIgnoreCase("Catapult", "Cat"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;

   // Tests 3a - 3d: Test the indexOf() function
   cout << "Test 3a: ";
   index = indexOf("adamant", 'a');
   if (index == 0)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 0\n";

   cout << "Test 3b: ";
   index = indexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 3c: ";
   index = indexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 3d: ";
   index = indexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;

   // Tests 4a - 4d: Test the lastIndexOf() function
   cout << "Test 4a: ";
   index = lastIndexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 4b: ";
   index = lastIndexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 4c: ";
   index = lastIndexOf("adamant", 'a');
   if (index == 4)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 4\n";

   cout << "Test 4d: ";
   index = lastIndexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;

   // Tests 5a - 5c: Test the startsWith() function
   cout << "Test 5a: ";
   if (startsWith("your house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 5b: ";
   if (!startsWith("my house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 5c: ";
   if (!startsWith("you", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;

   // Tests 6a - 6c: Test the endsWith() function
   cout << "Test 6a: ";
   if (endsWith("your house", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 6b: ";
   if (!endsWith("your mouse", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 6c: ";
   if (!endsWith("use", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   return 0;
   }

// Add your function definitions here

/****************************************************************************
Function: equals

Use: Compares the C string str1 to the C string str2
using the string compare function (strcmp()).

Parameters:
1. str1: A constant character array to be compared with str2.
2. str2: A constant character array to be compared with str1.

Returns: A bool result (true if they are equal, false if they are not.)
*****************************************************************************/
bool equals(const char* str1, const char* str2)
{
	if(strcmp(str1, str2) == 0)
	{
	return true;
	}
	else
	{
	return false;
	}
}

/*****************************************************************************
Function: equalsIgnoreCase

Use: Compares the C string str1 to the C string str2 using a for loop.
It uses the tolower and toupper functions to ignore case consideration.

Parameters:
1. str1: A constant character array to be compared with str2, ignoring case.
2. str2: A constant character array to be compared with str1, ignoring case.

Returns: A bool result (true if they are equal, false if they are not),
ignoring letter-case consideration.
*****************************************************************************/

bool equalsIgnoreCase(const char* str1, const char* str2)
	{
	int i;
	for(i=0; str1[i] != '\0' && str2[i] != '\0'; i++)
		{
		if(tolower(str1[i]) != tolower(str2[i]))
			{
			return false;
			}
		}
	if(str1[i] == '\0' && str2[i] == '\0')
	{
	return true;
	}
	else
	{
		return false;
	}
	}

/*****************************************************************************
Function: indexOf

Use: Uses a for loop to search the C string (parameter str) for the first
occurence of the desired character (parameter ch).

Parameters:
1. A constant character array (str)
2. A character from the char class which the function searches for within str.

Returns: An integer which represents the index of the first occurence of ch
within str.
*****************************************************************************/

int indexOf(const char* str, char ch)
	{
	int i;
	for(i=0; str[i] != '\0'; i++)
		{
		if(str[i] == ch)
			{
			return i;
			}
		}

			return -1;
	}

/******************************************************************************
Function: lastIndexOf

Use: Uses a for loop to search the constant character (parameter str) to search
for the last occurence of the character (parameter ch).

Parameters:
1. A constant character array, str, which is searched.
2. A character from the char class. The last occurence of this character is
what is searched for within str.

Returns:
An integer that represents the index of the last occurence of ch within str.
*******************************************************************************/

int lastIndexOf(const char* str, char ch)
	{
	int i, x = -1;
	for(i=0; str[i] != '\0'; i++)
		{
		if(str[i] == ch)
			{
			x = i;
			}
		}
	return x;
	}

/*******************************************************************************
Function: startsWith

Use: Tests if the C string (parameter str) starts with the specified prefix,
the C string (parameter prefix).

Parameters:
1. A constant character array, str.
2. A constant character array, prefix.

Returns: A bool result (true or false).
*******************************************************************************/

bool startsWith(const char* str, const char* prefix)
{
int i;
for(i=0; str[i] != '\0' && prefix[i] != '\0'; i++)
	{
	if(str[i] != prefix[i])
		{
		return false;
		}
	}
	if(prefix[i]  == '\0')
		{
		return true;
		}
	else
		{
		return false;
		}
}

/*******************************************************************************
Function: endsWith

Use: Tests if the C string (parameter str) ends with the specified suffix, the
C string (parameter suffix).

Parameters:
1. A constant character array, str.
2. A constant character array, suffix.

Returns: A bool result (true or false).
*******************************************************************************/

bool endsWith(const char* str, const char* suffix)
{
int i, j;
for(i = strlen(str)-1, j = strlen(suffix)-1; i >= 0 && j >= 0; i--, j--)
	{
	if(str[i] != suffix[j])
		{
		return false;
		}
	}
if(j == -1)
	{
	return true;
	}
else
	{
	return false;
	}
}

