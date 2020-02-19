/***************************************************************************

	CLASS: Vector3

	PROGRAMMER: Branden Hidalgo

	LOGON ID: z1663752

	DUE DATE: 03/08/18

	PURPOSE: Manipulates 3-Dimensional vectors using overloading
		 techniques.

*****************************************************************************/

#include <iostream>
#include <iomanip>
#include "Vector3.h"

using namespace std;

/*************************************************************************
        FUNCTION: Vector3::Vector3()

        ARGUMENTS: 3 default variables

        RETURNS: N/A.

	PURPOSE: Initializes vector components x, y, z to 0.0.

        NOTES: Default constructor; intializes vector components
	    x, y, z to 0.0.
**************************************************************************/
Vector3::Vector3(float x, float y, float z)
   {
   vectorAr[0] = x;
   vectorAr[1] = y;
   vectorAr[2] = z;
   }

/*********************************************************************************

	FUNCTION: Vector3::ostream& operator<<(ostream& lhs, const Vector3&)

	ARGUMENTS: 2 Arguments. A reference to an ostream object and a 
		   constant reference to a Vector3 object.

	RETURNS: A reference to an ostream object

	PURPOSE: Sends a vector3 object to the standard output

	NOTES: Friend function to Vector3 class
*********************************************************************************/
ostream& operator<<(ostream& lhs, const Vector3& rhs)
    {
    lhs << "(" << rhs.vectorAr[0] << ", " << rhs.vectorAr[1] << ", " << rhs.vectorAr[2] << ")" ;
    return lhs;
    }

/***********************************************************************************

	FUNCTION: Vector3 Vector3::operator+(const Vector3& rhs) const

	ARGUMENTS: 1 constant reference to a Vector3 object representing the
		   right-hand operand

	RETURNS: A Vector3 object

	PURPOSE: Adds the components of two vectors.

	NOTES: Constant method

************************************************************************************/

Vector3 Vector3::operator+(const Vector3& rhs) const
    {
    Vector3 result;

    result.vectorAr[0] = vectorAr[0] + rhs.vectorAr[0];
    result.vectorAr[1] = vectorAr[1] + rhs.vectorAr[1];
    result.vectorAr[2] = vectorAr[2] + rhs.vectorAr[2];

    return result;
    }

/*************************************************************************************

	FUNCTION: Vector3 Vector3::operator-(const Vector3& rhs) const

	ARGUMENTS: 1 constant reference to a Vector3 object.

	RETURNS: A Vector3 object

	PURPOSE: Subtracts the components of two vectors from each other.

	NOTES: Constant method

**************************************************************************************/

Vector3 Vector3::operator-(const Vector3& rhs) const
    {
    Vector3 result;

    result.vectorAr[0] = vectorAr[0] - rhs.vectorAr[0];
    result.vectorAr[1] = vectorAr[1] - rhs.vectorAr[1];
    result.vectorAr[2] = vectorAr[2] - rhs.vectorAr[2];

    return result;
    }


/*****************************************************************************

        FUNCTION: float Vector3::operator*(const Vector3 & rhs)

        ARGUMENTS: constant reference to a Vector3 object

        RETURNS: 1 floating point value

	PURPOSE: Multiplies the components of two vectors, then adds the
		 results.
        NOTES: Constant Method

***************************************************************************/


float Vector3::operator*(const Vector3& rhs) const
    {
    float result1, result2, result3, finalResult;

    result1 = vectorAr[0] * rhs.vectorAr[0];
    result2 = vectorAr[1] * rhs.vectorAr[1];
    result3 = vectorAr[2] * rhs.vectorAr[2];
    finalResult = result1 + result2 + result3;

    return finalResult;
    }


/***************************************************************************

	FUNCTION: Vector3 Vector3::operator*(float val) const

	ARGUMENTS: 1 floating point value

	RETURNS: 1 Vector3 object.

	PURPOSE: Multiplies a vector by a floating point value

	NOTES: Constant Method

***************************************************************************/

Vector3 Vector3::operator*(float val) const
    {
    Vector3 result;

    result.vectorAr[0] = vectorAr[0] * val;
    result.vectorAr[1] = vectorAr[1] * val;
    result.vectorAr[2] = vectorAr[2] * val;

    return result;
    }

/***************************************************************************

	FUNCTION: Vector3 operator*(float val, const Vector3& rhs)

	ARGUMENTS: 1 floating point value
		   1 constant reference to a vector object

	RETURNS: 1 Vector3 object

	PURPOSE: Multiplies a vector by a floating point value

	NOTES: Friend function to the Vector3 class

****************************************************************************/

Vector3 operator*(float val, const Vector3& rhs)
    {
    Vector3 result;

    result.vectorAr[0] = val * rhs.vectorAr[0];
    result.vectorAr[1] = val * rhs.vectorAr[1];
    result.vectorAr[2] = val * rhs.vectorAr[2];

    return result;
    }

/**************************************************************************

	FUNCTION: float Vector3::operator[](int subVal) const

	ARGUMENTS: 1 integer value

	RETURNS: 1 floating point value

	PURPOSE: Provides write method for the class.

	NOTES: Constant Method

***************************************************************************/

float Vector3::operator[](int subVal) const
    {
    return vectorAr[subVal];
    }

/****************************************************************************

	FUNCTION: float& Vector3::operator[](int newVal)

	ARGUMENTS: 1 integer value

	RETURNS: 1 reference to a floating point value

	PURPOSE: Provides retriever method for the class

	NOTES: Method

****************************************************************************/
float& Vector3::operator[](int newVal)
    {
    return vectorAr[newVal];
    }

/***************************************************************************

	FUNCTION: bool Vector3::operator==(const Vector3& rhs) const

	ARGUMENTS: 1 constant reference to a Vector3 object

	RETURNS: 1 Boolean value

	PURPOSE: Compares the components of two vectors

	NOTES: Constant Method

*****************************************************************************/

bool Vector3::operator==(const Vector3& rhs) const
    {
    if(vectorAr[0] == rhs.vectorAr[0] && vectorAr[1] == rhs.vectorAr[1] && vectorAr[2] == rhs.vectorAr[2])
	{
	return 1;
	}
    else
	{
	return 0;
	}
    }
