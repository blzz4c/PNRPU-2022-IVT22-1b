#include <iostream>
#include "TRIAD.h"
#include "TIME.h"
using namespace std;

void f1(TRIAD & t) {
	t.set_first(3);
	cout << t;
}

TRIAD f2() {
	TIME tim(2, 2, 4);
	return tim;
}

void main() {
	TRIAD a;
	cin >> a;
	cout << a;
	TRIAD b(3, 4, 1);
	cout << b;
	a = b;
	cout << a;

	TIME c;
	cin >> c;
	cout << c;

	f1(c);
	a = f2();
	cout << a;

	if (a > b) {
		cout << a;
	}
}