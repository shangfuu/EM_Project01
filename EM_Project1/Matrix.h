#pragma once
#include<vector>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>
#define PI 3.14159265358979323846

/***Error Type***/
enum MATRIX_ERROR {

};

//©w¸q Matrix
class Matrix
{	
public:
	std::string Name;
	std::vector<std::vector<double>> Data;
	Matrix();
};