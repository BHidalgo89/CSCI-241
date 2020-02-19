/****************************************************************************

	CLASS: VectorN

	PROGRAMMER: Branden Hidalgo

	LOGON ID: Z1663752

	DUE DATE:

	PURPOSE: Utilization of dynamic storage allocation and operator
		 overloading in terms of vectors.

****************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include <fstream>
#include <string>
#include "VectorN.h"

using std::cout;
using std::endl;
using std::out_of_range;

/*****************************************************************************
	FUNCTION: VectorN()

	ARGUMENTS: No arguments

	RETURNS: N/A

	PURPOSE: Default constructor initializes a new VectorN object to an empty
		 vector array with a capacity of 0

	NOTES: VectorN method
*****************************************************************************/
VectorN::VectorN()
   {
   vCapacity = 0;
   vArray = nullptr;
   }

/*****************************************************************************
	FUNCTION: VectorN(const double values[], size_t n)

	ARGUMENTS: A constant double array and a size_t variable

	RETURNS: N/A

	PURPOSE: Constructor initializes a new VectorN object to the values stored in the
		 values array

	NOTES: VectorN method
*****************************************************************************/
VectorN::VectorN(const double values[], size_t n)
   {
   vCapacity = n;
   if(vCapacity == 0)
     {
     vArray = nullptr;
     }
   else
     {
     vArray = new double[vCapacity];
     for(size_t i = 0; i < vCapacity; i++)
       {
       vArray[i] = values[i];
       }
     }
   }

/****************************************************************************
	FUNCTION: VectorN(const Vectorn& other)

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: N/A

	PURPOSE: Copy constructor initializes a new VectorN object to the same
		 capacity and array contents as the existing VectorN object

	NOTES: VectorN method
*****************************************************************************/
VectorN::VectorN(const VectorN& other)
   {
   vCapacity = other.vCapacity;
   if(vCapacity == 0)
     {
     vArray = nullptr;
     }
   else
     {
     vArray = new double[vCapacity];
     for(size_t i = 0; i < vCapacity; i++)
       {
       vArray[i] = other.vArray[i];
       }
     }
   }

/*****************************************************************************
	FUNCTION: ~VectorN()

	ARGUMENTS: N/A

	RETURNS: N/A

	PURPOSE: Destructor deallocates a pointer object and the dynamic
	         storage that it points to

	NOTES: VectorN method
****************************************************************************/
VectorN::~VectorN()
   {
   delete[] vArray;
   }

/****************************************************************************
	FUNCTION: VectorN& operator=(const VectorN& other)

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: A reference to a constant VectorN object

	PURPOSE: Overloaded copy assignment operator assigns a VectorN object
		 to another VectorN object and deletes the vector array for
		 the object pointed to by this

	NOTES: VectorN method
*****************************************************************************/
VectorN& VectorN::operator=(const VectorN& other)
   {
   if(this != &other)
     {
     delete[] vArray;
     vCapacity = other.vCapacity;

     if(vCapacity == 0)
       {
       vArray = nullptr;
       }
     else
       {
       vArray = new double[vCapacity];
       }
     for(size_t i = 0; i < vCapacity; i++)
       {
       vArray[i] = other.vArray[i];
       }
     }
    return *this;
   }

/*****************************************************************************
	FUNCTION: void clear()

	ARGUMENTS: N/A

	RETURNS: void

	PURPOSE: Sets the instance back to a vector of zero elements.
		 Deletes the vector array, sets the vector array pointer to
		 nullptr, and sets the vector capacity to 0

	NOTES: VectorN method
*****************************************************************************/
void VectorN::clear()
   {
   delete[] vArray;
   vArray = nullptr;
   vCapacity = 0;
   }

/*****************************************************************************
	FUNCTION: size_t size() const

	ARGUMENTS: N/A

	RETURNS: A size_t value

	PURPOSE: Gets the size of the vector, which is equal to the capacity
		 of the vector

	NOTES: Constant VectorN method
*****************************************************************************/
size_t VectorN::size() const
   {
   return vCapacity;
   }

/*****************************************************************************
	FUNCTION: VectorN operator+(const VectorN& other) const

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: A VectorN object

	PURPOSE: Addition operator adds the components of two vectors in
		 sequence

	NOTES: Constant VectorN method
*****************************************************************************/
VectorN VectorN::operator+(const VectorN& other) const
   {
   VectorN result;

   if(vCapacity < other.vCapacity)
     {
     result.vCapacity = vCapacity;
     }
   else
     {
     result.vCapacity = other.vCapacity;
     }

   result.vArray = new double[result.vCapacity];

   for(size_t i = 0; i < result.vCapacity ; i++)
     {
     result.vArray[i] = vArray[i] + other.vArray[i];
     }
   return result;
   }

/****************************************************************************
	FUNCTION: VectorN operator-(const VectorN& other) const

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: A VectorN object

	PURPOSE: Subtraction operator subtracts the components of two vectors
		 in sequence

	NOTES: Constant VectorN method
*****************************************************************************/
VectorN VectorN::operator-(const VectorN& other) const
   {
   VectorN result;
   if(vCapacity < other.vCapacity)
     {
     result.vCapacity = vCapacity;
     }
   else
     {
     result.vCapacity = other.vCapacity;
     }

   result.vArray = new double[result.vCapacity];

   for(size_t i = 0; i < result.vCapacity; i++)
     {
     result.vArray[i] = vArray[i] - other.vArray[i];
     }
   return result;
   }

