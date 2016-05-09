#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int TYPE = 1;	// 1 means create error point, 2 means create both sample points and error points
int DIM = 2;
int POINTNUM = 8;
double LOWERBOUND = -1;
double UPPERBOUND = 1;

int main(int argc, char* argv[])
{
	if (argc != 6)
	{
		cout << "missing inputs:" << endl;
		cout << "./0_uniformSampler <type> <dimension> <point number> <lower bound> <upper bound>" << endl;
		cout << "1. type: 1 means create error point, 2 means create sample points" << endl;
		cout << "2. dimension: 2 means 2 dimesnsion, 3 means 3 dimension. Only support 2 and 3 dimension, more dimensions being developed." << endl;
		cout << "3. point number: points on each direction" << endl;
		cout << "4. lower bound: the lower bound of the variables" << endl;
		cout << "5. upper bound: the upper bound of the variables" << endl;

		return -1;
	}
	if (argc == 6)
	{
		TYPE= atoi(argv[1]);
		DIM = atoi(argv[2]);
		POINTNUM = atoi(argv[3]);
		LOWERBOUND = atof(argv[4]);
		UPPERBOUND = atof(argv[5]);	
	}


	double stepSize = 0.0;
	if (TYPE == 1)
	{
		stepSize = (UPPERBOUND - LOWERBOUND) / POINTNUM;
	}
	if (TYPE == 2)
	{
		stepSize = (UPPERBOUND - LOWERBOUND) / (POINTNUM - 1);
	}
	
	if (DIM == 2)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double y = errorPointBeginPos + j*stepSize;
					ofs << x << "\t" << y << endl;
					cout << x << "\t" << y << endl;
				}
			}
			ofs.close();
		}
		if (TYPE == 2)
		{
			ofstream ofs;
			ofs.open("UniformSamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double y = LOWERBOUND + j*stepSize;
					ofs << x << "\t" << y << endl;
					cout << x << "\t" << y << endl;
				}
			}
			ofs.close();

			/*
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM - 1; i++)
			{
				double x = errorPointBeginPos + i*stepSize;

				for (int j = 0; j < POINTNUM - 1; j++)
				{
					double y = errorPointBeginPos + j*stepSize;
					ofs << x << "\t" << y << endl;
					cout << x << "\t" << y << endl;
				}
			}
			ofs.close();
			*/
		}
		
	}
	if (DIM == 3)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double y = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double z = errorPointBeginPos + k*stepSize;
						ofs << x << "\t" << y << "\t" << z << endl;
						cout << x << "\t" << y << "\t" << z << endl;
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 2)
		{
			ofstream ofs;
			ofs.open("UniformSamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double y = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double z = LOWERBOUND + k*stepSize;
						ofs << x << "\t" << y << "\t" << z << endl;
						cout << x << "\t" << y << "\t" << z << endl;
					}
				}
			}
			ofs.close();

			/*
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM - 1; i++)
			{
				double x = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM - 1; j++)
				{
					double y = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM - 1; k++)
					{
						double z = errorPointBeginPos + k*stepSize;
						ofs << x << "\t" << y << "\t" << z << endl;
						cout << x << "\t" << y << "\t" << z << endl;
					}
				}
			}
			ofs.close();
			*/
		}	
	}

	//system("pause");
	return 0;
}