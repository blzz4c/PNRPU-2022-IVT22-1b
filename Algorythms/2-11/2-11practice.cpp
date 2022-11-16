#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, p;
    bool plusFirst = false, minusFirst = false; //flag
	cout << "Введите кол-во элементов послед-сти: " << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (!plusFirst && !minusFirst)
        {
            if (p > 0)
            {
                plusFirst == true;
            }
            else if (p < 0)
            {
                minusFirst == true;
            }
        }
    }
    if (plusFirst)
    {
        cout << "Сначала ввели пол. число";
    }
    else if (minusFirst)
    {
        cout << "Сначала ввели отр. число";
    }
    else
    {
        cout << "Сначала ввели нулевое число";
    }
}