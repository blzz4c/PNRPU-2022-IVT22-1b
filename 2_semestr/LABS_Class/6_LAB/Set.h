#pragma once
#include <iostream>
#include <string>

class Iterator {
	friend class Set;
public:
	Iterator() {
		elem = 0;
	}

	Iterator(const Iterator& it) {
		elem = it.elem;
	}

	bool operator==(const Iterator& it) {
		return elem == it.elem;
	}

	bool operator!=(const Iterator& it) {
		return elem != it.elem;
	}

	void operator++() { ++elem; }
	void operator--() { --elem; }
	void operator+(int n) { elem += n; }

	int& operator *() const {
		return *elem;
	}

private:
	int* elem;
};

class Set {
public:
	Set(int s, int k = 0);
	Set(const Set&a);
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
	int *data;
	Iterator beg;
	Iterator end;
};