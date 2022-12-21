#include <iostream>
using namespace std;

int main()
{
	int n, fact = 1;
    int *f = &fact;
	setlocale(LC_ALL, "rus");
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        *f *= i;
    }
    fact = *f;

	cout << "Factorial of " << n << " is " << fact << endl;
	return 0;
}