#include <iostream>
using namespace std;
int main()
{
    int n1, n2, n3, max;
    cin >> n1 >> n2 >> n3;
    if (n1 >= n2 && n1 >= n3)
    {
        max = n1;
    }
    else if (n2 >= n1 && n2 >= n3)
    {
        max = n2;
    }
    else
    {
        max = n3;
    }
    cout << max;
}