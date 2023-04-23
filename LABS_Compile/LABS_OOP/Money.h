#pragma once
#include <iostream>
#include <string>

class Money
{
	long rub;
	int cop;
public:
	Money() { rub = 0; cop = 0; } //����������� ��� ����������
	Money(long r, int c) { rub = r; cop = c; } //����������� � �����������
	Money(const Money&m) { rub = m.rub; cop = m.cop; } //����������� �����������
	~Money() {}; //�����������
	long get_rub() { return rub; } //��������
	int get_cop() { return cop; } //��������
	void set_rub(long r) { rub = r; } //�����������
	void set_cop(int c) { cop = c; } //�����������
	//������������� ��������
	Money& operator=(const Money&);
	Money operator-(const Money&);
	Money operator==(const Money&);
	Money operator!= (const Money&);
	bool operator==(Money& m) { return rub == m.rub && cop == m.cop; };
	bool operator!=(Money& m) { return rub != m.rub && cop != m.cop; };

	
	//���������� ������� �����/������
	friend std::istream& operator>>(std::istream& in, Money& m);
	friend std::ostream& operator<<(std::ostream& out, const Money& m);
};