#pragma once
#include "Vector.h"
#include "Matrix.h"

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;

	//�x�s�x�}���
	std::vector<Matrix> Matrices;
	//�����x�}ID�A�Ω󱱺�
	int MatrixVariableIndex;

	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();

	//Ū���V�q���
	bool LoadMatrixData();
	//���o�V�q���
	std::vector<Matrix> GetMatrices();

	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	
};