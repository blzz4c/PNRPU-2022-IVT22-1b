// f(x) = 3x - 4lnx - 5
// f'(x) = 3 - 4/x;
// f''(x) = 4/x^2;
// [2, 4]

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;
int main()
{
setlocale(LC_ALL, "RUS");
float x, xPrev = 0;
// f(b) * f''(b) > 0
// (12 - 4*ln4 - 5) * (4/16) > 0 => x0 = b;
x = 4;
double eps = 0.000001;

while (abs(x - xPrev) > eps)
{
x = xPrev - (3 * xPrev - 4 * log(xPrev) - 5) / (3 - 4/xPrev);
}
cout << "Корень: " << x << endl;
return 0;
}