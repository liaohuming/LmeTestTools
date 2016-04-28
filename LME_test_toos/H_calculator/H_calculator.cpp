#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

vector<double> x1_sample;
vector<double> x2_sample;
vector<double> x3_sample;
vector<double> x1_error;
vector<double> x2_error;
vector<double> x3_error;
vector<double> h_all;
vector<double> h_error_points;
int DIM = 2;

int ReadSamplePoints();
int ReadErrorPoints();
void H_calculator();
void WriteErrorPointH();

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		DIM = atoi(argv[1]);
	}

	if (ReadSamplePoints()!=0)
	{
		return -1;
	}
	if (ReadErrorPoints()!=0)
	{
		return -1;
	}
	
	H_calculator();
	WriteErrorPointH();

	//system("pause");
	return 0;
}

int ReadSamplePoints()
{
	ifstream infile;
	infile.open("SamplePoints.txt");
	if (!infile.is_open())
	{
		cout << "Can not open SamplePoints.txt" << endl;
		return -1;
	}
	while (!infile.eof())
	{
		if (DIM == 2)
		{
			double x1_temp = 0;
			double x2_temp = 0;
			string lineStr = "";
			getline(infile, lineStr);
			sscanf(lineStr.c_str(), "%lg\t%lg\t%*lg", &(x1_temp), &(x2_temp));
			x1_sample.push_back(x1_temp);
			x2_sample.push_back(x2_temp);
		}
		if (DIM == 3)
		{
			double x1_temp = 0;
			double x2_temp = 0;
			double x3_temp = 0;
			string lineStr = "";
			getline(infile, lineStr);
			sscanf(lineStr.c_str(), "%lg\t%lg\t%lg\t%*lg", &(x1_temp), &(x2_temp), &(x3_temp));
			x1_sample.push_back(x1_temp);
			x2_sample.push_back(x2_temp);
			x3_sample.push_back(x3_temp);
		}
	}
	infile.close();

	return 0;
}

int ReadErrorPoints()
{
	ifstream infile;
	infile.open("ErrorPoints.txt");
	if (!infile.is_open())
	{
		cout << "Can not open ErrorPoints.txt" << endl;
		return -1;
	}
	while (!infile.eof())
	{
		if (DIM == 2)
		{
			double x1_temp = 0;
			double x2_temp = 0;
			string lineStr = "";
			getline(infile, lineStr);
			sscanf(lineStr.c_str(), "%lg\t%lg", &(x1_temp), &(x2_temp));
			x1_error.push_back(x1_temp);
			x2_error.push_back(x2_temp);
		}
		if (DIM == 3)
		{
			double x1_temp = 0;
			double x2_temp = 0;
			double x3_temp = 0;
			string lineStr = "";
			getline(infile, lineStr);
			sscanf(lineStr.c_str(), "%lg\t%lg\t%lg", &(x1_temp), &(x2_temp), &(x3_temp));
			x1_error.push_back(x1_temp);
			x2_error.push_back(x2_temp);
			x3_error.push_back(x3_temp);
		}
	}
	infile.close();

	return 0;
}

void H_calculator()
{
	for (int i = 0; i < x1_error.size(); i++)
	{
		if (DIM == 2)
		{
			double x1 = x1_error[i];
			double x2 = x2_error[i];
			double h_temp = 0.0;
			for (int j = 0; j < x1_sample.size(); j++)
			{
				h_temp = sqrt((x1 - x1_sample[j])*(x1 - x1_sample[j]) + 
					(x2 - x2_sample[j])*(x2 - x2_sample[j]));
				h_all.push_back(h_temp);
			}

			double h_min = 0.0;
			for (int k = 0; k < h_all.size(); k++)
			{
				if (k == 0)
				{
					h_min = h_all[0];
				}
				if (h_all[k] < h_min)
				{
					h_min = h_all[k];
				}
			}
			h_error_points.push_back(h_min);
		}

		if (DIM == 3)
		{
			double x1 = x1_error[i];
			double x2 = x2_error[i];
			double x3 = x3_error[i];
			double h_temp = 0.0;
			for (int j = 0; j < x1_sample.size(); j++)
			{
				h_temp = sqrt((x1 - x1_sample[j])*(x1 - x1_sample[j]) + 
					(x2 - x2_sample[j])*(x2 - x2_sample[j]) +
					(x3 - x3_sample[j])*(x3 - x3_sample[j]));
				h_all.push_back(h_temp);
			}

			double h_min = 0.0;
			for (int k = 0; k < h_all.size(); k++)
			{
				if (k == 0)
				{
					h_min = h_all[0];
				}
				if (h_all[k] < h_min)
				{
					h_min = h_all[k];
				}
			}
			h_error_points.push_back(h_min);
		}
	}
}

void WriteErrorPointH()
{
	ofstream ofs;
	ofs.open("h.txt", ios::out|ios::trunc);

	for (int i = 0; i < h_error_points.size(); i++)
	{
		if (i < h_error_points.size() - 1)
		{
			ofs << h_error_points[i] << endl;
			cout << h_error_points[i] << endl;
		}

		//aviod to output last line with an empty line
		if (i == h_error_points.size() -1 )
		{
			ofs << h_error_points[i];
			cout << h_error_points[i];
		}
	}
	ofs.close();
}