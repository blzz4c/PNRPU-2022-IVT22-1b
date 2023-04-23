#include<iostream>
int main()
{
	int n;
	int n_new;
	int* ptr = &n;

	std::cin >> *ptr;
	std::cin >> n_new;
	*ptr = n_new;
	std::cout << n << std::endl;

	return 0;
}