#include "Set.h"
#include <iostream>
int main() {
	setlocale(LC_ALL, "RUS");
	std::cout << "Максимальный размер множества равен 10\n";
	try {
		Set A(3, 0);
		A[0] = 32;
		A[1] = 124;
		A[2] = 312;
		std::cout << "Множество a = ";
		std::cout << A << "\n";
		int index;
		std::cout << "Введите размер множества b:";
		std::cin >> index;
		Set B(index, 0);
		std::cin >> B;
		std::cout << "A != B? Ответ: ";
		if (A != B) {
			std::cout << "Правда\n";
		}
		else {
			std::cout << "Ложь\n";
		}
		int n = 10;
		std::cout << "Число 10 > чисел из множества? Ответ: ";
		if (A < n) {
			std::cout << "Правда\n";
		}
		else {
			std::cout << "Ложь\n";
		}
		std::cout << *(A.first()) << "\n";

		Iterator i = A.first();
		i + 3;
		std::cout << *i << "\n";
	}
	catch (int) {
		std::cout << "Ошибка!\n";
	}
	return 0;
}