#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int n; int sum = 0;
    cin >> n;
    if (n <= 0)
    {
        cout << "Невозможно посчитать сумму натуральных чисел при n <= 0" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << sum << endl;
    }
}