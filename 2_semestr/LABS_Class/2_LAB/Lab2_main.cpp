#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

Employee make_Employee() {
	string l, p;
	double s;
	cout << "Введите ФИО: ";
	getline(cin, l);
	cout << "Введите Должность: ";
	getline(cin, p);
	cout << "Введите Зарплату: ";
	cin >> s;
	Employee t(l, p, s);
	return t;
}
//Функция для передачи объекта как параметра
void print_Employee(Employee t) {
	t.show();
}

void main() {
	system("chcp 1251");
	//коструктор без параметров
	Employee t1;
	t1.show();
	//конструктор с параметрами
	Employee t2("Пушкин Александр Сергеевич", "Поэт", 95.43);
	t2.show();
	//конструктор копирования
	Employee t3 = t2;
	t3.set_LFP("Попов Александр Степанович");
	t3.set_Post("Изобретатель");
	t3.set_Salary(465.22);
	//конструктор копирования
	print_Employee(t3);
	//конструктор копирования
	t1 = make_Employee();
	t1.show();
}