#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, pr, s, m1 = 0;
	cin >> n >> s;
	while (n > 0)
	{
		pr = (n % 10);
		if (pr == s)
		{
			m1 = 1;
		}
		n /= 10;
	}
	if (m1 == 1)
	{
		cout << "Да, входит!";
	}
	else
	{
		cout << "Нет, не входит!";
	}
}