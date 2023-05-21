#include <iostream>
#include "Money.h"
#include <set>
using namespace std;
typedef set<int, less<int>>TSet;
typedef TSet::iterator it;

Money key;
Money p;

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

Money avg_value(TSet s)
{
	Money sum;
	int n = s.size();
	for (it i = s.begin(); i != s.end(); i++)
	{
		sum = sum + ;
	}
	return sum / n;
}

void add_value(Money& value) {
	value = value + p;
}

struct Equal_key
{
	bool operator()(Money t)
	{
		return t == key;
	}
};

void main() {
	int n;
	cout << "N?";
	cin >> n;
	TSet s;
	s = make_set(n);
	print_set(s);

	cout << "Task 3:\n";
	// impossible

	cout << "Task 4:\n";
	cout << "Enter key: ";
	cin >> key;
	s.erase(remove_if(s.begin(), s.end(), Equal_key()), s.end());
	print_set(s);

	cout << "Task 5:\n";
	p = avg_value(s);
	for_each(s.begin(), s.end(), add_value);
	print_set(s);
}