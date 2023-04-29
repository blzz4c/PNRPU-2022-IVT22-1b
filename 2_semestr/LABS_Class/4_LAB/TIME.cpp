#include <iostream>
#include "TIME.h"

TIME::TIME() {
	hour = 0;
	min = 0;
	sec = 0;
}

TIME::~TIME() {}

TIME::TIME(int h, int m, int s) :TRIAD(h, m, s) {
	hour = h;
	min = m;
	sec = s;
}

TIME::TIME(const TIME& tim) {
	hour = tim.hour;
	min = tim.min;
	sec = tim.sec;
}

TIME& TIME::operator=(const TIME& tim) {
	if (&tim == this) return *this;
	hour = tim.hour;
	min = tim.min;
	sec= tim.sec;
	return *this;
}

std::istream& operator>>(std::istream& in, TIME& tim) {
	do {
		std::cout << "Hour? "; in >> tim.hour;
		if (tim.hour > 24) {
			std::cout << "Error! Please try again!\n";
		}
	} while (tim.hour > 24);

	do {
		std::cout << "Min? "; in >> tim.min;
		if (tim.min > 60) {
			std::cout << "Error! Please try again!\n";
		}
	} while (tim.min > 60);

	do {
		std::cout << "Second? "; in >> tim.sec;
		if (tim.sec > 60) {
			std::cout << "Error! Please try again!\n";
		}
	} while (tim.sec > 60);

	return in;
}

std::ostream& operator<<(std::ostream& out, const TIME& tim) {
	out << tim.hour << ":" << tim.min << ":" << tim.sec;
	return out;
}