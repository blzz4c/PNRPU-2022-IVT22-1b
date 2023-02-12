#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int const SIZEh = 100;
	int const SIZEw = 100;

	srand(time(NULL));

	int midA = 0, midNow = 0, cnt = 0, ROWS, COLS;

	int arr[SIZEh][SIZEw];

	std::cout << "Задайте количество строк: ";
	std::cin >> ROWS;
	if (ROWS > 0)
	{
		cout << "Задайте количество столбцов: ";
		cin >> COLS;
		if (COLS > 0)
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					arr[i][j] = rand() % 1000;
				}
				midA += arr[i][0];
			}
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			cout << "Среднее арифметическое 1 столбца: " << midA << endl;
			for (int i = 0; i < COLS; i++)
			{
				for (int j = 0; j < ROWS; j++)
				{
					midNow += arr[j][i];
					if (midA < arr[j][i])
					{
						cnt += 1;
					}
				}
				midA = midNow;
				midNow = 0;
			}
			cout << "Количество чисел превышающие среднее арифметическое предыдущего столбца: " << cnt;
		}
		else
		{
			std::cout << "Количество столбцов не может быть отрицательным или равным 0. Попробуйте ещё раз.";
		}
	}
	else
	{
		std::cout << "Количество строк не может быть отрицательным или равным 0. Попробуйте ещё раз.";
	}
}