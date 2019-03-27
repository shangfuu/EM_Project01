#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix mat;
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data.push_back(m1.Data[i] + m2.Data[i]);
	}
	return mat;
}

Matrix operator-(const Matrix & m1, const Matrix & m2)
{
	Matrix mat;
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data.push_back(m1.Data[i] - m2.Data[i]);
	}
	return mat;
}

Matrix operator*(const Matrix & m1, const Matrix & m2)
{
	Matrix mat;
	if (m1.getCol() == m2.getRow()) {

	}
	return mat;
}

Matrix Multi_Matrix_Op(array<System::String^> ^userCommand,const std::vector<Matrix>matrices, MATRIX_ERROR& Error)
{
	// postfix 用來存運算元
	std::vector<std::string> stack;
	std::vector<std::string> postfix;
	std::vector<Matrix> result;

	// Infix to Postfix
	for (unsigned int i = 1; i < userCommand->Length; i++) {
		// 暫存 userCommand
		std::string tmpString;
		MarshalString(userCommand[i], tmpString);

		if (tmpString == "+" || tmpString == "-" || tmpString == "*" || tmpString == "/")
		{
			while (stack.size() > 0 && (priority(stack.back()) >= priority(tmpString))) {
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.push_back(tmpString);
		}
		else if (tmpString == "(")
		{
			stack.push_back(tmpString);
		}
		else if (tmpString == ")")
		{
			while (stack.size() != 0 && stack.back() != "(") {
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.pop_back();
		}
		else {
			/* 判斷並存取指令中的向量 */
			bool isIn = false;
			for (unsigned int j = 0; j < matrices.size(); j++) {
				if (tmpString == matrices[j].Name) {
					isIn = true;
					postfix.push_back(tmpString);
					break;
				}
			}
			if (!isIn) {
				Error = MMO_Error;
				break;
			}
		}
	}

	// 兩變數以上不能沒有運算元
	if (postfix.size() > 1 && stack.size() == 0) {
		Error = MMO_Error;
	}
	else {
		while (stack.size() > 0 && Error == Correct) {
			if (stack.back() == "(") {
				Error = MMO_Error;
				break;
			}
			postfix.push_back(stack.back());
			stack.pop_back();
		}
	}
	if (postfix.size() == 0) Error = MMO_Error;

	// 沒有錯誤才運算
	if (Error == Correct) {

		// 有無0矩陣
		bool hasZero = false;

		// Calculate
		for (unsigned int i = 0; i < postfix.size(); i++) {
			int top = result.size();

			if (postfix[i] == "+") {
				// Dim 一樣才運算
				if (result[top - 2].getRow() != result[top - 1].getRow() || result[top-2].getCol() != result[top-1].getCol()) {
					Error = RC_Error;
					break;
				}
				result[top - 2] = result[top - 2] + result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "-") {
				// Dim 一樣才運算
				if (result[top - 2].getRow() != result[top - 1].getRow() || result[top - 2].getCol() != result[top - 1].getCol()) {
					Error = RC_Error;
					break;
				}
				result[top - 2] = result[top - 2] - result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "*") {

				// 不同維度
				if (result[top - 2].getCol() != result[top - 1].getRow()) {
					Error = RC_Error;
					break;
				}
				// Multi
				else {
					result[top - 2] = result[top - 2] * result[top - 1];
				}
				result.pop_back();
			}
			else {
				// 變數名稱
				for (unsigned int j = 0; j < matrices.size(); j++) {
					if (postfix[i] == matrices[j].Name) {
						result.push_back(matrices[j]);
						// 判斷零矩陣
						if (Rank(matrices[j]) == 0) {
							hasZero = true;
							result.back().Name = "Zero";
						}
					}
				}
			}

			// 處理零向量
			if (hasZero && result.size() == 2) {
				if (result[1].Name == "Zero") {
					result[1].Data.resize(result[0].getRow());
					for (int i = 0; i < result[0].getRow(); i++) {
						result[1].Data[i].Data.resize(result[0].getCol());
						for (int j = 0; j < result[0].getCol(); j++) {
							result[1].Data[i].Data[j] = 0;
						}
					}
				}
				else {
					result[0].Data.resize(result[1].getRow());
					for (int i = 0; i < result[1].getRow(); i++) {
						result[0].Data[i].Data.resize(result[1].getCol());
						for (int j = 0; j < result[1].getCol(); j++) {
							result[0].Data[i].Data[j] = 0;
						}
					}
				}
			}
		}
	}
	else {
		Matrix err;
		err.Name = "Err";
		result.push_back(err);
	}

	return result[0];
}

int Rank(const Matrix &)
{
	return 0;
}


