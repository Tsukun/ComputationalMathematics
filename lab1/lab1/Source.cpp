#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

double f(double x)
{
	return -pow(x, 4) + 15 * pow(x, 2) + 12 * x - 10;
}

double df(double x)
{
	return -4 * pow(x, 3) + 30 * x + 12;
}

double X(double x)
{
	return sqrt((pow(x, 4) - 12 * x + 10) / 15);
}

double Newton(double x, double e)
{
	double tmp;
	int n = 0;
	tmp = x + 2 * e;
	while (abs(x - tmp) > e)
	{
		tmp = x;
		x -= f(x) / df(x);
		n++;
	}
	cout << endl << n << endl;
	return x;
}

double Iteration(double a, double b, double e)
{
	int n = 0;
	double temp, x = (a + b) / 2;
	while (abs(x - temp) > e)
	{
		temp = x;
		x = X(x);
		n++;
	}
	cout << endl << n << endl;
	return x;
}

double Hord(double a, double b, double e)
{
	int n = 0;
	while (abs(f(b)) > e)
	{
		n++;
		a = b - ((b - a) * f(b)) / (f(b) - f(a));
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	}
	cout << endl << n << endl;
	return b;
}
int main()
{
	double a, b, e;
	int temp;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "e: "; cin >> e;
	while (1)
	{
		cout << "Choose method: " 
			<< endl << "1) Newton method"
			<< endl << "2) Simple iteration method "
			<< endl << "3) Hord method " << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:cout << "x=" << Newton(b, e) << endl << endl;
			break;
		case 2:cout << "x=" << Iteration(a, b, e) << endl << endl;
			break;
		case 3:cout << "x=" << Hord(a, b, e) << endl << endl;
			break;
		}
	}
}
