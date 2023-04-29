#include <iostream>
#include "TRIAD.h"
#include "TIME.h"
#include "Vector.h"
#include "Object.h"
using namespace std;

void main() {
	Vector v(5);
	TRIAD a;
	cin >> a;
	TIME b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
}