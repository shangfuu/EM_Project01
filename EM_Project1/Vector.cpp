#include "Vector.h"
// #define ANNOTATION

Vector::Vector()
{
}

Vector operator + (const Vector& x, const Vector& y) {
	Vector buff;
	for (int i = 0; i < x.Data.size(); i++) {
		buff.Data.push_back(x.Data[i] + y.Data[i]);
	}
	return buff;
}

Vector operator - (const Vector& x, const Vector& y) {
	Vector buff;
	for (int i = 0; i < x.Data.size(); i++) {
		buff.Data.push_back(x.Data[i] - y.Data[i]);
	}
	return buff;
}

Vector operator *(const Vector& x, const Vector& y) {
	Vector tmp;
	double dot = 0;

	for (int i = 0; i < x.Data.size(); i++) {
		dot += (x.Data[i] * y.Data[i]);
	}
	tmp.Data.push_back(dot);
	tmp.Name = "Dot";
	return tmp;
}

Vector Scalar(const Vector& vec1, const Vector& vec2) {
	Vector vec, scal;
	vec.Name = "Scalar";
	if (vec1.getDim() == 1 && vec2.getDim() != 1) {
		vec = vec2;
		scal = vec1;
	}
	else {
		vec = vec1;
		scal = vec2;
	}
	for (int i = 0; i < vec.getDim(); i++) {
		vec.Data[i] = vec.Data[i] * scal.Data[0];
	}
	return vec;
}

double Norm(const Vector& x) {
	double sum = 0;
	for (int i = 0; i < x.getDim(); i++) {
		sum += pow(x.Data[i], 2);
	}
	sum = sqrt(sum);
	return sum;
}

Vector Normal(const Vector& x) {
	Vector buff;
	buff.Name = "Normal (" + x.Name + ")";
	for (int i = 0; i < x.getDim(); i++) {
		buff.Data.push_back(x.Data[i] / Norm(x));
	}
	return buff;
}

Vector Cross(const Vector& u, const Vector& v) {

	//Vector buff;
	//std::vector<double> bx, by;
	//for (int i = 1; i < x.Data.size(); i++) {	// 從第一位開始存到最後一位
	//	bx.push_back(x.Data[i]);
	//	by.push_back(y.Data[i]);
	//}
	//for (int i = 0; i < 2; i++) {	// 最後一位存取完回到第0位並存取至第1位
	//	bx.push_back(x.Data[i]);
	//	by.push_back(y.Data[i]);
	//}
	//for (int i = 0; i < bx.size() - 1; i++) {
	//	int f = i + 1;
	//	buff.Data.push_back(bx[i] * by[f] - bx[f] * by[i]);
	//}
	Vector vec;
	vec.Name = "Cross";
	double i = (u.Data[1] * v.Data[2]) - (u.Data[2] * v.Data[1]);
	vec.Data.push_back(i);
	double j = -(1.0) * ((u.Data[0] * v.Data[2]) - (u.Data[2] * v.Data[0]));
	vec.Data.push_back(j);
	double k = (u.Data[0] * v.Data[1]) - (u.Data[1] * v.Data[0]);
	vec.Data.push_back(k);

	return vec;
}

Vector Comp(const Vector& x, const Vector& y) {
	//	double ny = Norm(y);
	//	y = Normal(y, ny);
	// 	return (dotv(x, y));
	Vector vec = x * y;
	vec.Data[0] = vec.Data[0] / Norm(y);
	vec.Name = "Comp";
	return vec;
}

Vector Proj(const Vector& x, const Vector& y) {
	//	double ny = Norm(y);
	//	y = Normal(y, ny);
	// Vector buff = dotv(y, com);
	Vector comp = Comp(x, y);
	Vector normal = Normal(y);
	Vector vec = Scalar(comp, normal);
	vec.Name = "Proj";
	return vec;
}

