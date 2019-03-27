#pragma once
#include<vector>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>
#include "Vector.h"
#define PI 3.14159265358979323846

/***Error Type***/
enum MATRIX_ERROR {
	M_Correct = 0, MMO_Error, RC_Error
};

//定義 Matrix
class Matrix
{	
public:
	Matrix();

	std::string Name;
	std::vector<Vector> Data;	// Row Vector

	int getRow() const {		// Get Matrix Rows
		return Data.size();
	};
	int getCol() const {		// Get Matrix Columns
		return Data[0].getDim();
	}
	void print(System::Windows::Forms::TextBox^ );		// print Matrix 
	
	/* Operator Overloading */
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);	// Matrix Multiplication

	/* Method */
	friend Matrix Multi_Matrix_Op(array<System::String^> ^,const std::vector<Matrix>,MATRIX_ERROR&);	//多矩陣運算
	friend int Rank(const Matrix&);		// nonZero rows
	Matrix Transpose();
	Matrix Inverse();
	

	/* Format Dealing */

};