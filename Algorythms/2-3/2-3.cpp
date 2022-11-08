#include <iostream>
using namespace std;
int main()
{
	int n, sr = 0, num = 1, s = 0, z = 1;
	setlocale(LC_ALL, "Rus");
	cout << "Введите число N" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sr = i;
		for (int j = num; j <= num + z; j++)
		{
			sr *= j;
		}
		num = 2;
		s += sr;
		num += i;
		if (num >= 4)
		{
			z += 1;
		}
	}
	cout << s;
}