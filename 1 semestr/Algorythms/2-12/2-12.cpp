#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, p, max, max_old = - 100000, max_new, min, min_old = 100000, min_new;
	cout << "Введите сначал кол-во элементов послед-сти, а затем сами элементы послед-сти ЧЕРЕЗ ПРОБЕЛ!" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		max_new = p;
		if (max_new > max_old)
			max = max_new;
		max_old = max_new;
        min_new = p;
        if (min_new > min_old)
			min = min_new;
        min_new = p;
	}
	cout << max + min;
}
