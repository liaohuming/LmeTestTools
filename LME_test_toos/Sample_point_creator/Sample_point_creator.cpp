#include <iostream>;
#include <fstream>
using namespace std;

int main(int agrc, char* agrv[])
{
	double lowerBound = -1.0;
	double upperBound = 1.0;
	int nodeNum = 14;
	double stepSize = (upperBound - lowerBound) / (nodeNum-1);
	
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
	for (int i = 0; i < nodeNum-1; i++)
	{
		double x = errorPointBeginPos + i*stepSize;

		for (int j = 0; j < nodeNum-1; j++)
		{
			double y = errorPointBeginPos + j*stepSize;
			
			ofs << x << "\t" << y << endl;
			cout << x << "\t" << y << endl;
		}
	}

	system("pause");
	return 0;
}