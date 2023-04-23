#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//конструкторы
Employee::Employee() {
	LFP = "";
	Post = "";
	Salary = 0;
	cout << "Конструктор без параметров для объекта: " << this << endl;
}

Employee::Employee(string L, string P, double S) {
	LFP = L;
	Post = P;
	Salary = S;
	cout << "Конструктор с параметрами для объекта: " << this << endl;
}

Employee::Employee(const Employee &t) {
	LFP = t.LFP;
	Post = t.Post;
	Salary = t.Salary;
	cout << "Конструктор копирования для объекта: " << this << endl;
}
//деструктор
Employee::~Employee() {
	cout << "Деструктор для объекта: " << this << endl;
}
//селекторы
string Employee::get_LFP() {
	return LFP;
}

string Employee::get_Post() {
	return Post;
}

double Employee::get_Salary() {
	return Salary;
}
//модификаторы
void Employee::set_LFP(string L) {
	LFP = L;
}

void Employee::set_Post(string P) {
	Post = P;
}

void Employee::set_Salary(double S) {
	Salary = S;
}
//метод для просмотра атрибутов
void Employee::show() {
	cout << "ФИО: " << LFP << endl;
	cout << "Должность: " << Post << endl;
	cout << "Зарплата: " << Salary << endl;
}