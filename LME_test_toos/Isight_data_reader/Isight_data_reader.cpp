#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{	
	int DIM = 2;

	if (argc != 2)
	{
		cout << "missing inputs:" << endl;
		cout << "./1_isightDataReader <dimension>" << endl;
		cout << "only support 2-10 dimension, more dimensions being developed." << endl;
		cout << endl;
		cout << "necessary files:" << endl;
		cout << "RBF-Init-Data-Points.txt" << endl;
		cout << "RBF-Actual-Error-Points.txt" << endl;
		cout << "RBF-Predicted-Error-Points.txt" << endl;
		cout << "RSM2-Predicted-Error-Points" << endl;
		cout << "RSM4-Predicted-Error-Points" << endl;
		cout << "Kriging1-Predicted-Error-Points.txt" << endl;
		cout << "Kriging2-Predicted-Error-Points.txt" << endl;
		cout << "Kriging3-Predicted-Error-Points.txt" << endl;
		cout << "Kriging4-Predicted-Error-Points.txt" << endl;

		return -1;
	}
	if (argc == 2)
	{
		DIM = atoi(argv[1]);
	}

	// Read sampling points
	vector<string> x1_vector;
	vector<string> x2_vector;
	vector<string> x3_vector;
	vector<string> x4_vector;
	vector<string> x5_vector;
	vector<string> x6_vector;
	vector<string> x7_vector;
	vector<string> x8_vector;
	vector<string> x9_vector;
	vector<string> x10_vector;
	vector<string> y_vector;

	ifstream infile;
	infile.open("RBF-Init-Data-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open RBF-Init-Data-Points.txt" << endl;
		//return -1;
	}

	int rowNumOfSamplingPoints = 0;
	while (!infile.eof())
	{
		string lineStrOfSamplingPoints = "";
		getline(infile, lineStrOfSamplingPoints);
		if (lineStrOfSamplingPoints != "")
		{
			if (rowNumOfSamplingPoints == 0)	// 第一行不读取
			{
				rowNumOfSamplingPoints++;
			}
			else
			{
				if (DIM == 2)
				{
					char x1_char[255];
					char x2_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 3)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 4)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 5)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 6)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					x6_vector.push_back(x6_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 7)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					x6_vector.push_back(x6_str);
					x7_vector.push_back(x7_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 8)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					x6_vector.push_back(x6_str);
					x7_vector.push_back(x7_str);
					x8_vector.push_back(x8_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 9)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char x9_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(x9_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string x9_str = string(x9_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					x6_vector.push_back(x6_str);
					x7_vector.push_back(x7_str);
					x8_vector.push_back(x8_str);
					x9_vector.push_back(x9_str);
					y_vector.push_back(y_str);
				}
				if (DIM == 10)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char x9_char[255];
					char x10_char[255];
					char y_char[255];
					sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(x9_char), &(x10_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string x9_str = string(x9_char);
					string x10_str = string(x10_char);
					string y_str = string(y_char);
					x1_vector.push_back(x1_str);
					x2_vector.push_back(x2_str);
					x3_vector.push_back(x3_str);
					x4_vector.push_back(x4_str);
					x5_vector.push_back(x5_str);
					x6_vector.push_back(x6_str);
					x7_vector.push_back(x7_str);
					x8_vector.push_back(x8_str);
					x9_vector.push_back(x9_str);
					x10_vector.push_back(x10_str);
					y_vector.push_back(y_str);
				}
			}
		}
	}
	infile.close();
	
	// Output sampling points,最后不输出空行
	cout << "Isight_sample_points_data" << endl;
	ofstream ofs_sampling_points;
	ofs_sampling_points.open("SamplePoints.txt", ios::out | ios::trunc);
	for (int i = 0; i < x1_vector.size(); i++)
	{
		if (DIM == 2)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i]  << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 3)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 4)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 5)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 6)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 7)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 8)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 9)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << y_vector[i] << endl;
		}
		if (DIM == 10)
		{
			if (i < x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << x10_vector[i] << "\t" << y_vector[i] << endl;
			}
			if (i == x1_vector.size() - 1)
			{
				ofs_sampling_points << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << x10_vector[i] << "\t" << y_vector[i];
			}
			cout << x1_vector[i] << "\t" << x2_vector[i] << "\t" << x3_vector[i] << "\t" << x4_vector[i] << "\t" << x5_vector[i] << "\t" << x6_vector[i] << "\t" << x7_vector[i] << "\t" << x8_vector[i] << "\t" << x9_vector[i] << "\t" << x10_vector[i] << "\t" << y_vector[i] << endl;
		}
	}
	ofs_sampling_points.close();

	// Read error analysis points
	vector<string> x1_error_vector;
	vector<string> x2_error_vector;
	vector<string> x3_error_vector;
	vector<string> x4_error_vector;
	vector<string> x5_error_vector;
	vector<string> x6_error_vector;
	vector<string> x7_error_vector;
	vector<string> x8_error_vector;
	vector<string> x9_error_vector;
	vector<string> x10_error_vector;
	vector<string> y_error_vector;
	infile.open("RBF-Actual-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open RBF-Actual-Error-Points.txt" << endl;
		//return -1;
	}

	int rowNumOfErrorPoints = 0;
	while (!infile.eof())
	{
		string lineStrOfErrorPoints = "";
		getline(infile, lineStrOfErrorPoints);
		if (lineStrOfErrorPoints != "")
		{
			if (rowNumOfErrorPoints == 0)	// 第一行不读取
			{
				rowNumOfErrorPoints++;
			}
			else
			{
				if (DIM == 2)
				{
					char x1_char[255];
					char x2_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 3)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 4)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 5)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 6)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					x6_error_vector.push_back(x6_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 7)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					x6_error_vector.push_back(x6_str);
					x7_error_vector.push_back(x7_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 8)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					x6_error_vector.push_back(x6_str);
					x7_error_vector.push_back(x7_str);
					x8_error_vector.push_back(x8_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 9)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char x9_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(x9_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string x9_str = string(x9_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					x6_error_vector.push_back(x6_str);
					x7_error_vector.push_back(x7_str);
					x8_error_vector.push_back(x8_str);
					x9_error_vector.push_back(x9_str);
					y_error_vector.push_back(y_str);
				}
				if (DIM == 10)
				{
					char x1_char[255];
					char x2_char[255];
					char x3_char[255];
					char x4_char[255];
					char x5_char[255];
					char x6_char[255];
					char x7_char[255];
					char x8_char[255];
					char x9_char[255];
					char x10_char[255];
					char y_char[255];
					sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(x3_char), &(x4_char), &(x5_char), &(x6_char), &(x7_char), &(x8_char), &(x9_char), &(x10_char), &(y_char));
					string x1_str = string(x1_char);
					string x2_str = string(x2_char);
					string x3_str = string(x3_char);
					string x4_str = string(x4_char);
					string x5_str = string(x5_char);
					string x6_str = string(x6_char);
					string x7_str = string(x7_char);
					string x8_str = string(x8_char);
					string x9_str = string(x9_char);
					string x10_str = string(x10_char);
					string y_str = string(y_char);
					x1_error_vector.push_back(x1_str);
					x2_error_vector.push_back(x2_str);
					x3_error_vector.push_back(x3_str);
					x4_error_vector.push_back(x4_str);
					x5_error_vector.push_back(x5_str);
					x6_error_vector.push_back(x6_str);
					x7_error_vector.push_back(x7_str);
					x8_error_vector.push_back(x8_str);
					x9_error_vector.push_back(x9_str);
					x10_error_vector.push_back(x10_str);
					y_error_vector.push_back(y_str);
				}
			}
		}
	}
	infile.close();
	

