#include <iostream>
using namespace std;

int main()
{
	int n, tmp, *ptr=&tmp, max, min, Sum = 0;
	setlocale(LC_ALL, "rus");
	cout << "Введите длину последовательности: " << endl;
	cin >> n;
    cout << "Введите первое число: " << endl;
    cin >> *ptr;

	max = *ptr;
	min = *ptr;

	for (int i = 2; i <= n; i++)
    {
        cin >> *ptr;
        if (*ptr > max)
        {
            max = *ptr;
        }
        else if (*ptr < min)
        {
            min = *ptr;
        }
    }

	cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
	return 0;
}