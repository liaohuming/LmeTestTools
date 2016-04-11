#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
using namespace std;

double Calc_uRange(vector<double> u);
int Calc_nModel(void);

int main(int argc, char* argv[])
{
	ifstream infile;

	// Read error points real value
	vector<double> u;
	infile.open("ErrorPoints_actual_value.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		double u_temp = 0;
		string lineStr = "";
		getline(infile, lineStr);
		sscanf(lineStr.c_str(), "%lg", &(u_temp));	
		u.push_back(u_temp);
	}
	infile.close();

	// Calculate u range
	double uRange = Calc_uRange(u);

	// Cound surrogate model number
	int n_model = Calc_nModel();

	// Read error points predicted value
	//vector<vector<double>> uh_n(n_model);
	//infile.open("ErrorPointsPredictedValue.txt");
	//if (!infile.is_open())
	//{
	//	return -1;
	//}
	//while (!infile.eof())
	//{
	//	/*
	//	lineData为ErrorPointsPredictedValue.txt中的一行数据，
	//	一行数据有n列，每列代表一种代理模型得到的一个预测值，
	//	每列的值保存在uh_n[index]中，代表n种代理模型中的第
	//	index种（亦即第index列）
	//	*/
	//	string lineStr = "";
	//	getline(infile, lineStr);
	//	char lineChar[255] = { 0 };
	//	strcpy(lineChar, lineStr.c_str());

	//	const char *delimter = "\t";
	//	char *uh_char;
	//	uh_char = strtok(lineChar, delimter);
	//	int index = 0;
	//	while (uh_char)
	//	{
	//		uh_n[index].push_back(atof(uh_char));
	//		index++;
	//		uh_char = strtok(NULL, delimter);
	//	}
	//}
	//infile.close();

	// Read Isight_predicted_data.txt
	vector<vector<double>> uh_n(n_model);
	infile.open("Isight_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	int index = -1;
	string lineStr = "";
	getline(infile, lineStr);
	while (lineStr != "")
	{
		if (lineStr == "y")
		{
			index++;
		}
		else
		{
			uh_n[index].push_back(atof(lineStr.c_str()));
		}
		getline(infile, lineStr);
	}
	infile.close(); 
	
	// Read LME_predicted_data.txt
	infile.open("LME_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	getline(infile, lineStr);
	while (lineStr != "")
	{
		if (lineStr == "y")
		{
			index++;
		}
		else
		{
			uh_n[index].push_back(atof(lineStr.c_str()));
		}
		getline(infile, lineStr);
	}
	infile.close();

	// Calculate average value of the real value
	double u_mean = 0;
	for (int i = 0; i < u.size(); i++)
	{
		u_mean += abs(u[i]);
	}
	u_mean = u_mean / u.size();

	// Write predicted value
	ofstream ofs("Error_analysis_results.txt", ofstream::out);
	ofs << "L2\tR_square\tNRMSE" << endl;
	cout << "L2\tR_square\tNRMSE" << endl;
	for (int i = 0; i < uh_n.size(); i++)
	{
		double Math_error = 0;		// the overall error
		double R_square = 0;		// Coefficient of determination
		double NRMSE = 0;			// Normalized Root mean squared error
		double numerator = 0;
		double denominator_Math_error = 0;
		double denominator_R_square = 0;

		for (int j = 0; j < u.size(); j++)
		{
			numerator += (u[j] - uh_n[i][j])*(u[j] - uh_n[i][j]);
			denominator_Math_error += u[j] * u[j];
			denominator_R_square += (u[j] - u_mean)*(u[j] - u_mean);
		}
		Math_error = sqrt(numerator / denominator_Math_error);
		R_square = 1 - numerator / denominator_R_square;
		NRMSE = sqrt(numerator / u.size()) / uRange;

		ofs << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
		cout << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
	}

	system("pause");
	return 0;
}

double Calc_uRange(vector<double> u)
{
	double u_max = 0;
	double u_min = 0;

	for (int i = 0; i<u.size(); i++)
	{
		if (i == 0)
		{
			u_max = u_min = u[0];
		}
		if (u[i]>u_max)
		{
			u_max = u[i];
		}
		if (u[i]<u_min)
		{
			u_min = u[i];
		}
	}
	return u_max-u_min;
}

int Calc_nModel(void)
{
	//ifstream infile;
	//infile.open("ErrorPointsPredictedValue.txt");
	//if (!infile.is_open())
	//{
	//	return -1;
	//}
	///*
	//获取一行数据，计算该行数据由几列，一列代表一种代理模型
	//*/
	//string lineStr = "";
	//getline(infile, lineStr);
	//char lineChar[255] = { 0 };
	//strcpy(lineChar, lineStr.c_str());

	//const char *delimter = "\t";
	//char *uh_char;
	//uh_char = strtok(lineChar, delimter);
	//int n_model = 0;
	//while (uh_char)
	//{
	//	n_model++;
	//	uh_char = strtok(NULL, delimter);
	//}
	//infile.close();

	ifstream infile;
	int n_model = 0;
	infile.open("Isight_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}

	string lineStr = "";
	getline(infile, lineStr);
	while (lineStr!="")
	{
		if (lineStr=="y")
		{
			n_model++;
		}
		getline(infile, lineStr);
	}
	infile.close();

	infile.open("LME_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	getline(infile, lineStr);
	while (lineStr != "")
	{
		if (lineStr == "y")
		{
			n_model++;
		}
		getline(infile, lineStr);
	}
	infile.close();
	return n_model;
}