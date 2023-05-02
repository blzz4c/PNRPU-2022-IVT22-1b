#include "Set.h"

Set::Set(int s, int k) {
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
} 

Set::Set(const Set &a) {
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
} 

Set::~Set() {
	delete[]data;
	data = 0;
}

Set& Set::operator=(const Set& a) {
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) {
		delete[]data;
	}
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
	return *this;
}

int&Set::operator[](int index) {
	if (index < size) {
		return data[index];
	}
	else {
		std::cout << "\nError! Index > size";
	}
}

//!= - проверка на неравенство
bool Set::operator!=(const Set& a) {
	if (size != a.size) {
		return size != a.size;
	}
	bool ans = false;
	for (int i = 0; i < size; i++) {
		ans += data[i] != a.data[i];
	}
	return ans;
}
//< число - принадлежность множеству

bool Set::operator<(int n) {
	bool ans = false;
	for (int i = 0; i < size; i++) {
		ans += data[i] < n;
	}
	return ans;
}

std::istream& operator>>(std::istream& in, Set& a) {
	for (int i = 0; i < a.size; ++i)
	{
		in >> a.data[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Set& a) {
	for (int i = 0; i < a.size; ++i)
	{
		out << a.data[i] << " ";
	}
	return out;
}