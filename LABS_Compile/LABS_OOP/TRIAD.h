#pragma once
#include <iostream>
#include <string>

class TRIAD
{
protected:
	int first;
	int second;
	int third;
public:
	TRIAD(); //конструктор без параметров
	TRIAD(int, int, int); //конструктор с параметрами
	TRIAD(const TRIAD&);//конструктор копирования
	virtual ~TRIAD() {}; //декструктор
	int get_first() { return first; } //селектор
	int get_second() { return second; } //селектор
	int get_third() { return third; } // селектор
	void set_first(int); //модификатор
	void set_second(int); //модификатор
	void set_third(int); //модификатор
	//перегруженные операции
	TRIAD& operator=(const TRIAD&);
	
	//глобальные функции ввода/вывода
	friend std::istream& operator>>(std::istream& in, TRIAD& t);
	friend std::ostream& operator<<(std::ostream& out, const TRIAD& t);
};