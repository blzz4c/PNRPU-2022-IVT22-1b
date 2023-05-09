#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <class T>
class Vector
{
	int len;
	stack <T> s;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void Print();
	~Vector(void);
	T& max_elem();
	void add_max(T);
	int find_elem(T);
	void del_elem(int);
	T mid_value();
	void add_value(T);
};

template <class T>
vector<T> copy_stack_to_vector(stack<T> s) {
	vector<T> v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

template <class T>
stack<T> copy_vector_to_stack(vector<T> v) {
	stack<T> s;
	for (int i = 0; i < v.size(); i++) {
		s.push(v[i]);
	}
	return s;
}

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::Vector(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push(a);
	}
	len = s.size();
}

template <class T>
Vector<T>::Vector(const Vector<T>& Vec) {
	len = Vec.len;
	vector<T> v = copy_stack_to_vector(Vec.s);
	s = copy_vector_to_stack(v);
}

template <class T>
Vector<T>::~Vector(void) {

}

template <class T>
void Vector<T>::Print() {
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

template <class T>
T& Vector<T>::max_elem() {
	Money me = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty()) {
		if (s.top() > me) {
			me = s.top();
		}
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return me;
}

template <class T>
void Vector<T>::add_max(T el) {
	vector<T> v;
	T m;
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

template <class T>
int Vector<T>::find_elem(T key) {
	vector<T> v = copy_stack_to_vector(s);
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

template <class T>
void Vector<T>::del_elem(int pos) {
	vector<T> v;
	T m;
	int i = 1;
	while (!s.empty()) {
		m = s.top();
		if (i != pos) v.push_back(m);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}

template <class T>
T Vector<T>::mid_value() {
	vector<T> v = copy_stack_to_vector(s);
	T mv = s.top();
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

template <class T>
void Vector<T>::add_value(T value) {
	vector<T> v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] + value;
	}
	s = copy_vector_to_stack(v);
}
