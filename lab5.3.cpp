#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;
double k(const double x);
int main()
{
	double zp, zk, z, r;
	int n;

	cout << "zp = "; cin >> zp;
	cout << "zk = "; cin >> zk;
	cout << "n = "; cin >> n;

	double zg = (zk - zp) / n;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "z" << " |"
		<< setw(10) << "r" << " |"
		<< endl;
	cout << "----------------------" << endl;

	z = zp;
	while (z <= zk)
	{
		r = k(pow(z, 2) + 1) - k(pow(z, 2) - 1) + 2 * k(z);
		cout << "|" << setw(7) << setprecision(2) << z << " |"
			<< setw(10) << setprecision(5) << r << " |"
			<< endl;
		z += zg;
	}
	return 0;
}
double k(const double x)
{
	if (abs(x) >= 1)
		return ((exp(x) + sin(x)) / (pow(cos(x), 2) + 1));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = (x / i);
			a *= R;
			S += 1 / exp(x) * a;
		} while (i < 5);
		return S;
	}
}
