#include<iostream>
using namespace std;

int main()
{
	int num1, num2, *ptr1, *ptr2;
	setlocale(LC_ALL, "rus");
	cout << "Введите значения переменных a и b: " << endl;
	cin >> num1;
	ptr1 = &num1;

    cin >> num2;
	ptr2 = &num2;

	int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;

	cout << "a = " << *ptr1 << endl;
	cout << "b = " << *ptr2 << endl;
	return 0;
}