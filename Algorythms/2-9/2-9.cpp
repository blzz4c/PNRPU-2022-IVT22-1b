#include <iostream>
using namespace std;
int main()
{
    int n, d;
    cin >> n;
    d = n / 2;
    for (int i = 0; i < d; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "* ";
    }
    for (int i = 0; i < d-1; i++)
    {
        for (int j = 0; j < d-i; j++)
        {
            cout << " ";
        }
        cout << "* ";
        for (int j = 0; j < n-2; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < d-i; j++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }
    cout << endl;

}