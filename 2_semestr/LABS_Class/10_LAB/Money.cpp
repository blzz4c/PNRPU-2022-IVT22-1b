#include <iostream>
#include "Money.h"

//конструкторы
Money& Money::operator=(const Money& m) {
	if (&m == this) return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

Money Money::operator-(const Money& m) {
	int temp1 = rub * 100 + cop;
	int temp2 = m.rub * 100 + m.cop;

	Money p(rub, cop);
	p.rub = (temp1 - temp2) / 100;
	p.cop = (temp1 - temp2) % 100;
	if (cop < 0) {
		cop *= (-1);
	}

	if (rub < 0) {
		std::cout << "Error! Rub can't be less than 0";
	}
	else {
		return p;
	}
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

std::fstream& operator>>(std::fstream& fin, Money& m) {
	std::cout << "Rub? "; fin >> m.rub;
	do {
		std::cout << "Cop? "; fin >> m.cop;
		if (m.cop > 100) {
			std::cout << "Error! Please try again!\n";
		}
	} while (m.cop > 100);

	return fin;
}

std::fstream& operator<<(std::fstream& fout, const Money& m) {
	fout << m.rub << "," << m.cop;
	return fout;
}