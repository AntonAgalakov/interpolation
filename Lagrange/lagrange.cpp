#include <iostream>
#include <fstream>

using namespace std;
const int n = 5;
double x[n] = {-1.0, -0.5, 0, 0.5, 1};
double y[n] = {-1.56, -0.55, 0, 0.55, 1.56};

double lagrange(double xp)
{
	double temp;
	double result = 0.0;

	for(int i = 0; i < n; i++)
	{
		temp = 1;
		for(int j = 0; j < n;j++)
		{
			if(j == i)
				continue;
			temp *= (xp - x[j]) / (x[i] - x[j]);
		}
		result += temp * y[i];
	}
	return result;
}

int main()
{
	ofstream fout("data.txt");
	for(double i = -1; i <= 1; i+=0.01)
		fout << i<< "\t"<< lagrange(i) << endl;
	fout.close();
	return 0;
}