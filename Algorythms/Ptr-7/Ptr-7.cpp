#include<iostream>
using namespace std;

int main()
{
	int num, *ptr=&num;
	setlocale(LC_ALL, "rus");
	cout << "Введите значение переменной: " << endl;
	cin >> *ptr;
    cout << num;

	return 0;
}