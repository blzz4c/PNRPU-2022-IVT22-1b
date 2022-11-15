#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c;
	double D, x1, x2;
	cin >> a >> b >> c;
	D = b * b - 4 * a * c;
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);
	if (D < 0)
	{
		cout << "D < 0, корней нет.";
	}
	else
	{
		cout << "x1 = " << x1 << "x2 = " << x2;
	}
}