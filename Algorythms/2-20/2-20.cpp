#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, S;
	bool flag = false;
	cout << "Введите количество элементов n" << endl;
	cin >> n;
	cout << "Введите искомый элемент S" << endl;
	cin >> S;
	for (int i = 1; i <= n; i++)
	{
		if (S == sin(n + (i / n)))
		{
			flag = true;
		}
	}
	if (flag)
	{
		cout << "Да, есть" << endl;
	}
	else if (!flag)
	{
		cout << "Нет, нету" << endl;
	}
}