#include <iostream>;
#include <fstream>
using namespace std;

int main(int agrc, char* agrv[])
{
	double lowerBound = 2.1;
	double upperBound = 9.9;
	int nodeNum = 8;
	double stepSize = (upperBound - lowerBound) / (nodeNum-1);
	int DIM = 3;

	if (DIM==2)
	{
		ofstream ofs;
		ofs.open("UniformSamplingPoints.txt", ofstream::out);
		for (int i = 0; i < nodeNum; i++)
		{
			double x = lowerBound + i*stepSize;
			for (int j = 0; j < nodeNum; j++)
			{
				double y = lowerBound + j*stepSize;
				ofs << x << "\t" << y << endl;
				cout << x << "\t" << y << endl;
			}
		}
		ofs << endl;

		double errorPointBeginPos = lowerBound + stepSize / 2;
		for (int i = 0; i < nodeNum - 1; i++)
		{
			double x = errorPointBeginPos + i*stepSize;

			for (int j = 0; j < nodeNum - 1; j++)
			{
				double y = errorPointBeginPos + j*stepSize;

				ofs << x << "\t" << y << endl;
				cout << x << "\t" << y << endl;
			}
		}
	}
	if (DIM==3)
	{
		ofstream ofs;
		ofs.open("UniformSamplingPoints.txt", ofstream::out);
		for (int i = 0; i < nodeNum; i++)
		{
			double x = lowerBound + i*stepSize;
			for (int j = 0; j < nodeNum; j++)
			{
				double y = lowerBound + j*stepSize;
				for (int k = 0; k < nodeNum; k++)
				{
					double z = lowerBound + k*stepSize;
					ofs << x << "\t" << y << "\t" << z << endl;
					cout << x << "\t" << y << "\t" << z << endl;
				}				
			}
		}
		ofs << endl;

		double errorPointBeginPos = lowerBound + stepSize / 2;
		for (int i = 0; i < nodeNum - 1; i++)
		{
			double x = errorPointBeginPos + i*stepSize;
			for (int j = 0; j < nodeNum - 1; j++)
			{
				double y = errorPointBeginPos + j*stepSize;
				for (int k = 0; k < nodeNum-1; k++)
				{
					double z = errorPointBeginPos + k*stepSize;
					ofs << x << "\t" << y << "\t" << z << endl;
					cout << x << "\t" << y << "\t" << z << endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}