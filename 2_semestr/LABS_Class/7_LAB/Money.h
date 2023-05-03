#pragma once
#include <iostream>

class Money
{
	long rub;
	int cop;
public:
	Money(); //конструктор без параметров
	Money(long r, int c); //конструктор с параметрами
	Money(const Money& m); //конструктор копирования
	Money& operator=(const Money&);
	virtual ~Money() ; //декструктор

	//глобальные функции ввода/вывода
	friend std::istream& operator>>(std::istream& in, Money& m);
	friend std::ostream& operator<<(std::ostream& out, const Money& m);
};

