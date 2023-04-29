#include "Vector.h"

Vector::Vector() {
	beg = 0;
	cur = 0;
	size = 0;
} 

Vector::Vector(int n) {
	beg = new Object* [n];
	cur = 0;
	size = n;
} 

void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "Empty\n";
	}

	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++) {
		(*p)->Show();
		p++;
	}
	return out;
}