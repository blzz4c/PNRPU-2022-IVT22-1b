#include <iostream>
#include <set>
#include "Money.h"
using namespace std;
typedef set<Money, less<Money>>TSet;
typedef TSet::iterator it;

TSet make_set(int n) {
	TSet s;
	Money a;
	for (int i = 0; i < n; i++) {
		cout << "?";
		cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(TSet s) {
	for (it i = s.begin(); i != s.end(); i++) {
		cout << *i << " ";
	}
}

Money avg_value(TSet s)
{
	Money sum(0, 0);
	int n = s.size();
	for (it i = s.begin(); i != s.end(); i++)
	{
		sum = sum + *i;
	}
	return sum / n;
}

TSet add_constant(TSet s, Money constant)
{
	int iv = 0;
	Money* m = new Money[s.size()];
	for (it i = s.begin(); i != s.end(); i++)
	{
		m[iv] = constant + *i;
		iv++;
	}
	TSet tmp(m, m + s.size());
	return tmp;
}

void main() {
	int n;
	cout << "Enter number of element: ";
	cin >> n;
	TSet s = make_set(n);
	print_set(s);

	cout << "\nEx 1: ";
	cout << "\nExercise impossible, because set store only unique values, and so max value is already in set";

	cout << "\nEx 2: ";
	Money key;
	cout << "\nEnter key:";
	cin >> key;
	s.erase(key);
	print_set(s);

	cout << "\nEx 3: ";
	Money c = avg_value(s);
	TSet s2 = add_constant(s, c);
	print_set(s2);
}