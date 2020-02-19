#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>

//**************************************************************************
// File:	Vector3.h
// Author:	Branden Hidalgo
// Logon ID:	z1663752
// DUE DATE:	03/08/18
//
//PURPOSE:
//**************************************************************************

class Vector3
	{	friend std::ostream& operator<<(std::ostream&, const Vector3&);
                friend Vector3 operator*(const float, const Vector3&);

	private:
 		float vectorAr[3];

	public:
		Vector3(float = 0.0, float = 0.0, float = 0.0);
		Vector3 operator+(const Vector3&) const;
		Vector3 operator-(const Vector3&) const;
		float operator*(const Vector3&) const;
		Vector3 operator*(float) const;
		bool operator==(const Vector3&) const;
		float operator[](int) const;
		float& operator[](int);
	};
#endif

