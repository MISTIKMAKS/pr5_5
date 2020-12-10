#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return pow(x, 3) - 2 * pow(x, 2) - 6 * x - 1;
}
typedef double (*function_f)(double x);

double root(function_f f_, double a, double b, double eps)
{
	double c;
	if (fabs(b - a) < eps)
		return (a + b) / 2;
	else
	{
		c = (a + b) / 2;
		if (f_(a) * f_(c) <= 0.)
			return root(f_, a, c, eps);
		else
			return root(f_, c, b, eps);
	}
}


int main(int argc, char* argv[])
{
	double a, b, epc;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "epc = "; cin >> epc;
	std::cout << root(&f, a, b, epc) << std::endl;
	return 0;
}