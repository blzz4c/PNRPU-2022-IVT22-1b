// f(x)=3*x-4*lnx-5
// [2, 4]

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	float fA, fB, fC;
	double eps = 0.000001;
	a = 2;
	b = 4;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		fA = 3 * a - 4 * log(a) - 5;
		fB = 3 * b - 4 * log(b) - 5;
		fC = 3 * c - 4 * log(c) - 5;
		if (fA * fC <= 0) { b = c; }
		else if (fC * fB <= 0) { a = c; }
		else { cout << "Что-то не то!" << endl; }
	}
	cout << "Корни: " << a << "; " << b << endl;
	return 0;
}