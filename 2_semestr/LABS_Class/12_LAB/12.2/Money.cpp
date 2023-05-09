#include <iostream>
#include "Money.h"

//конструкторы
bool Money::operator<(const Money& m) {
	if (rub < m.rub) return true;
	if (rub == m.rub && cop < m.cop) return true;
	return false;
}

bool Money::operator>(const Money& m) {
	if (rub > m.rub) return true;
	if (rub == m.rub && cop > m.cop) return true;
	return false;
}

bool Money::operator==(const Money& m) {
	if (rub == m.rub && cop == m.cop) return true;
	return false;
}

bool Money::operator!=(const Money& m) {
	if (rub != m.rub && cop != m.cop) return true;
	return false;
}

Money& Money::operator=(const Money& m) {
	if (&m == this) return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

Money Money::operator+(const Money& m) {
	int temp1 = rub * 100 + cop;
	int temp2 = m.rub * 100 + m.cop;

	Money p(rub, cop);
	p.rub = (temp1 + temp2) / 100;
	p.cop = (temp1 + temp2) % 100;
	if (cop < 0) {
		cop *= (-1);
	}
	return p;
}

Money Money::operator/(const Money& m) {
	int temp1 = rub * 100 + cop;
	int temp2 = m.rub * 100 + m.cop;

	Money p(rub, cop);
	p.rub = (temp1 / temp2) / 100;
	p.cop = (temp1 / temp2) % 100;
	if (cop < 0) {
		cop *= (-1);
	}
	return p;
}

Money Money::operator/(const int& m) {
	int temp1 = rub * 100 + cop;

	Money p(rub, cop);
	p.rub = (temp1 / m) / 100;
	p.cop = (temp1 / m) % 100;
	if (cop < 0) {
		cop *= (-1);
	}
	return p;
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