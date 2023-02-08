#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int const SIZE = 10;

	int answ, temp, num;

	int arr[SIZE] = {};
	
	while(true)
	{
		std::cout << "Что вы хотите сделать?\n1.Добавить число \n2.Удалить число ";
		std::cin >> answ;
		if (answ == 1)
		{
			std::cout << "Введите число в стек: ";
			std::cin >> num;
			for (int i = 0; i < SIZE-1; i++)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			arr[SIZE - 1] = num;
			for (int i = 0; i < SIZE; i++)
			{
				std::cout << arr[i] << " ";
			}
		}
		else if(answ ==2)
		{
			for (int i = SIZE - 1; i > 0; i--)
			{
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i - 1] = temp;
			}
			arr[0] = 0; //ооо, да я мастер костылей
			for (int i = 0; i < SIZE; i++)
			{
				std::cout << arr[i] << " ";
			}
		}
	}
}