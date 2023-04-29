#pragma once
#include <iostream>
#include "Object.h"

class TRIAD : public Object
{
protected:
	int first;
	int second;
	int third;
public:
	TRIAD(); //конструктор без параметров
	virtual ~TRIAD();//декструктор
	void Show();
	TRIAD(int, int, int); //конструктор с параметрами
	TRIAD(const TRIAD&);//конструктор копирования
	int get_first() { return first; } //селектор
	int get_second() { return second; } //селектор
	int get_third() { return third; } // селектор
	void set_first(int); //модификатор
	void set_second(int); //модификатор
	void set_third(int); //модификатор
	//перегруженные операции
	TRIAD& operator=(const TRIAD&);

	bool operator==(TRIAD& t) {
		return first == t.first && second == t.second && third == t.third; 
	};
	bool operator!=(TRIAD& t) {
		return first != t.first && second != t.second && third != t.third;
	};
	bool operator>(TRIAD& t) {
		return first > t.first && second > t.second && third > t.third;
	};
	bool operator<(TRIAD& t) {
		return first < t.first && second < t.second && third < t.third;
	};
	
	//глобальные функции ввода/вывода
	friend std::istream& operator>>(std::istream& in, TRIAD& t);
	friend std::ostream& operator<<(std::ostream& out, const TRIAD& t);
};