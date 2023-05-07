#pragma once
#include <iostream>
#include "Error.h"
const int MAX_SIZE = 10;

class Iterator {
	friend class Set;
public:
	Iterator() {
		elem = 0;
	}

	Iterator(const Iterator& it) {
		elem = it.elem;
	}

	void operator+(int n) { 
		int* tmp = elem;
		int i = 0;
		while (i < n) {
			++elem;
			i++;
		}
		if (i > MAX_SIZE || elem == NULL) {
			elem = tmp;
			throw IndexErrorS();
		}
	}

	int& operator *() const {
		return *elem;
	}

private:
	int* elem;
};

class Set {
public:
	Set(int,int);
	Set(const Set& a);
	~Set();
	Set& operator=(const Set& a);
	int& operator[](int index);
	bool operator!=(const Set& a);
	bool operator<(int n);
	//< число - принадлежность множеству
	friend std::istream& operator>>(std::istream& in, Set& a);
	friend std::ostream& operator<<(std::ostream& out, const Set& a);

	Iterator first() { return beg; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

