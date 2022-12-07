#include<iostream>
using namespace std;

int main()
{
	int num, tmp, *ptr1, *ptr2;
	setlocale(LC_ALL, "rus");
	cout << "Введите значения переменных a и b: " << endl;
	cin >> num;

	ptr1 = &num;
    tmp = *ptr1;
    cin >> num;

	ptr2 = &num;
    *ptr1 = *ptr2;
    *ptr2 = tmp;

	cout << "a = " << *ptr1 << endl;
	cout << "b = " << *ptr2 << endl;
	return 0;
}