/****************************************************************************
	FUNCTION: double operator*(const VectorN& other) const

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: A double value

	PURPOSE: Multiplication operator computes the scalar product of two
		 vectors

	NOTES: Constant VectorN method
*****************************************************************************/
double VectorN::operator*(const VectorN& other) const
   {
   double result;
   size_t capacity = 0;

   if(vCapacity < other.vCapacity)
     {
     capacity = vCapacity;
     }
   else
     {
     capacity = other.vCapacity;
     }

   for(size_t i = 0; i < capacity; i++)
     {
     result +=  vArray[i] * other.vArray[i];
     }
   return result;
   }

/*****************************************************************************
	FUNCTION: VectorN operator*(const double& val) const

	ARGUMENTS: A reference to a constant double

	RETURNS: A VectorN object

	PURPOSE: Multiplication operator computes the multiplication of a
		 VectorN object and a double constant in that order.

	NOTES: Constant VectorN method
*****************************************************************************/
VectorN VectorN::operator*(const double& val) const
   {
   VectorN result;

   result.vCapacity = vCapacity;

   result.vArray = new double[result.vCapacity];

   for(size_t i = 0; i < result.vCapacity; i++)
     {
     result.vArray[i] = vArray[i] * val;
     }
   return result;
   }

/*****************************************************************************
	FUNCTION: friend VectorN operator*(const float& val, const VectorN& v1)

	ARGUMENTS: A reference to a constant float and a reference to a constant
		   VectorN object

	RETURNS: A VectorN object

	PURPOSE: Multiplication operator is a friend method which computes the
		 multiplication of a constant float and a constant VectorN
		 object in that order

	NOTES: Constant friend function to the VectorN class
*****************************************************************************/
VectorN operator*(const double& val, const VectorN& other)
   {
   VectorN result;

   result.vCapacity = other.vCapacity;

   result.vArray = new double[result.vCapacity];

   for(size_t i = 0; i < result.vCapacity; i++)
     {
     result.vArray[i] = val * other.vArray[i];
     }
   return result;
   }

/****************************************************************************
	FUNCTION: friend ostream& operator<<(ostream&, const VectorN&)

	ARGUMENTS: A reference to an ostream object and a constant reference
		   to a VectorN object

	RETURNS: A reference to an ostream object

	PURPOSE: Insertion operator allows a VectorN to be sent to the
		 standard output

	NOTES: A friend function to the VectorN class
*****************************************************************************/
std::ostream& operator<<(std::ostream& output, const VectorN& v)
   {
   if(v.vCapacity == 0)
     {
     output << "()";
     }
   else
     {
     output << "(";
     for(size_t i = 0; i < v.vCapacity; i++)
       {
       output << v.vArray[i];
       if(i < v.vCapacity - 1)
         {
         output << ", ";
         }
       else
         {
         output << ")";
         }
       }
     }
   return output;
   }

/*****************************************************************************
	FUNCTION: double operator[](int sub) const;

	ARGUMENTS: An integer subscript

	RETURNS: A double

	PURPOSE: Subscript operator serves as an accessor method to the
		 VectorN class. Gets the value of a given subscript of a
		 vector array

	NOTES: Constant VectorN method
*****************************************************************************/
double VectorN::operator[](int sub) const
   {
   return vArray[sub];
   }

/*****************************************************************************
	FUNCTION: double& operator[](int sub)

	ARGUMENTS: An integer subscript

	RETURNS: A reference to a double

	PURPOSE: Subscript operator serves as an accessor method to the
		 VectorN class. Sets the value of a given subscript of a
		 vector array.
	NOTES: VectorN method
*****************************************************************************/
double& VectorN::operator[](int sub)
   {
   return vArray[sub];
   }

/****************************************************************************
	FUNCTION: at(int sub) const

	ARGUMENTS: An integer subscript

	RETURNS: A double

	PURPOSE: Accessor method which provides error checking while
		 getting the value of a given subscript of a vector
		 array

	NOTES: Constant VectorN method
*****************************************************************************/
double VectorN::at(int sub) const
   {
   if(sub < 0 || sub >= (int) vCapacity)
     {
     throw out_of_range("subscript out of range");
     }
   else
     {
     return vArray[sub];
     }
   }

/****************************************************************************
	FUNCTION: double& at(int sub)

	ARGUMENTS: An integer subscript

	RETURNS: A reference to a double

	PURPOSE: Accessor method which provies error checking while setting
		 the value of a given subscript of a vector array

	NOTES: VectorN method
*****************************************************************************/
double& VectorN::at(int sub)
   {
   if(sub < 0 || sub >= (int) vCapacity)
     {
     throw out_of_range("subscript out of range");
     }
   else
     {
     return vArray[sub];
     }
   }

/*****************************************************************************
	FUNCTION: bool operator==(const VectorN& other) const

	ARGUMENTS: A reference to a constant VectorN object

	RETURNS: A boolean value

	PURPOSE: Equality operator compares two VectorN objects to see if they
		 are equal

	NOTES: Constant VectorN method
*****************************************************************************/

bool VectorN::operator==(const VectorN& other) const
   {
   if(vCapacity != other.vCapacity)
     {
     return 0;
     }

   for(size_t i = 0; i < vCapacity; i++)
       {
       if(vArray[i] != other.vArray[i])
         {
         return 0;
         }
       }
    return 1;
    }




