#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream infile;

	// Read sampling points
	vector<string> x1_vextor;
	vector<string> x2_vextor;
	vector<string> y_vextor;

	infile.open("RBF-Init-Data-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}

	int rowNumOfSamplingPoints = 0;
	string lineStrOfSamplingPoints = "";
	getline(infile, lineStrOfSamplingPoints);
	while (lineStrOfSamplingPoints !="")
	{
		if (rowNumOfSamplingPoints ==0 )	// 第一行不读取
		{
			rowNumOfSamplingPoints++;
		}
		else
		{
			char x1_char[255];
			char x2_char[255];
			char y_char[255];
			sscanf(lineStrOfSamplingPoints.c_str(), "%*s\t%s\t%s\t%s", &(x1_char), &(x2_char), &(y_char));
			string x1_str = string(x1_char);
			string x2_str = string(x2_char);
			string y_str = string(y_char);
			x1_vextor.push_back(x1_str);
			x2_vextor.push_back(x2_str);
			y_vextor.push_back(y_str);
		}
		getline(infile, lineStrOfSamplingPoints);
	}
	infile.close();

	// Output sampling points,最后不输出空行
	cout << "Isight_sample_points_data" << endl;
	ofstream ofs_sampling_points;
	ofs_sampling_points.open("SamplePoints.txt", ofstream::out);
	for (int i = 0; i < x1_vextor.size(); i++)
	{
		if (i < x1_vextor.size()-1)
		{
			ofs_sampling_points << x1_vextor[i] << "\t" << x2_vextor[i] << "\t" << y_vextor[i] << endl;
		}
		if (i == x1_vextor.size() - 1)
		{
			ofs_sampling_points << x1_vextor[i] << "\t" << x2_vextor[i] << "\t" << y_vextor[i];
		}	
		cout << x1_vextor[i] << "\t" << x2_vextor[i] << "\t" << y_vextor[i] << endl;
	}
	ofs_sampling_points.close();

	// Read error analysis points
	vector<string> x1_error_vextor;
	vector<string> x2_error_vextor;
	vector<string> y_error_vector;
	infile.open("RBF-Actual-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}

	int rowNumOfErrorPoints = 0;
	string lineStrOfErrorPoints = "";
	getline(infile, lineStrOfErrorPoints);
	while (lineStrOfErrorPoints != "")
	{
		if (rowNumOfErrorPoints == 0)	// 第一行不读取
		{
			rowNumOfErrorPoints++;
		}
		else
		{
			char x1_char[255];
			char x2_char[255];
			char y_char[255];
			sscanf(lineStrOfErrorPoints.c_str(), "%*s\t%s\t%s\t%s", &(x1_char), &(x2_char),&(y_char));
			string x1_str = string(x1_char);
			string x2_str = string(x2_char);
			string y_str = string(y_char);
			x1_error_vextor.push_back(x1_str);
			x2_error_vextor.push_back(x2_str);
			y_error_vector.push_back(y_str);
		}
		getline(infile, lineStrOfErrorPoints);
	}
	infile.close();

	// Output error analysis points，最后不输出空行
	cout << "ErrorPoints" << endl;
	ofstream ofs_error_points;
	ofs_error_points.open("ErrorPoints.txt", ofstream::out);
	for (int i = 0; i < x1_error_vextor.size(); i++)
	{
		if (i < x1_error_vextor.size()-1)
		{
			ofs_error_points << x1_error_vextor[i] << "\t" << x2_error_vextor[i] << endl;
		}
		if (i == x1_error_vextor.size() - 1)
		{
			ofs_error_points << x1_error_vextor[i] << "\t" << x2_error_vextor[i];
		}	
		cout << x1_error_vextor[i] << "\t" << x2_error_vextor[i] << endl;
	}
	ofs_error_points.close();

	// Output error actual value，最后不输出空行
	cout << "ErrorPoints_actual_value.txt" << endl;
	ofstream ofs_error_points_actual_value;
	ofs_error_points_actual_value.open("ErrorPoints_actual_value.txt", ofstream::out);
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
		cout << x1_error_vextor[i] << endl;
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
		return -1;
	}
	while (!infile.eof())
	{		
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read RSM-2 Predicted Value
	infile.open("RSM-2-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read RSM-4 Predicted Value
	infile.open("RSM-4-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr!="")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging1 Predicted Value
	infile.open("Kriging1-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging2 Predicted Value
	infile.open("Kriging2-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging3 Predicted Value
	infile.open("Kriging3-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	// Read Kriging4 Predicted Value
	infile.open("Kriging4-Predicted-Error-Points.txt");
	if (!infile.is_open())
	{
		return -1;
	}
	while (!infile.eof())
	{
		char y_char[255];
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			sscanf(lineStr.c_str(), "%*s\t%*s\t%*s\t%s", &(y_char));
			string y_str = string(y_char);
			Isight_predicted_data.push_back(y_str);
		}
	}
	infile.close();

	cout << "Isight_predicted_data" << endl;
	ofstream ofs;
	ofs.open("Isight_predicted_data.txt", ofstream::out);
	for (int i = 0; i < Isight_predicted_data.size(); i++)
	{
		ofs << Isight_predicted_data[i] << endl;	//最后一行输出空行
		cout << Isight_predicted_data[i] << endl;
	}
	ofs.close();
	system("pause");
	return 0;
}