#include <iostream>

using namespace std;
const int n = 4;
double x[n] = {1,2,3,4};
double y[n] = {1, 4, 9, 16};

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
	double xp = 2.5;
	cout << lagrange(xp);
	return 0;
}