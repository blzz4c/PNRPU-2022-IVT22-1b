#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, p, max_old = - 100000, max_new;
	cout << "Введите сначал кол-во элементов послед-сти, а затем сами элементы послед-сти ЧЕРЕЗ ПРОБЕЛ!" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		max_new = p;
		if (max_new > max_old && i != 1)
			break;
		max_old = max_new;
	}
	cout << max_new;
}