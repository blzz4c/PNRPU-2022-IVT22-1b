#include <iostream>
#include "Money.h"
#include "Vector.h"
#include <vector>
#include <stack>
using namespace std;

void main() {
	Vector<Money>v(3);
	v.Print();
	cout << "Ex 3\n";
	Money el = v.max_elem();
	v.add_max(el);
	v.Print();
	cout << "Ex 4\n";
	Money key;
	cout << "Print the key: "; cin >> key;
	int pos = v.find_elem(key);
	v.del_elem(pos);
	v.Print();
	cout << "Ex 5\n";
	Money mid = v.mid_value();
	v.add_value(mid);
	v.Print();
}