#include<iostream>
using namespace std;

int main()
{
	int a, b;
	setlocale(LC_ALL, "rus");
	cout << "Введите значения переменных a и b: " << endl;
	cin >> a >> b;

	int *ptr1 = &a;
	int *ptr2 = &b;
	int *ptemp = ptr1;

	*ptr1 = *ptr2;
	*ptr2 = *ptemp;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}