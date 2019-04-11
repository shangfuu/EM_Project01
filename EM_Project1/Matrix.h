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
	M_Correct = 0, M_ERROR, MMO_Error, RC_Error
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
	}

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
	int Rank() const;		// nonZero rows

	friend Matrix Copy(const Matrix&);
	friend Matrix Transpose(const Matrix&);
	friend Matrix Inverse(const Matrix&);
	friend Matrix Solve_Linear_System(const Matrix&, const Matrix&);
	friend double Determinant(const Matrix&);
	friend  Matrix Adjoint(const Matrix&);
	friend  Matrix Eigen(const Matrix&);
	friend Vector FindK(const Matrix&, int);
	friend std::vector<Vector> Power_Method(const Matrix&);
	friend Matrix LeastSquare(const Matrix&, const Matrix &);
	// 最後一筆測資
	friend Matrix L_rref(const Matrix&);
	friend Matrix U_rref(const Matrix&);
	friend Matrix U_Triangle(const Matrix&);

	/* Format Dealing */
	friend void Format_One(array<System::String^> ^, const std::vector<Matrix> , MATRIX_ERROR& , Matrix& );
	friend void Format_Two(array<System::String^> ^, const std::vector<Matrix>, MATRIX_ERROR&, Matrix&, Matrix&);
};