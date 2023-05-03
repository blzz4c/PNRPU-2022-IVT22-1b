#include "Money.h"
#include <iostream>

Money::Money() {
	rub = 0; 
	cop = 0; 
} //конструктор без параметров
Money::Money(long r, int c) { 
	rub = r;
	cop = c; 
} //конструктор с параметрами
Money::Money(const Money& m) { 
	rub = m.rub; 
	cop = m.cop; 
} //конструктор копирования

Money::~Money() {}; //декструктор


Money& Money::operator=(const Money& m) {
	if (&m == this) return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}


std::istream& operator>>(std::istream& in, Money& m) {
	std::cout << "Rub? "; in >> m.rub;
	do {
		std::cout << "Cop? "; in >> m.cop;
		if (m.cop > 100) {
			std::cout << "Error! Please try again!\n";
		}
	} while (m.cop > 100);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Money& m) {
	return (out << m.rub << "," << m.cop);
}