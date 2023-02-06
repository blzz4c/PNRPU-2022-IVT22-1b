#include <iostream>

int main()
{
	const int N = 11;
	int temp;
	int arr[] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
	for (int i = 0; i < N; i++)
	{
		int min = arr[i];
		for (int j = i; j > 0 && arr[j-1] > arr[j]; j--)
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
		}
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
}