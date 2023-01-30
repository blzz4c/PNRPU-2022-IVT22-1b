#include <iostream>
using namespace std;
int main()
{
	int n, s = 0, cnt = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (cnt % 2 == 1)
		{
			s -= i;
		}
		else
		{
			s += i;
		}
		cnt += 1;
	}
	cout << s;
}