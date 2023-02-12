#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int const SIZE = 100;

	int answ, temp, num;

	int arr[SIZE] = {1,2,3};
	int fakeSIZE;
	std::cout << "Введите размер массива: ";
	std::cin >> fakeSIZE;
	if (fakeSIZE > 0)
	{
		while (true)
		{
			std::cout << "Что вы хотите сделать?\n1.Добавить число \n2.Удалить число ";
			std::cin >> answ;
			if (answ == 2)
			{
				for (int i = 0; i < fakeSIZE - 1; i++)
				{
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
				arr[fakeSIZE - 1] = 0;
			}
			else if (answ == 1)
			{
				std::cout << "Введите число в стек: ";
				std::cin >> num;
				for (int i = fakeSIZE - 1; i > 0; i--)
				{
					temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
				}
				arr[0] = num;
			}
			std::cout << "Массив: ";
			for (int i = 0; i < fakeSIZE; i++)
			{
				std::cout << arr[i] << " ";
			}
		}
	}
	else
	{
		std::cout << "Массив не может быть нулевого или отрицательного размера. Попробуйте ещё раз.";
	}
}