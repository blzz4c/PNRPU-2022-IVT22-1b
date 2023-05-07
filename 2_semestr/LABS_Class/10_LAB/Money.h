#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Money
{
	long rub;
	int cop;
public:
	Money() { rub = 0; cop = 0; } //конструктор без параметров
	Money(long r, int c) { rub = r; cop = c; } //конструктор с параметрами
	Money(const Money& m) { rub = m.rub; cop = m.cop; } //конструктор копирования
	~Money() {}; //декструктор
	//перегруженные операции
	Money& operator=(const Money&);
	Money operator-(const Money&);
	bool operator==(Money& m) { return rub == m.rub && cop == m.cop; };
	bool operator!=(Money& m) { return rub != m.rub && cop != m.cop; };


	//глобальные функции ввода/вывода
	friend std::istream& operator>>(std::istream& in, Money& m);
	friend std::ostream& operator<<(std::ostream& out, const Money& m);
	friend std::fstream& operator>>(std::fstream& fin, Money& m);
	friend std::fstream& operator<<(std::fstream& fout, const Money& m);
};