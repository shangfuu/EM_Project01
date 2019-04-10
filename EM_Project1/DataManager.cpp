#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int currentLoadVectorID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		std::vector<double> tempVectorData;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring = "";
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempSring;

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempSring;
			//�ѪR��V�q�аO"V"
			if (tempSring == "") {
				break;
			}
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//�w�q�Ȧs�V�q��Ƶ��c
					Vector tempVector;
					//�s�J�V�q���
					tempVector.Data = tempVectorData;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.Name = vectorVariableTemp;
					//�s�J�V�q
					Vectors.push_back(tempVector);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					VectorVariableIndex++;
					//�M���V�q��ƼȦs
					tempVectorData.clear();
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadVectorID++;
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempSring;
			}
			else
			{
				//Ū���V�q��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//�N�V�q��Ʀs�J�Ȧs
				tempVectorData.push_back(value);
			}
			tempSring = "";
		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//Ū�����\�^��false
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}

bool DataManager::HasVector()
{
	if (this->Vectors.size()) {
		return true;
	}
	return false;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

bool DataManager::LoadMatrixData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int rows = 0, cols = 0;
		int currentLoadMatrixID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		Vector MatrixCols;
		std::vector<Vector> MatrixRows;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempString = "";
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempString;

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempString;
			//�ѪR��V�q�аO"V"
			if (tempString == "") {
				break;
			}
			if (tempString == "M")
			{
				if (currentLoadMatrixID != 0)
				{
					//�w�q�Ȧs�V�q��Ƶ��c
					Matrix tempMatrix;
					//�s�J�V�q���
					tempMatrix.Data = MatrixRows;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string MatrixVariableTemp = "m" + std::to_string(MatrixVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempMatrix.Name = MatrixVariableTemp;
					//�s�J�V�q
					Matrices.push_back(tempMatrix);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					MatrixVariableIndex++;
					//�M���V�q��ƼȦs
					MatrixRows.clear();
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadMatrixID++;
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempString;
				rows = stoi(tempString);
				fin >> tempString;
				cols = stoi(tempString);
			}
			else
			{
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						double value;
						value = (double)strtod(tempString.c_str(), NULL);
						//�N�V�q��Ʀs�J�Ȧs
						MatrixCols.Data.push_back(value);
						if (i == (rows - 1) && j == (cols - 1))
							int o;
						else
							fin >> tempString;
					}
					MatrixRows.push_back(MatrixCols);
					MatrixCols.Data.clear();
				}
			}
			tempString = "";
		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Matrix tempMatrix;
		tempMatrix.Data = MatrixRows;
		std::string MatrixVariableTemp = "m" + std::to_string(MatrixVariableIndex);
		tempMatrix.Name = MatrixVariableTemp;
		Matrices.push_back(tempMatrix);
		MatrixVariableIndex++;
		//Ū�����\�^��false
		return true;
	}
}

std::vector<Matrix> DataManager::GetMatrices()
{
	return Matrices;
}

bool DataManager::HasMatrix()
{
	if (this->Matrices.size()) {
		return true;
	}
	return false;
}

void DataManager::clear() {
	this->Vectors.clear();
	this->Matrices.clear();
	this->VectorVariableIndex = 0;
	this->MatrixVariableIndex = 0;
}