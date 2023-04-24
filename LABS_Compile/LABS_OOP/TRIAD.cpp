#include <iostream>
#include "TRIAD.h"

TRIAD::TRIAD() { 
	first = 0; 
	second = 0; 
	third = 0; 
} //����������� ��� ����������

TRIAD::TRIAD(int a, int b, int c) {
	first = a; 
	second = b; 
	third = c; 
} //����������� � �����������

TRIAD::TRIAD(const TRIAD& t) { 
	first = t.first;
	second = t.second; 
	third = t.third;
} //����������� �����������

TRIAD::~TRIAD() {
}; //�����������

void TRIAD::set_first(int a) { 
	first = a; 
} //�����������

void TRIAD::set_second(int b) { 
	second = b; 
} //�����������

void TRIAD::set_third(int c) { 
	third = c; 
} //�����������


TRIAD&TRIAD::operator=(const TRIAD&t) {
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}

std::istream& operator>>(std::istream&in, TRIAD&t) {
	std::cout << "\nfirst: "; in >> t.first;
	std::cout << "\nsecond: "; in >> t.second;
	std::cout << "\nthird: "; in >> t.third;
	return in;
}

std::ostream& operator<<(std::ostream& out, const TRIAD& t) {
	std::cout << "\nfirst: " << t.first;
	std::cout << "\nsecond: " << t.second;
	std::cout << "\nthird: " << t.third << "\n";
	return out;
}