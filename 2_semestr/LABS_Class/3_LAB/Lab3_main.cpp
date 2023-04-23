#include <iostream>
#include "Money.h"

int main() {
	Money a;
	Money b;
	Money c;
	std::cin >> a;
	std::cin >> b;

	c = a - b;

	std::cout << "a= " << a << std::endl;
	std::cout << "b= " << b << std::endl;
	std::cout << "c= " << c << std::endl;

	return 0;
}