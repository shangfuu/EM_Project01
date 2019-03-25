#pragma once
#include "Vector.h"
/*
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>

#define PI 3.14159265358979323846
//�w�q�V�q��Ƶ��c
/*
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	int getDim() const {
		return Data.size();
	}
};*/
//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);

	///* Operator Overloading */
	//friend Vector operator+(const Vector&, const Vector&);
	//friend Vector operator-(const Vector&, const Vector&);
	//friend Vector operator*(const Vector&, const Vector&);  // Dot

	//Vector Scalar(const Vector&, const Vector&)const;
	//double Norm(const Vector&)const;		//�V�q����
	//Vector Normal(const Vector&)const;	// Normalizatioin ����V�q
	//Vector Cross(const Vector&, const Vector&)const;		// Cross Product �T���~�n
	//Vector Comp(const Vector &, const Vector&)const;		// Component �V�qA�L�g��V�qB������
	//Vector Proj(const Vector&, const Vector&)const;		// Projection ���g�v

	//double TrigArea(const Vector&, const Vector&)const;	// Triangle Area
	//bool IsParal(const Vector&, const Vector&)const;		// Parallrl Judge
	//bool IsOrthog(const Vector&, const Vector&)const;		// Orthogonal Judge
	//double Angle(const Vector&, const Vector&)const;
	//bool IsLI(const Vector&, const Vector&)const;
	//std::vector<Vector> Ob(std::vector<Vector>)const;
};