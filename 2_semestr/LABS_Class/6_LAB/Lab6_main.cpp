#include <iostream>
#include "Set.h"
using namespace std;

void main() {
	Set a(5);
	cout << a << "\n";

	cin >> a;
	cout << a << "\n";

	a[2] = 100;
	cout << a << "\n";

	Set b(5);
	cout << b << "\n";

	b = a;
	cout << b << "\n";

	//!= - проверка на неравенство
	if (a != b) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	//< число - принадлежность множеству
	int n = 10;
	if (a < n) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	cout << *(a.first()) << "\n";

	Iterator i = a.first();
	++i;
	cout << *i << "\n";

	i + 2;
	cout << *i << "\n";
    
	for (i = a.first(); i != a.last(); ++i) {
		cout << *i << " ";
	}

}