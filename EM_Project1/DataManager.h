#pragma once
#include "Vector.h"
#include "Matrix.h"

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;

	//儲存矩陣資料
	std::vector<Matrix> Matrices;
	//紀錄矩陣ID，用於控管
	int MatrixVariableIndex;

	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	//判斷有沒有load Vector
	bool HasVector();

	//讀取向量資料
	bool LoadMatrixData();
	//取得向量資料
	std::vector<Matrix> GetMatrices();
	//判斷有沒有load Matrix
	bool HasMatrix();

	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	
};