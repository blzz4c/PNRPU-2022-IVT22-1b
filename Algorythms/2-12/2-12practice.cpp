#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	float p, max, min;
	cout << "Введите длину последовательности!" << endl;
	cin >> p;
    max = p;
    min = p;
	cout << "Введите первое число:" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите следующее число:" << endl;
		cin >> p;
		if (p > max)
		{
			max = p;
		}
        else if (p < min)
		{
			min = p;
		}
	}
    cout << "Сумма max и min: " << max + min;
}