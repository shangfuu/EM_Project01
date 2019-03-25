#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
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

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

//
//Vector operator + (const Vector& x, const Vector& y) {
//	Vector buff;
//	for (int i = 0; i < x.Data.size(); i++) {
//		buff.Data.push_back(x.Data[i] + y.Data[i]);
//	}
//	return buff;
//}
//
//Vector operator - (const Vector& x, const Vector& y) {
//	Vector buff;
//	for (int i = 0; i < x.Data.size(); i++) {
//		buff.Data.push_back(x.Data[i] - y.Data[i]);
//	}
//	return buff;
//}
//
//Vector operator *(const Vector& x, const Vector& y) {
//	Vector tmp;
//	double dot = 0;
//
//	for (int i = 0; i < x.Data.size(); i++) {
//		dot += (x.Data[i] * y.Data[i]);
//	}
//	tmp.Data.push_back(dot);
//	tmp.Name = "Dot";
//	return tmp;
//}
//
//Vector MyVectors::Scalar(const Vector& vec1, const Vector& vec2)const {
//	Vector vec, scal;
//	vec.Name = "Scalar";
//	if (vec1.getDim() == 1 && vec2.getDim() != 1) {
//		vec = vec2;
//		scal = vec1;
//	}
//	else{
//		vec = vec1;
//		scal = vec2;
//	}
//	for (int i = 0; i < vec.getDim(); i++) {
//		vec.Data[i] = vec.Data[i] * scal.Data[0];
//	}
//	return vec;
//}
//
//double MyVectors::Norm(const Vector& x)const {
//	double sum = 0;
//	for (int i = 0; i < x.getDim(); i++) {
//		sum += pow(x.Data[i], 2);
//	}
//	sum = sqrt(sum);
//	return sum;
//}
//
//Vector MyVectors::Normal(const Vector& x)const {
//	Vector buff;
//	buff.Name = "Normal (" + x.Name + ")";
//	for (int i = 0; i < x.getDim(); i++) {
//		buff.Data.push_back(x.Data[i] / Norm(x));
//	}
//	return buff;
//}
//
//Vector MyVectors::Cross(const Vector& u, const Vector& v)const {
//
//	//Vector buff;
//	//std::vector<double> bx, by;
//	//for (int i = 1; i < x.Data.size(); i++) {	// �q�Ĥ@��}�l�s��̫�@��
//	//	bx.push_back(x.Data[i]);
//	//	by.push_back(y.Data[i]);
//	//}
//	//for (int i = 0; i < 2; i++) {	// �̫�@��s�����^���0��æs���ܲ�1��
//	//	bx.push_back(x.Data[i]);
//	//	by.push_back(y.Data[i]);
//	//}
//	//for (int i = 0; i < bx.size() - 1; i++) {
//	//	int f = i + 1;
//	//	buff.Data.push_back(bx[i] * by[f] - bx[f] * by[i]);
//	//}
//	Vector vec;
//	vec.Name = "Cross";
//	double i = (u.Data[1] * v.Data[2]) - (u.Data[2] * v.Data[1]);
//	vec.Data.push_back(i);
//	double j = -(1.0) * ((u.Data[0] * v.Data[2]) - (u.Data[2] * v.Data[0]));
//	vec.Data.push_back(j);
//	double k = (u.Data[0] * v.Data[1]) - (u.Data[1] * v.Data[0]);
//	vec.Data.push_back(k);
//
//	return vec;
//}
//
//Vector MyVectors::Comp(const Vector& x, const Vector& y)const {
////	double ny = Norm(y);
////	y = Normal(y, ny);
//// 	return (dotv(x, y));
//	Vector vec = x * y;
//	vec.Data[0] = vec.Data[0] / Norm(y);
//	vec.Name = "Comp";
//	return vec;
//}
//
//Vector MyVectors::Proj(const Vector& x, const Vector& y)const {
////	double ny = Norm(y);
////	y = Normal(y, ny);
//	// Vector buff = dotv(y, com);
//	Vector comp = Comp(x, y);
//	Vector normal = Normal(y);
//	Vector vec = Scalar(comp,normal);
//	vec.Name = "Proj";
//	return vec;
//}
//
//double MyVectors::TrigArea(const Vector& x, const Vector& y)const {
//	Vector tmp = x * y;
//	double XdotY = tmp.Data[0];
//	double ans = (sqrt( pow(Norm(x)*Norm(y),2) - pow(XdotY,2) ) ) / 2;
//	return ans;
//}
//
//bool MyVectors::IsParal(const Vector& x, const Vector& y)const {
//	
//	int flag = 0;
//	for (int i = 0; i < x.getDim(); i++) {
//		if (x.Data[i] != 0) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)	return false;
//	for (int i = 0; i < y.getDim(); i++) {
//		if (y.Data[i] != 0) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)	return false;
//	
//	Vector buff = Cross(x, y);
//	for (int i = 0; i < buff.getDim(); i++) {
//		if (buff.Data[i] != 0) {
//			return false;
//		}
//	}
//
//
//	return true;
//}
//
//bool MyVectors::IsOrthog(const Vector& x, const Vector& y) const {
//	// a dot b = 0
//	Vector tmp = x * y;
//	if (tmp.Data[0] == 0) 	return true;
//	else	return false;	
//}
//
//double MyVectors::Angle(const Vector& x, const Vector& y) const {
//	Vector tmp = x * y;
//	double XdotY = tmp.Data[0];
//	double cosv = XdotY / (Norm(x) * Norm(y));
//	return (acos(cosv) * 180 / PI);
//}
//
//bool MyVectors::IsLI(const Vector& x, const Vector& y)const {
//	if (IsParal(x, y)) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//
//std::vector<Vector> MyVectors::Ob(std::vector<Vector> x) const {
//	std::vector<Vector> buff;
////	buff.push_back(Normal(x[0], Norm(x[0])));
//	for (int i = 1; i < x.size(); i++) {
//		Vector temp = x[i];
//		for (int j = 0; j < i; j++) {
//		//	temp = subv(temp, projectv(temp, buff[j]));
//		}
//	//	buff.push_back(Normal(temp, Norm(temp)));
//	}
//	return buff;
//}