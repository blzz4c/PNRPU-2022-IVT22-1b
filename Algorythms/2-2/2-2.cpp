#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int n; int product = 1;
    cin >> n;
    if (n <= 0)
    {
        cout << "Невозможно посчитать произведение натуральных чисел при n <= 0" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            product *= i;
        }
        cout << product << endl;
    }
}