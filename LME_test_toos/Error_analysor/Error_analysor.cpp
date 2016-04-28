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
void IsightErrorAnalysis();
void AllErrorAnalysis();

int main(int argc, char* argv[])
{
	//IsightErrorAnalysis();
	AllErrorAnalysis();

	//system("pause");
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
	/*
	根据y的数量计算有多少种代理模型
	*/

	ifstream infile;
	int n_model = 0;
	infile.open("Isight_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr == "y")
		{
			n_model++;
		}
	}
	infile.close();

	infile.open("LME_predicted_data.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr == "y")
		{
			n_model++;
		}
	}
	infile.close();
	return n_model;
}

void IsightErrorAnalysis()
{
	ifstream infile;

	// Read error points real value
	vector<double> u;
	infile.open("ErrorPoints_actual_value.txt");
	if (!infile.is_open())
	{
		return;
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

	// Read Isight_predicted_data.txt
	int index = -1;
	vector<vector<double> > uh_n(n_model);
	infile.open("Isight_predicted_data.txt");
	if (!infile.is_open())
	{
		return;
	}
	while (!infile.eof())
	{
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr == "y")
		{
			index++;
		}
		else
		{
			uh_n[index].push_back(atof(lineStr.c_str()));
		}
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

		//aviod to output last line with an empty line
		if (i < uh_n.size() - 1)
		{
			ofs << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
			cout << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
		}
		if (i == uh_n.size() - 1)
		{
			ofs << Math_error << "\t" << R_square << "\t" << NRMSE;
			cout << Math_error << "\t" << R_square << "\t" << NRMSE;
		}
	}
}

void AllErrorAnalysis()
{
	ifstream infile;

	// Read error points real value
	vector<double> u;
	infile.open("ErrorPoints_actual_value.txt");
	if (!infile.is_open())
	{
		return;
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

	// Read Isight_predicted_data.txt
	int index = -1;
	vector<vector<double> > uh_n(n_model);
	infile.open("Isight_predicted_data.txt");
	if (!infile.is_open())
	{
		return;
	}
	while (!infile.eof())
	{
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr == "y")
		{
			index++;
		}
		else
		{
			uh_n[index].push_back(atof(lineStr.c_str()));
		}
	}
	infile.close();

	// Read LME_predicted_data.txt
	infile.open("LME_predicted_data.txt");
	if (!infile.is_open())
	{
		return;
	}
	while (!infile.eof())
	{
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr == "y")
		{
			index++;
		}
		else
		{
			uh_n[index].push_back(atof(lineStr.c_str()));
		}
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

		//aviod to output last line with an empty line
		if (i < uh_n.size()-1)
		{
			ofs << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
			cout << Math_error << "\t" << R_square << "\t" << NRMSE << endl;
		}
		if (i == uh_n.size()-1)
		{
			ofs << Math_error << "\t" << R_square << "\t" << NRMSE;
			cout << Math_error << "\t" << R_square << "\t" << NRMSE;
		}
	}
}