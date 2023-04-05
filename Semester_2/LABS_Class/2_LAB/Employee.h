#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string LFP;
	string Post;
	double Salary;
public:
	Employee(); //конструктор без параметров
	Employee(string, string, double); //конструктор с параметрами
	Employee(const Employee&); //конструктор копирования
	~Employee(); //декструктор
	string get_LFP(); //селектор
	void set_LFP(string); //модификатор
	string get_Post(); //селектор
	void set_Post(string); //модификатор
	double get_Salary(); //селектор
	void set_Salary(double); //модификатор
	void show(); //просмотр атрибутов
};