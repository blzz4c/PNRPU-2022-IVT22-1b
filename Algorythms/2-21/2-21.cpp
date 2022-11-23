#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n1, n2;
	bool Up = false;
	bool Izm = false; //проверка изменчивости
	cout << "Проверка чисел по возрастанию. 0 - признак окончания ввода" << endl;
	cout << "Введите число: ";
	cin >> n1;
	n2 = n1;
	while (n1 != 0)
	{
		cin >> n1;
		if (n1 >= n2)
		{
			Up = true;
		}
		if (n1 < n2 && n1 != 0)
		{
			Up = false;
			Izm = true;
		}
		n2 = n1;
	}
	if (Up && !Izm)
	{
		cout << "Числа расположены в порядке возрастания" << endl;
	}
	else if (!Up && !Izm)
	{
		cout << "Ошибка ввода!" << endl;
	}
	else
	{
		cout << "Числа расположены не в порядке возрастания" << endl;
	}
}