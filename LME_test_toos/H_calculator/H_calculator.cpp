#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct SamplePoint
{
	int id;
	double x[3];
	double h_min;
};
vector<SamplePoint> x_sp;
int ReadSamplePoints();
int Cmp(const void *a, const void *b);
void CalcSample_H(int id);

struct ErrorPoint
{
	double x[3];
	int sp_id;
	double h;
};
vector<ErrorPoint> x_ep;
int ReadErrorPoints();
void CalcError_H();
void WriteErrorPointH();

int DIM = 2;
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

	for (int i = 0; i < x_sp.size(); i++)
	{
		CalcSample_H(i);
	}

	if (ReadErrorPoints()!=0)
	{
		return -1;
	}

	CalcError_H();
	WriteErrorPointH();

	system("pause");
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
	int index = 0;
	while (!infile.eof())
	{
		SamplePoint sp;
		string lineStr = "";
		getline(infile, lineStr);
		if (DIM == 2)
		{		
			sscanf(lineStr.c_str(), "%lg\t%lg\t%*lg", &(sp.x[0]), &(sp.x[1]));	
		}
		if (DIM == 3)
		{
			sscanf(lineStr.c_str(), "%lg\t%lg\t%lg\t%*lg", &(sp.x[0]), &(sp.x[1]), &(sp.x[2]));
		}
		sp.id = index;
		sp.h_min = 0.0;
		x_sp.push_back(sp);
		index++;
	}
	infile.close();

	return 0;
}

int Cmp(const void *a, const void *b)
{
	return *(double *)a > *(double *)b ? 1 : -1;
}

void CalcSample_H(int id)
{
	double *h_all = new double[x_sp.size()];
	for (int i = 0; i < x_sp.size(); i++)
	{
		double h_temp = 0.0;
		if (DIM == 2)
		{
			h_temp = sqrt((x_sp[id].x[0] - x_sp[i].x[0])*(x_sp[id].x[0] - x_sp[i].x[0]) +
				(x_sp[id].x[1] - x_sp[i].x[1])*(x_sp[id].x[1] - x_sp[i].x[1]));
			h_all[i] = h_temp;
		}
		if (DIM == 3)
		{
			h_temp = sqrt((x_sp[id].x[0] - x_sp[i].x[0])*(x_sp[id].x[0] - x_sp[i].x[0]) +
				(x_sp[id].x[1] - x_sp[i].x[1])*(x_sp[id].x[1] - x_sp[i].x[1]) +
				(x_sp[id].x[2] - x_sp[i].x[2])*(x_sp[id].x[2] - x_sp[i].x[2]));
			h_all[i] = h_temp;
		}
	}
	qsort(h_all, x_sp.size(), sizeof(h_all[0]), Cmp);	// 从小到大排序
	x_sp[id].h_min = h_all[1];	// 取第二个h作为该点的最小h，因为第一个是到该点本身的距离，为0
	delete[]h_all;
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
		ErrorPoint ep;
		string lineStr = "";
		getline(infile, lineStr);
		if (lineStr != "")
		{
			if (DIM == 2)
			{
				sscanf(lineStr.c_str(), "%lg\t%lg", &(ep.x[0]), &(ep.x[1]));
			}
			if (DIM == 3)
			{
				sscanf(lineStr.c_str(), "%lg\t%lg\t%lg", &(ep.x[0]), &(ep.x[1]), &(ep.x[2]));
			}
			ep.sp_id = 0;
			ep.h = 0.0;
			x_ep.push_back(ep);
		}
	}
	infile.close();

	return 0;
}

void CalcError_H()
{
	vector<double> h_all;
	for (int i = 0; i < x_ep.size(); i++)
	{
		h_all.clear();
		for (int j = 0; j < x_sp.size(); j++)
		{
			double h_temp = 0.0;
			if (DIM == 2)
			{
				h_temp = sqrt((x_ep[i].x[0] - x_sp[j].x[0])*(x_ep[i].x[0] - x_sp[j].x[0]) +
					(x_ep[i].x[1] - x_sp[j].x[1])*(x_ep[i].x[1] - x_sp[j].x[1]));
				h_all.push_back(h_temp);
			}
			if (DIM == 3)
			{
				h_temp = sqrt((x_ep[i].x[0] - x_sp[j].x[0])*(x_ep[i].x[0] - x_sp[j].x[0]) +
					(x_ep[i].x[1] - x_sp[j].x[1])*(x_ep[i].x[1] - x_sp[j].x[1]) + 
					(x_ep[i].x[2] - x_sp[j].x[2])*(x_ep[i].x[2] - x_sp[j].x[2]));
				h_all.push_back(h_temp);
			}		
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

		// 将离该误差分析点最近的样本点的h_min值赋给误差分析点的h
		for (int l = 0; l < h_all.size(); l++)
		{
			if (h_min == h_all[l])
			{
				x_ep[i].h = x_sp[l].h_min;
			}
		}
	}
}

void WriteErrorPointH()
{
	ofstream ofs;
	ofs.open("h.txt", ios::out|ios::trunc);

	for (int i = 0; i < x_ep.size(); i++)
	{
		if (i < x_ep.size() - 1)
		{
			ofs << x_ep[i].h << endl;
			cout << x_ep[i].h << endl;
		}

		//aviod to output last line with an empty line
		if (i == x_ep.size() -1 )
		{
			ofs << x_ep[i].h;
			cout << x_ep[i].h;
		}
	}
	ofs.close();
}