#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, double S)
{
	first = F; second = S;
}

void fraction::Read()
{
	cout << "\nfirst? "; cin >> first;
	cout << "\nsecond? "; cin >> second;
}

void fraction::Show()
{
	cout << "\nfirst: " << first;
	cout << "\nsecond: " << second;
	cout << "\n";
}

double fraction::Distance(double x1, double y1)
{
	return sqrt(pow((first-x1),2) + pow((second - y1), 2));
}