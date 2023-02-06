#include <iostream>

int main()
{
	const int N = 11;
	int temp;
	int arr[] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
	for (int i = 0; i < N-1; i++)
	{
		int min = i;
		for (int j = i; j < N; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
}