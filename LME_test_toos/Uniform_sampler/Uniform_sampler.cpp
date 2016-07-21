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
		cout << "1. type: 1 means create error point, 2 means create sample points, 3 means just create boundary sample points." << endl;
		cout << "2. dimension: Only support 2-10 dimension, more dimensions being developed." << endl;
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
	if (TYPE == 3 )
	{
		stepSize = (UPPERBOUND - LOWERBOUND);
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
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					ofs << x1 << "\t" << x2 << endl;
					cout << x1 << "\t" << x2 << endl;
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					ofs << x1 << "\t" << x2 << endl;
					cout << x1 << "\t" << x2 << endl;
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					ofs << x1 << "\t" << x2 << endl;
					cout << x1 << "\t" << x2 << endl;
				}
			}
			ofs.close();
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
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						ofs << x1 << "\t" << x2 << "\t" << x3 << endl;
						cout << x1 << "\t" << x2 << "\t" << x3 << endl;
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						ofs << x1 << "\t" << x2 << "\t" << x3 << endl;
						cout << x1 << "\t" << x2 << "\t" << x3 << endl;
					}
				}
			}
			ofs.close();
		}	
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						ofs << x1 << "\t" << x2 << "\t" << x3 << endl;
						cout << x1 << "\t" << x2 << "\t" << x3 << endl;
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 4)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
							cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
							cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
							cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 5)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
								cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
								cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
								cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << endl;
							}
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 6)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = errorPointBeginPos + n*stepSize;
									ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << endl;
									cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  endl;
								}
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << endl;
									cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  endl;
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << endl;
									cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  endl;
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 7)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = errorPointBeginPos + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = errorPointBeginPos + o*stepSize;
										ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << endl;
										cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << endl;
									}
								}
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << endl;
										cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << endl;
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << endl;
										cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << endl;
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 8)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = errorPointBeginPos + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = errorPointBeginPos + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = errorPointBeginPos + p*stepSize;
											ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << endl;
											cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << endl;
										}
									}
								}
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << endl;
											cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << endl;
											cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 9)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = errorPointBeginPos + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = errorPointBeginPos + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = errorPointBeginPos + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = errorPointBeginPos + q*stepSize;
												ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
												cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
											}
										}
									}
								}
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = LOWERBOUND + q*stepSize;
												ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
												cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = LOWERBOUND + q*stepSize;
												ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
												cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
	}
	if (DIM == 10)
	{
		if (TYPE == 1)
		{
			ofstream ofs;
			ofs.open("ErrorPoints.txt", ios::out | ios::trunc);
			double errorPointBeginPos = LOWERBOUND + stepSize / 2;
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = errorPointBeginPos + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = errorPointBeginPos + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = errorPointBeginPos + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = errorPointBeginPos + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = errorPointBeginPos + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = errorPointBeginPos + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = errorPointBeginPos + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = errorPointBeginPos + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = errorPointBeginPos + q*stepSize;
												for (int r = 0; r < POINTNUM; ++r)
												{
													double x10 = errorPointBeginPos + r*stepSize;
													ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
													cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
												}
											}
										}
									}
								}
							}
						}
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
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = LOWERBOUND + q*stepSize;
												for (int r = 0; r < POINTNUM; ++r)
												{
													double x10 = LOWERBOUND + r*stepSize;
													ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
													cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
		if (TYPE == 3)
		{
			ofstream ofs;
			ofs.open("BoundarySamplingPoints.txt", ios::out | ios::trunc);
			for (int i = 0; i < POINTNUM; i++)
			{
				double x1 = LOWERBOUND + i*stepSize;
				for (int j = 0; j < POINTNUM; j++)
				{
					double x2 = LOWERBOUND + j*stepSize;
					for (int k = 0; k < POINTNUM; k++)
					{
						double x3 = LOWERBOUND + k*stepSize;
						for (int l = 0; l < POINTNUM; ++l)
						{
							double x4 = LOWERBOUND + l*stepSize;
							for (int m = 0; m < POINTNUM; ++m)
							{
								double x5 = LOWERBOUND + m*stepSize;
								for (int n = 0; n < POINTNUM; ++n)
								{
									double x6 = LOWERBOUND  + n*stepSize;
									for (int o = 0; o < POINTNUM; ++o)
									{
										double x7 = LOWERBOUND + o*stepSize;
										for (int p = 0; p < POINTNUM; ++p)
										{
											double x8 = LOWERBOUND + p*stepSize;
											for (int q = 0; q < POINTNUM; ++q)
											{
												double x9 = LOWERBOUND + q*stepSize;
												for (int r = 0; r < POINTNUM; ++r)
												{
													double x10 = LOWERBOUND + r*stepSize;
													ofs << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 << "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
													cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << x5 << "\t" << x6 <<  "\t" << x7 << "\t" << x8 << "\t" << x9 << "\t" << x10 << endl;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			ofs.close();
		}
	}

	//system("pause");
	return 0;
}