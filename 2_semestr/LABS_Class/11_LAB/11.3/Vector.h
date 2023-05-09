#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector
{
	int len;
	vector <T> v;
public:
	Vector();
	Vector(int n);
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
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::Vector(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

template <class T>
Vector<T>::~Vector(void) {

}

template <class T>
void Vector<T>::Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "  \n";
	}
}

template <class T>
T& Vector<T>::max_elem() {
	T mx = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > mx) {
			mx = v[i];
		}
	}
	return mx;
}

template <class T>
void Vector<T>::add_max(T el) {
	v.push_back(el);
}

template <class T>
int Vector<T>::find_elem(T key) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			return i;
		}
	}
	cout << "\nThe element does not exist";
}

template <class T>
void Vector<T>::del_elem(int pos) {
	v.erase(v.begin() + pos);
}

template <class T>
T Vector<T>::mid_value() {
	T mv = v[0];
	int n = v.size();
	for (int i = 0; i < v.size(); i++) {
		mv = mv + v[i];
	}
	return (mv / n);
}

template <class T>
void Vector<T>::add_value(T value) {
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] + value;
	}
}