#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, max = -100, num;
	bool flag = false;
	cout << "Введите количество элементов n" << endl;
	cin >> n;
	max = sin(n + (1/ n));
	for (int i = 1; i <= n; i++)
	{
		if (max < sin(n + (i / n)))
		{
			max = sin(n + (i / n));
            num = i;
		}
	}
	cout << "Max: " << max << " Num: " << num;
}