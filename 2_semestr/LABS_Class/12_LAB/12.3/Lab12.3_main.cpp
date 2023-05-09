#include <iostream>
#include <set>
#include "Money.h"
#include "Vector.h"
using namespace std;

void main() {
	int n;
	cout << "Enter number of element: ";
	cin >> n;
	Vector<Money> v(n);
	v.Print();

	cout << "\nEx 1: ";
	cout << "\nExercise impossible, because set store only unique values, and so max value is already in set";

	cout << "\nEx 2: ";
	Money key;
	cout << "\nEnter key:";
	cin >> key;
	v.del_key(key);
	v.Print();

	cout << "\nEx 3: ";
	Money c = v.avg_value();
	v.add_constant(c);
	v.Print();
}