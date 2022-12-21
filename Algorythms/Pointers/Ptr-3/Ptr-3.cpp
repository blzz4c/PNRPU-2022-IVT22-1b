#include <iostream>
using namespace std;

int main()
{
	float a, b, *ptr1, *ptr2, Sum = 0;
	setlocale(LC_ALL, "rus");
	cout << "Введите значения переменных a и b: " << endl;
	cin >> a >> b;

	ptr1 = &a;
	ptr2 = &b;

	Sum = *ptr1 + *ptr2;

	cout << "Sum = " << Sum << endl;
	return 0;
}