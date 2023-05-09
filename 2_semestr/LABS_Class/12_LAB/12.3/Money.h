#pragma once
#include <iostream>
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
	long get_rub() { return rub; } //селектор
	int get_cop() { return cop; } //селектор
	void set_rub(long r) { rub = r; } //модификатор
	void set_cop(int c) { cop = c; } //модификатор
	//перегруженные операции
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator/(const Money&);
	Money operator/(const int&);
	bool operator>(const Money&);
	bool operator<(const Money&) const;
	bool operator==(const Money&);
	bool operator!=(const Money&);

	//глобальные функции ввода/вывода
	friend std::istream& operator>>(std::istream& in, Money& m);
	friend std::ostream& operator<<(std::ostream& out, const Money& m);
};