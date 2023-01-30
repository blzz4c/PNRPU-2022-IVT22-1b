#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, p, gues;
	cout << "Введите сначал кол-во элементов послед-сти, а затем сами элементы послед-сти ЧЕРЕЗ ПРОБЕЛ!" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (p > 0)
		{
			cout << "Положительные числа вводятся раньше" << endl;
		}
		else if (p < 0)
		{
			cout << "Положительные числа вводятся раньше" << endl;
		}
		else
		{
			cout << "Нулевые вводятся раньше или все элементы нулевые" << endl;
		}
		break;
	}
}