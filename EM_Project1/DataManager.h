#pragma once
#include "Vector.h"
/*
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>

#define PI 3.14159265358979323846
//定義向量資料結構
/*
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	int getDim() const {
		return Data.size();
	}
};*/
//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);

	///* Operator Overloading */
	//friend Vector operator+(const Vector&, const Vector&);
	//friend Vector operator-(const Vector&, const Vector&);
	//friend Vector operator*(const Vector&, const Vector&);  // Dot

	//Vector Scalar(const Vector&, const Vector&)const;
	//double Norm(const Vector&)const;		//向量長度
	//Vector Normal(const Vector&)const;	// Normalizatioin 轉單位向量
	//Vector Cross(const Vector&, const Vector&)const;		// Cross Product 三維外積
	//Vector Comp(const Vector &, const Vector&)const;		// Component 向量A印射到向量B的長度
	//Vector Proj(const Vector&, const Vector&)const;		// Projection 正射影

	//double TrigArea(const Vector&, const Vector&)const;	// Triangle Area
	//bool IsParal(const Vector&, const Vector&)const;		// Parallrl Judge
	//bool IsOrthog(const Vector&, const Vector&)const;		// Orthogonal Judge
	//double Angle(const Vector&, const Vector&)const;
	//bool IsLI(const Vector&, const Vector&)const;
	//std::vector<Vector> Ob(std::vector<Vector>)const;
};