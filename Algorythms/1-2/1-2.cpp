#include <iostream>

int main() 
{
	setlocale(LC_ALL, "Rus");
	float n1, n2;
	std::cin >> n1 >> n2;
	if (n2 == 0)
	{
		std::cout << "На ноль делить нельзя!";
	}
	else
	{
		std::cout << n1 / n2;
	}
}