#include <iostream>
using namespace std;
int main()
{
	int n, S = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			S -= i;
		}
		else
		{
			S += i;
		}
	}
	cout << S;
}