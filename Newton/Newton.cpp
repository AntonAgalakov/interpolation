#include <iostream>
#include <fstream>

using namespace std;
const int n = 5;
double x[n] = {-1.0, -0.5, 0, 0.5, 1};
double y[n] = {-1.56, -0.55, 0, 0.55, 1.56};

double Newton(double xp)
{
	double result, divider, F;
	result = y[0];
	for(int i = 1; i < n; i++)
	{
		F = 0;
		for(int j = 0; j <= i; j++)
		{
			divider = 1;
			for(int k = 0; k <= i; k++)
			{
				if(k != j)
					divider *=(x[j] - x[k]);
			}
			F += y[j]/divider;
		}
		for(int k = 0; k < i; k++)
			F *= (xp - x[k]);
		result += F;
	}
	return result;
}
int main()
{
	ofstream fout("data.txt");
	for(double i = -1; i <= 1; i+=0.01)
		fout << i<< "\t"<< Newton(i) << endl;
	fout.close();
	return 0;
}