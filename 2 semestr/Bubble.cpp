#include <iostream>

int main()
{
	int temp = 0;
	int arr[] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
	for (int i = 0; i < 11-1; i++)
	{
		for (int j = 0; j < 11 - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
}