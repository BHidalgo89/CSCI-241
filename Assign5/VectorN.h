#ifndef VECTORN_H
#define VECTORN_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

//****************************************************************************
// File:	VectorN.h
// Author:	Branden Hidalgo
// Logon ID:	z1663752
// Due Date:
//
// Purpose:
//***************************************************************************/

class VectorN
	{
		friend VectorN operator*(const double&, const VectorN&);
		friend std::ostream& operator<<(std::ostream&, const VectorN&);

	private:
		double* vArray;
		size_t vCapacity;

	public:
		VectorN();

		VectorN(const double[], size_t);
		VectorN(const VectorN&);
		~VectorN();
		VectorN& operator=(const VectorN&);
		void clear();
		size_t size() const;
		VectorN operator+(const VectorN&) const;
		VectorN operator-(const VectorN&) const;
		double operator*(const VectorN&) const;
		VectorN operator*(const double&) const;
		double operator[](int) const;
		double& operator[](int);
		double at(int) const;
		double& at(int);
		bool operator==(const VectorN&) const;
	};

#endif