double TrigArea(const Vector& x, const Vector& y) {
	Vector tmp = x * y;
	double XdotY = tmp.Data[0];
	double ans = (sqrt(pow(Norm(x)*Norm(y), 2) - pow(XdotY, 2))) / 2;
	return ans;
}

bool IsParal(const Vector& x, const Vector& y) {

	if (x.getDim() != y.getDim()) return false;
	if (Norm(x) == 0 || Norm(y) == 0) return false;

	double length = Norm(x)*Norm(y) * sin(Angle(x, y)*PI / 180);
	if (length == 0) {
		return true;
	}
	return false;
}

bool IsOrthog(const Vector& x, const Vector& y) {
	// a dot b = 0
	Vector tmp = x * y;
	if (tmp.Data[0] == 0) 	return true;
	else	return false;
}

double Angle(const Vector& x, const Vector& y) {
	Vector tmp = x * y;
	double XdotY = tmp.Data[0];
	double cosv = XdotY / (Norm(x) * Norm(y));
	return (acos(cosv) * 180 / PI);
}

bool IsLI(const Vector& x, const Vector& y) {
	// 應該要Call Matrix做
	if (IsParal(x, y)) {
		return false;
	}
	else {
		return true;
	}
}

std::vector<Vector> Ob(const std::vector<Vector>& x) {
	std::vector<Vector> buff;
	buff.push_back(Normal(x[0]));

	for (int i = 1; i < x.size(); i++) {
		Vector temp = x[i];
		for (int j = 0; j < i; j++) {
			temp = temp - Proj(temp, buff[j]);
		}
		buff.push_back(Normal(temp));
	}
	return buff;
}

Vector MVS(array<System::String^> ^userCommand, std::vector<Vector> vectors, VECTOR_ERROR& Error)
{
	// postfix 用來存運算元
	std::vector<std::string> stack;
	std::vector<std::string> postfix;
	std::vector<Vector> result;

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
			for (unsigned int j = 0; j < vectors.size(); j++) {
				if (tmpString == vectors[j].Name) {
					isIn = true;
					postfix.push_back(tmpString);
					break;
				}
			}
			if (!isIn) {
				Error = MVS_Error;
				break;
			}
		}
	}

	// 兩變數或以上不能沒有運算元
	if (postfix.size() > 1 && stack.size() == 0) {
		Error = MVS_Error;
	}
	else {
		while (stack.size() > 0 && Error == Correct) {
			if (stack.back() == "(") {
				Error = MVS_Error;
				break;
			}
			postfix.push_back(stack.back());
			stack.pop_back();
		}
	}
	if (postfix.size() == 0) Error = MVS_Error;

	// 沒有錯誤才運算
	if (Error == Correct) {

		// Calculate
		for (unsigned int i = 0; i < postfix.size(); i++) {
			int top = result.size();

			if (postfix[i] == "+") {
				// Dim 一樣才運算
				if (result[top - 2].getDim() != result[top - 1].getDim()) {
					Error = Dim_Error;
					break;
				}
				result[top - 2] = result[top - 2] + result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "-") {
				// Dim 一樣才運算
				if (result[top - 2].getDim() != result[top - 1].getDim()) {
					Error = Dim_Error;
					break;
				}
				result[top - 2] = result[top - 2] - result[top - 1];
				result.pop_back();
			}
			else if (postfix[i] == "*") {

				// 一向量為 一維執行 Scalar
				if (result[top - 2].getDim() == 1 || result[top - 1].getDim() == 1) {
					result[top - 2] = Scalar(result[top - 1], result[top - 2]);
				}
				// 不同維度
				else if (result[top - 2].getDim() != result[top - 1].getDim()) {
					Error = Dim_Error;
					break;
				}
				// 做 Dot
				else {
					result[top - 2] = result[top - 2] * result[top - 1];
				}
				result.pop_back();
			}
			else {
				// 變數名稱
				for (unsigned int j = 0; j < vectors.size(); j++) {
					if (postfix[i] == vectors[j].Name) {
						result.push_back(vectors[j]);
					}
				}
			}
		}
	}
	else {
		Vector err;
		err.Name = "Err";
		result.push_back(err);
	}

	return result[0];
}

