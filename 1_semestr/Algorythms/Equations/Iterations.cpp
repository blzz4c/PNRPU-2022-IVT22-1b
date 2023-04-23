// f(x) = 3x - 4lnx - 5
// f'(x) = 3 - 4/x;
// f''(x) = 4/x^2;
// [2, 4]
// ф(x) = x + λ(3x-4lnx-5)
// -1/r < λ < 0, если f'(x) > 0
// 0 < λ < 1/r, если f'(x) < 0
// r = max(abs(f'(a)), abs(f'(b))
// λ = -9/10 = -0.9

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	float x, xPrev;
	double lambda = -0.9; // -9/10
	x = 2; // можно выбрать любое x0 из [2, 4] — выбранного заранее промежутка
	xPrev = 0; //делаем заведомо сильно меньше x, чтобы цикл правильно сработал
	double eps = 0.000001;

	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		x = lambda * (3*xPrev - 4*log(xPrev) - 5) + xPrev;
	}
	cout << "Корень по методу итераций: " << x << endl;
	return 0;
}