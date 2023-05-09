#include <iostream>
#include <set>
using namespace std;
typedef set<int, less<int>>TSet;
typedef TSet::iterator it;

TSet make_set(int n) {
	TSet s;
	int a;
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

int avg_value(TSet s)
{
	int sum = 0;
	int n = s.size();
	for (it i = s.begin(); i != s.end(); i++)
	{
		sum = sum + *i;
	}
	return sum / n;
}

TSet add_constant(TSet s, int constant)
{
	int iv = 0;
	int* m = new int[s.size()];
	for (it i = s.begin(); i != s.end(); i++)
	{
		m[iv] = *i + constant;
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
	int key;
	cout << "\nEnter key:";
	cin >> key;
	s.erase(key);
	print_set(s);

	cout << "\nEx 3: ";
	int c = avg_value(s);
	TSet s2 = add_constant(s, c);
	print_set(s2);
}