void Format_Two(array<System::String^> ^userCommand, const std::vector<Vector> vectors, VECTOR_ERROR& Error, Vector& vec1, Vector& vec2) {

	if (userCommand->Length >= 6 && userCommand[1] == "(" && userCommand[userCommand->Length - 1] == ")") {
		Error = E_Error;
		System::String^ tmpString = "";
		array<System::String^> ^ Cmd1, ^ Cmd2;
		int commas = 0;

		for (int i = 1; i < userCommand->Length - 1; i++) {
			if (userCommand[i] == ",") {
				commas++;
				Error = Correct;
				Cmd1 = tmpString->Split(' ');
				tmpString = "";
			}
			if (commas > 1) {
				Error = E_Error;
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
			vec1 = MVS(Cmd1, vectors, Error);
			vec2 = MVS(Cmd2, vectors, Error);
			// 少指令
			if (Error != Dim_Error && (vec1.getDim() == 0 || vec2.getDim() == 0)) {
				Error = E_Error;
			}
		}
	}
	else {
		Error = E_Error;
	}
}

void Format_One(array<System::String^> ^userCommand, const std::vector<Vector> vectors, VECTOR_ERROR& Error, Vector& vec) {

	Error = E_Error;
	if (userCommand->Length >= 4 && userCommand[1] == "(" && userCommand[userCommand->Length - 1] == ")") {

		int commas = 0;
		System::String^ tmpString = "";
		array<System::String^> ^Cmd;

		for (int i = 1; i < userCommand->Length - 1; i++) {
			if (userCommand[i] == ",") {
				Error = E_Error;
				break;
			}
			if (tmpString->Length == 0) {
				Error = Correct;
				tmpString += userCommand[i];
			}
			else {
				tmpString += " " + userCommand[i];
			}
		}
		if (!Error) {
			Cmd = tmpString->Split(' ');
			vec = MVS(Cmd, vectors, Error);
			if (vec.getDim() == 0 && Error != Dim_Error) {
				Error = E_Error;
			}
		}
	}
}

void Format_Muti(array<System::String^> ^userCommand, const std::vector<Vector> vectors, VECTOR_ERROR& Error, std::vector<Vector>& vecs)
{
	if (userCommand->Length >= 4 && userCommand[1] == "(" && userCommand[userCommand->Length - 1] == ")") {
		Error = Correct;
		System::String^ tmpString = "";
		array<System::String^> ^tmpCmd;
		array<array<System::String^> ^>^  Cmd = gcnew array<array<System::String^>^>(userCommand->Length);
		
		int commas = 0;

		for (int i = 1; i < userCommand->Length - 1; i++) {
			if (userCommand[i] == ",") {
				tmpCmd = tmpString->Split(' ');
				Cmd[commas++] = tmpCmd;
				tmpString = "";
			}
			if (tmpString->Length == 0) {
				tmpString += userCommand[i];
			}
			else {
				tmpString += " " + userCommand[i];
			}
		}
		// 補最後一個
		tmpCmd = tmpString->Split(' ');
		Cmd[commas++] = tmpCmd;
		Cmd->Resize(Cmd, commas);
		
		for (unsigned int i = 0; i < Cmd->Length; i++) {
			vecs.push_back(MVS(Cmd[i], vectors, Error));
			// 少指令
			if (Error != Dim_Error && vecs[i].getDim() == 0) {
				Error = E_Error;
				break;
			}
		}
	}
	else {
		Error = E_Error;
	}
}

// Infix to Postfix Used
int priority(std::string op) {
	if (op == "+" || op == "-")	return 1;
	else if (op == "*" || op == "/") return 2;
	else return 0;
}