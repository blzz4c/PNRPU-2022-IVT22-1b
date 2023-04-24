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
	TRIAD(); //����������� ��� ����������
	TRIAD(int, int, int); //����������� � �����������
	TRIAD(const TRIAD&);//����������� �����������
	virtual ~TRIAD() {}; //�����������
	int get_first() { return first; } //��������
	int get_second() { return second; } //��������
	int get_third() { return third; } // ��������
	void set_first(int); //�����������
	void set_second(int); //�����������
	void set_third(int); //�����������
	//������������� ��������
	TRIAD& operator=(const TRIAD&);
	
	//���������� ������� �����/������
	friend std::istream& operator>>(std::istream& in, TRIAD& t);
	friend std::ostream& operator<<(std::ostream& out, const TRIAD& t);
};