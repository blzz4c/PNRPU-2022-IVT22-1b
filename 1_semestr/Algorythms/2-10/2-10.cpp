#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	float p, max;
	cout << "Введите длину последовательности!" << endl;
	cin >> n;
	cout << "Введите первое число:" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите следующее число:" << endl;
		cin >> p;
		if (p > max)
		{
			max = p;
		}
	}
	cout << "Максимальный элемент: " << max << endl;
}