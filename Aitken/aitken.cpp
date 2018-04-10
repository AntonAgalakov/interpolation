#include <iostream>

using namespace std;
const int n = 5;
double x[n] = {-1.0, -0.5, 0, 0.5, 1};
double y[n] = {-1.56, -0.55, 0, 0.55, 1.56};

double p[n];

double aitkien(double xp)
{
	for(int i = 0; i < n; i++)
	{
		p[i] = y[i];
		//cout << p[i] << endl;
	}

	for(int j = 0; j < n; j++)
	{
		for(int i = j+1; i < n; i++)
			{
				//cout << "(" << p[j] <<"*"<< xp-x[j] << "-"<< p[i] <<"*"<<xp-x[j]<< ")/"<<x[i]<< "-"<< x[j]<< endl;
				p[i] = ((xp - x[i]) * p[j] - (xp - x[j])*p[i])/(x[i]-x[j]);
				//cout << p[i]<< endl;
				
			}
	}
	return p[n-1];
}
int main()
{
	ofstream fout("data.txt");
	for(double i = -1; i <= 1; i+=0.01)
		fout << i<< "\t"<< aitkien(i) << endl;
	fout.close();
	return 0;
}