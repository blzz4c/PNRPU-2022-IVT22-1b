#pragma once
#include <iostream>
#include <set>
using namespace std;

template <class T>
class Vector
{
	set<T, less<T>> s;
	int len;
public:
	Vector();
	Vector(int n);
	~Vector(void);

	void Print();
	void del_key(T key);
	T avg_value();
	void add_constant(T constant);
};

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void)
{
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);

	}
	len = s.size();
}

template <class T>
void Vector<T>::Print()
{
	for (T i : s)
	{
		cout << i << " ";
	}
}

template <class T>
void Vector<T>::del_key(T key)
{
	s.erase(key);
}

template <class T>
T Vector<T>::avg_value()
{
	T sum(0, 0);
	int n = s.size();
	for (T i : s)
	{
		sum = sum + i;
	}
	return sum / n;
}

template <class T>
void Vector<T>::add_constant(T constant)
{
	int iv = 0;
	T* m = new T[s.size()];
	for (T i : s)
	{
		m[iv] = i + constant;
		iv++;
	}
	set<T> tmp(m, m + s.size());
	s = tmp;
}