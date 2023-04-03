#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, double S) {
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	system("chcp 1251 > NULL");
	fraction M;
	M.Init(3.0, 2.5);
	cout << "Введите координаты точки N: " << endl;
	double x1, y1;
	cout << "x1: "; cin >> x1;
	cout << "y1: "; cin >> y1;
	cout << "Координаты M: ";
	M.Show();
	cout << "Координаты N: ";
	cout << "\nx1: " << x1;
	cout << "\ny1: " << y1 << "\n";

	cout << "MN.Distance((" << M.first << "; " << M.second << "), (" << x1 << "; " << y1 << ")) =" << M.Distance(x1, y1) << endl;

	fraction* N = new fraction;
	cout << "Координаты точки N: ";
	N->Init(2.0, 5.0);
	N->Show();

	cout << "Введите координаты точки P: " << endl;
	cout << "x1: "; cin >> x1;
	cout << "y1: "; cin >> y1;
	cout << "Координаты N: ";
	N->Show();
	cout << "Координаты P: ";
	cout << "\nx1: " << x1;
	cout << "\ny1: " << y1 << "\n";
	N->Distance(x1, y1);

	cout << "NP.Distance((" << N->first << "; " << N->second << "), (" << x1 << "; " << y1 << ")) = " << N->Distance(x1, y1) << endl;

	cout << "Массивы" << endl;
	fraction mas[3];
	double X[3];
	double Y[3];
	for (int i = 0; i < 3; i++) {
		cout << "Координаты первой точки: " << endl;
		mas[i].Read();
		cout << "Координаты другой точки: ";
		cout << "x1: "; cin >> X[i];
		cout << "y1: "; cin >> Y[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << "Координаты первой точки: " << endl;
		mas[i].Show();
		cout << "Координаты другой точки: ";
		cout << "\nx1: " << X[i];
		cout << "\ny1: " << Y[i] << "\n";
	}
	for (int i = 0; i < 3; i++) {
		int z = mas[i].Distance(X[i],Y[i]);
		cout << "mas[" << i << "].Distance((" << mas[i].first << ";" << mas[i].second << "),(" << X[i] << ";" << Y[i] << ")) = " << mas[i].Distance(X[i], Y[i]) << endl;
	}

	cout << "Динамические Массивы" << endl;
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++) {
		cout << "Координаты первой точки: ";
		p_mas[i].Read();
		cout << "Координаты другой точки: ";
		cout << "x1: "; cin >> X[i];
		cout << "y1: "; cin >> Y[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << "Координаты первой точки: ";
		p_mas[i].Show();
		cout << "Координаты другой точки: ";
		cout << "\nx1: " << X[i];
		cout << "\ny1: " << Y[i] << "\n";
	}
	for (int i = 0; i < 3; i++) {
		int z = p_mas[i].Distance(X[i],Y[i]);
		cout << "p_mas[" << i << "].Distance((" << p_mas[i].first << ";" << p_mas[i].second << "),(" << X[i] << ";" << Y[i] << ")) = " << p_mas[i].Distance(X[i], Y[i]) << endl;
	}
	
	cout << "Функция" << endl;
	double x; int y;
	cout << "first?"; cin >> x;
	cout << "second?"; cin >> y;

	fraction F = make_fraction(x, y);
	cout << "Координаты первой точки: ";
	F.Show();
	cout << "Координаты другой точки: ";
	cout << "x1: "; cin >> x1;
	cout << "y1: "; cin >> y1;
	cout << F.Distance(x1,y1);

}