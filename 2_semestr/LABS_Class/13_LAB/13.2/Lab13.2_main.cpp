#include <iostream>
#include "Money.h"
#include "Vector.h"
using namespace std;

void main() {
	Vector<Money>vec(5);
	vec.Print();

	cout << "Ex 3\n";
	Money el = vec.max_elem();
	vec.add_max(el);
	vec.Print();

	cout << "Ex 4\n";
	Money key;
	cout << "Print the key: "; cin >> key;
	int pos = vec.find_elem(key);
	vec.del_elem(pos);
	vec.Print();

	cout << "Ex 5\n";
	Money mid = vec.mid_value();
	vec.add_value(mid);
	vec.Print();
}