// 误差分析点在Uniform_sampler中生成，此处不需要再输出

	// Output error analysis points，最后不输出空行
	cout << "ErrorPoints" << endl;
	ofstream ofs_error_points;
	ofs_error_points.open("ErrorPoints.txt", ios::out | ios::trunc);
	for (int i = 0; i < x1_error_vector.size(); i++)
	{
		if (DIM == 2)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << endl;
		}
		if (DIM == 3)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << endl;
		}
		if (DIM == 4)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << endl;
		}
		if (DIM == 5)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << endl;
		}
		if (DIM == 6)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << endl;
		}
		if (DIM == 7)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << endl;
		}
		if (DIM == 8)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << endl;
		}
		if (DIM == 9)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i] << endl;
		}
		if (DIM == 10)
		{
			if (i < x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i] << "\t" << x10_error_vector[i] << endl;
			}
			if (i == x1_error_vector.size() - 1)
			{
				ofs_error_points << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i] << "\t" << x10_error_vector[i];
			}
			cout << x1_error_vector[i] << "\t" << x2_error_vector[i] << "\t" << x3_error_vector[i] << "\t" << x4_error_vector[i] << "\t" << x5_error_vector[i] << "\t" << x6_error_vector[i] << "\t" << x7_error_vector[i] << "\t" << x8_error_vector[i] << "\t" << x9_error_vector[i] << "\t" << x10_error_vector[i] << endl;
		}
		
	}
	ofs_error_points.close();


	// Output error actual value，最后不输出空行
	cout << "ErrorPoints_actual_value.txt" << endl;
	ofstream ofs_error_points_actual_value;
	ofs_error_points_actual_value.open("ErrorPoints_actual_value.txt", ios::out | ios::trunc);
	for (int i = 0; i < y_error_vector.size(); i++)//
	{
		if (i < y_error_vector.size()-1)
		{
			ofs_error_points_actual_value << y_error_vector[i] << endl;
		}
		if (i == y_error_vector.size()-1)
		{
			ofs_error_points_actual_value << y_error_vector[i];
		}
		cout << y_error_vector[i] << endl;
	}
	ofs_error_points_actual_value.close();

	/*
		Read Isight_predicted_data
	*/
	vector<string> Isight_predicted_data;

	// Read RBF Predicted Value
	infile.open("RBF-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open RBF-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read RSM-2 Predicted Value
	infile.open("RSM2-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open RSM2-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read RSM-4 Predicted Value
	infile.open("RSM4-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open RSM4-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();
	
	// Read Kriging1 Predicted Value
	infile.open("Kriging1-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open Kriging1-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging2 Predicted Value
	infile.open("Kriging2-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open Kriging2-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging3 Predicted Value
	infile.open("Kriging3-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open Kriging3-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging4 Predicted Value
	infile.open("Kriging4-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		cout << "Can not open Kriging4-Predicted-Error-Points.txt" << endl;
		//return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 4)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 5)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 6)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 7)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 8)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 9)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			if (DIM == 10)
			{
				sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%s", &(y_char));
			}
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	cout << "Isight_predicted_data" << endl;
	ofstream ofs;
	ofs.open("Isight_predicted_data.txt", ios::out | ios::trunc);
	for (int i = 0; i < Isight_predicted_data.size(); i++)
	{
		if (i < Isight_predicted_data.size()-1)
		{
			ofs << Isight_predicted_data[i] << endl;
			cout << Isight_predicted_data[i] << endl;
		}
		if (i == Isight_predicted_data.size()-1)
		{
			ofs << Isight_predicted_data[i];
			cout << Isight_predicted_data[i];
		}	
	}
	ofs.close();
	//system("pause");
	return 0;
}