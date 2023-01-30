#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, pr, s;
    bool m1 = false;
	cin >> n >> s;
	while (n > 0 && !m1)
	{
		pr = (n % 10);
		if (pr == s)
		{
			m1 = true;
		}
		n /= 10;
	}
	if (m1 == true)
	{
		cout << "Да, входит!";
	}
	else
	{
		cout << "Нет, не входит!";
	}
}