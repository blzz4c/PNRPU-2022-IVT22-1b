#include <iostream>
#include "Money.h"
#include <vector>
#include <stack>
using namespace std;
typedef stack<Money>St;
typedef vector<Money>Vec;

St make_stack(int n) {
	St s;
	Money m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		s.push(m);
	}
	return s;
}

St print_stack(St s) {
	while (!s.empty())
	{
		cout << s.top() << "\n";
		s.pop();
	}
	cout << endl;
	return s;
}

Vec copy_stack_to_vector(St s) {
	Vec v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St copy_vector_to_stack(Vec v) {
	St s;
	for (int i = 0; i < v.size(); i++) {
		s.push(v[i]);
	}
	return s;
}

Money& max_elem(St s) {
	Money me = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty()) {
		if (s.top() > me) {
			me = s.top();
		}
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return me;
}

void add_max(St& s, Money el) {
	Vec v;
	Money m;
	while (!s.empty()) {
		m = s.top();
		v.push_back(m);
		s.pop();
	}
	v.push_back(el);
	s = copy_vector_to_stack(v);
	v = copy_stack_to_vector(s);
	s = copy_vector_to_stack(v);
}

int find_elem(St& s, Money key) {
	Vec v = copy_stack_to_vector(s);
	Money m;
	int i = v.size();
	while (!s.empty()) {
		if (s.top() == key) {
			s = copy_vector_to_stack(v);
			return i;
		}
		s.pop();
		i--;
	}
	s = copy_vector_to_stack(v);
	cout << "\nThe element does not exist\n";
}

void del_elem(St& s, int pos) {
	Vec v;
	Money m;
	int i = 1;
	while (!s.empty()) {
		m = s.top();
		if (i != pos) v.push_back(m);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}

Money mid_value(St& s) {
	Vec v = copy_stack_to_vector(s);
	Money mv = s.top();
	s.pop();
	int n = 1;
	while (!s.empty()) {
		mv = mv + s.top();
		s.pop();
		n++;
	}
	s = copy_vector_to_stack(v);
	return mv / n;
}

void add_value(St& s, Money value) {
	Vec v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] + value;
	}
	s = copy_vector_to_stack(v);
}

void main() {
	Money m;
	St s;
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);
	print_stack(s);
	cout << "Ex 3\n";
	Money el = max_elem(s);
	add_max(s, el);
	print_stack(s);
	cout << "Ex 4\n";
	Money key;
	cout << "Print the key: "; cin >> key;
	int pos = find_elem(s, key);
	del_elem(s, pos);
	print_stack(s);
	cout << "Ex 5\n";
	Money mid = mid_value(s);
	add_value(s, mid);
	print_stack(s);
}