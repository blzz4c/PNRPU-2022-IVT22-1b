#include <iostream>
#include "TRIAD.h"

int main() {
	TRIAD a;
	std::cin >> a;
	std::cout << a;
	TRIAD t(1,2,3);
	std::cout << t;
	a = t;
	std::cout << a;

	std::cout << "a= " << a << std::endl;

	return 0;
}