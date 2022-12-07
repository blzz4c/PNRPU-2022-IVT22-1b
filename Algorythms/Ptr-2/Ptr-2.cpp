#include <iostream>
using namespace std;

int main()
{
	int a, b, Sum;
	setlocale(LC_ALL, "rus");
	cout << "Введите значения переменных a и b: " << endl;
	cin >> a >> b;

	int *ptr1 = &a;
	int *ptr2 = &b;

	Sum = *ptr1 + *ptr2;

	cout << "Sum = " << Sum << endl;
	return 0;
}