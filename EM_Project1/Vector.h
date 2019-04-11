#pragma once
#include<vector>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>
#include"DotNetUitilities.h"

#define PI 3.14159265358979323846

int priority(std::string);
/***** Error Type *****/
enum VECTOR_ERROR {
	Correct = 0, E_Error = 1, Dim_Error, VN_Error
};

class Vector
{
public:
	Vector(); 
	std::string Name;
	std::vector<double> Data;
	int getDim() const {
		return Data.size();
	}

	/* Operator Overloading */
	friend Vector operator+(const Vector&, const Vector&);
	friend Vector operator-(const Vector&, const Vector&);
	friend Vector operator*(const Vector&, const Vector&);  // Dot

	/* Method */
	friend Vector Scalar(const Vector&, const Vector&);
	friend double Norm(const Vector&);		//向量長度
	friend Vector Normal(const Vector&);	// Normalizatioin 轉單位向量

	friend Vector Cross(const Vector&, const Vector&);		// Cross Product 三維外積
	friend Vector Comp(const Vector &, const Vector&);		// Component 向量A印射到向量B的長度
	friend Vector Proj(const Vector&, const Vector&);		// Projection 正射影

	friend double TrigArea(const Vector&, const Vector&);	// Triangle Area
	friend bool IsParal(const Vector&, const Vector&);		// Parallrl Judge
	friend bool IsOrthog(const Vector&, const Vector&);		// Orthogonal Judge
	friend double Angle(const Vector&, const Vector&);
	//friend bool IsLI(const Matrix&);		// Linear Independent Judge
	friend std::vector<Vector> Ob(const std::vector<Vector>&);		// Gram–Schmidt Orthogonalization Process

	/* 處理格式 */
	friend Vector MVS(array<System::String^> ^, std::vector<Vector>, VECTOR_ERROR&);
	friend void Format_Two(array<System::String^> ^, const std::vector<Vector>, VECTOR_ERROR&,Vector&, Vector&);
	friend void Format_One(array<System::String^> ^, const std::vector<Vector>, VECTOR_ERROR&, Vector&);
	friend void Format_Muti(array<System::String^> ^, const std::vector<Vector>, VECTOR_ERROR&, std::vector<Vector>&);
};

