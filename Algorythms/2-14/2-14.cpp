#include <iostream>
using namespace std;
int main()
{
    int n, s = 0;
    cin >> n;
    while (n > 0)
    {
        s += (n % 10); // задание егэ)
        n /= 10;
    }
    cout << s;
}