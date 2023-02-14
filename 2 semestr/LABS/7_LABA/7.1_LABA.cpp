#include <iostream>
#include <cmath>
using namespace std;

int stepen(int a, int n)
{
	return pow(a,n);
}
long stepen(long a, int n)
{
	return pow(a, n);
}
double koren(double a, int n)
{
	return pow(a, 1.0 / n);
}
float koren(float a, int n)
{
	return pow(a, 1.0 / n);
}
int main()
{
	setlocale(LC_ALL, "Ru");
	int n;
	cout << "Введите число n: ";
	cin >> n;
	int x = 7;
	long y = 5;
	float z = 2.25;
	double w = 650.25;
	int m1 = stepen(x,n);
	long m2 = stepen(y,n);
	float m3 = koren(z, n);
	double m4 = koren(w, n);
	cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl;
	return 0;
}