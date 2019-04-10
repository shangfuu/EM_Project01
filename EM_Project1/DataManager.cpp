#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取向量ID
		int currentLoadVectorID = 0;
		//定義向量資料暫存變數
		std::vector<double> tempVectorData;
		//定義讀取檔案字串暫存變數
		std::string tempSring = "";
		//從檔案讀取字串，解析掉向量總數
		fin >> tempSring;

		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempSring;
			//解析到向量標記"V"
			if (tempSring == "") {
				break;
			}
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//定義暫存向量資料結構
					Vector tempVector;
					//存入向量資料
					tempVector.Data = tempVectorData;
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string vectorVariableTemp = "v" + std::to_string(VectorVariableIndex);
					//存入向量變數名稱
					tempVector.Name = vectorVariableTemp;
					//存入向量
					Vectors.push_back(tempVector);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					VectorVariableIndex++;
					//清除向量資料暫存
					tempVectorData.clear();
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadVectorID++;
				//從檔案讀取字串，解析掉向量維度
				fin >> tempSring;
			}
			else
			{
				//讀取向量資料，並將string轉為double
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//將向量資料存入暫存
				tempVectorData.push_back(value);
			}
			tempSring = "";
		}
		//讀入輸入檔案中最後一個向量資訊
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//讀取成功回傳false
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
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取向量ID
		int rows = 0, cols = 0;
		int currentLoadMatrixID = 0;
		//定義向量資料暫存變數
		Vector MatrixCols;
		std::vector<Vector> MatrixRows;
		//定義讀取檔案字串暫存變數
		std::string tempString = "";
		//從檔案讀取字串，解析掉向量總數
		fin >> tempString;

		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempString;
			//解析到向量標記"V"
			if (tempString == "") {
				break;
			}
			if (tempString == "M")
			{
				if (currentLoadMatrixID != 0)
				{
					//定義暫存向量資料結構
					Matrix tempMatrix;
					//存入向量資料
					tempMatrix.Data = MatrixRows;
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string MatrixVariableTemp = "m" + std::to_string(MatrixVariableIndex);
					//存入向量變數名稱
					tempMatrix.Name = MatrixVariableTemp;
					//存入向量
					Matrices.push_back(tempMatrix);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					MatrixVariableIndex++;
					//清除向量資料暫存
					MatrixRows.clear();
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadMatrixID++;
				//從檔案讀取字串，解析掉向量維度
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
						//將向量資料存入暫存
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
		//讀入輸入檔案中最後一個向量資訊
		Matrix tempMatrix;
		tempMatrix.Data = MatrixRows;
		std::string MatrixVariableTemp = "m" + std::to_string(MatrixVariableIndex);
		tempMatrix.Name = MatrixVariableTemp;
		Matrices.push_back(tempMatrix);
		MatrixVariableIndex++;
		//讀取成功回傳false
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