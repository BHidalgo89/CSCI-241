#ifndef VERIFIER_H
#define VERIFIER_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>



//****************************************************************************
//	FILE:		Verifier.h
//	AUTHOR:		Branden Hidalgo
//	LOGON ID:	z1663752
//	DUE DATE:	03/27/18
//
//	PURPOSE:
//****************************************************************************

class Verifier
	{
	private:

		int grid[9][9];

	public:

		Verifier();
		void readGrid(const char* fileName);
		void printGrid();
		bool verifySolution();
	};

#endif

