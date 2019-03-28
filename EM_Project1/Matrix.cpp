#include "Matrix.h"

Matrix::Matrix()
{
}

void Matrix::print(System::Windows::Forms::TextBox^ Output)
{
	//定意輸出暫存
	System::String^ outputTemp = "";

	outputTemp += "[";
	//將輸出資料存入暫存
	for (unsigned int r = 0; r < this->getRow(); r++)
	{
		for (unsigned int c = 0; c < this->getCol(); c++) {
			outputTemp += this->Data[r].Data[c].ToString();
			if (c != this->Data[r].getDim() - 1)
				outputTemp += ",";
		}
		if (r != this->Data.size() - 1)
			outputTemp += System::Environment::NewLine;
	}
	//將輸出格式存入暫存，並且換行
	outputTemp += "]" + System::Environment::NewLine;
	//輸出暫存資訊
	Output->Text += gcnew System::String(this->Name.c_str()) + " = " + System::Environment::NewLine + outputTemp;


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
	mat.Data.resize(m1.getRow());
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data[i].Data.resize(m2.getCol());
		for (int j = 0; j < m2.getCol(); j++) {
			for (int k = 0; k < m1.getCol(); k++) {
				mat.Data[i].Data[j] += m1.Data[i].Data[k] * m2.Data[k].Data[j];
			}
		}
	}
	return mat;
}

int Matrix::Rank() const
{
	return 1;
}

Matrix Multi_Matrix_Op(array<System::String^> ^userCommand, const std::vector<Matrix>matrices, MATRIX_ERROR& Error)
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
		while (stack.size() > 0 && Error == M_Correct) {
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
	if (Error == M_Correct) {

		// 有無0矩陣
		bool hasZero = false;

		// Calculate
		for (unsigned int i = 0; i < postfix.size(); i++) {
			int top = result.size();

			if (postfix[i] == "+") {
				// RC 一樣才運算
				if (result[top - 2].getRow() != result[top - 1].getRow() || result[top - 2].getCol() != result[top - 1].getCol()) {
					Error = RC_Error;
					break;
				}
				result[top - 2] = result[top - 2] + result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "-") {
				// RC 一樣才運算
				if (result[top - 2].getRow() != result[top - 1].getRow() || result[top - 2].getCol() != result[top - 1].getCol()) {
					Error = RC_Error;
					break;
				}
				result[top - 2] = result[top - 2] - result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "*") {

				// 不同RC
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
						if (matrices[j].Rank() == 0) {
							hasZero = true;
							result.back().Name = "Zero";
						}
					}
				}
			}

			// 處理零矩陣
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
	if (Error != M_Correct) {
		Matrix err;
		err.Name = "Err";
		result.resize(0);
		result.push_back(err);
	}

	return result[0];
}

void Format_One(array<System::String^> ^userCommand, const std::vector<Matrix> matrices, MATRIX_ERROR& Error, Matrix& mat) {

	Error = M_ERROR;
	if (userCommand->Length >= 4 && userCommand[1] == "(" && userCommand[userCommand->Length - 1] == ")") {

		int commas = 0;
		System::String^ tmpString = "";
		array<System::String^> ^Cmd;

		for (int i = 1; i < userCommand->Length - 1; i++) {
			if (userCommand[i] == ",") {
				Error = M_ERROR;
				break;
			}
			if (tmpString->Length == 0) {
				Error = M_Correct;
				tmpString += userCommand[i];
			}
			else {
				tmpString += " " + userCommand[i];
			}
		}
		if (!Error) {
			Cmd = tmpString->Split(' ');
			mat = Multi_Matrix_Op(Cmd, matrices, Error);
			if (mat.getRow() == 0 && Error != RC_Error) {
				Error = M_ERROR;
			}
		}
	}
}

void Format_Two(array<System::String^> ^userCommand, const std::vector<Matrix> matrices, MATRIX_ERROR& Error, Matrix& mat1, Matrix& mat2) {

	if (userCommand->Length >= 6 && userCommand[1] == "(" && userCommand[userCommand->Length - 1] == ")") {
		Error = M_ERROR;
		System::String^ tmpString = "";
		array<System::String^> ^ Cmd1, ^ Cmd2;
		int commas = 0;

		for (int i = 1; i < userCommand->Length - 1; i++) {
			if (userCommand[i] == ",") {
				commas++;
				Error = M_Correct;
				Cmd1 = tmpString->Split(' ');
				tmpString = "";
			}
			if (commas > 1) {
				Error = M_ERROR;
				break;
			}
			if (tmpString->Length == 0) {
				tmpString += userCommand[i];
			}
			else {
				tmpString += " " + userCommand[i];
			}
		}
		if (!Error) {
			Cmd2 = tmpString->Split(' ');
			mat1 = Multi_Matrix_Op(Cmd1, matrices, Error);
			mat2 = Multi_Matrix_Op(Cmd2, matrices, Error);
			// 判斷零矩陣
			if (mat1.Rank() == 0) {
				mat1.Data.resize(mat2.getRow());
				for (int i = 0; i < mat2.getRow(); i++) {
					mat1.Data[i].Data.resize(mat2.Data[i].getDim());
					for (int j = 0; j < mat2.Data[i].getDim(); j++) {
						mat1.Data[i].Data[j] = 0;
					}
				}
			}
			if (mat2.Rank() == 0) {
				mat2.Data.resize(mat1.getRow());
				for (int i = 0; i < mat1.getRow(); i++) {
					mat2.Data[i].Data.resize(mat1.Data[i].getDim());
					for (int j = 0; j < mat1.Data[i].getDim(); j++) {
						mat2.Data[i].Data[j] = 0;
					}
				}
			}

			// 少指令
			if (Error != RC_Error && (mat1.getRow() == 0 || mat2.getRow() == 0)) {
				Error = M_ERROR;
			}
		}
	}
	else {
		Error = M_ERROR;
	}
}
