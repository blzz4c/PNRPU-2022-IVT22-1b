#pragma once
#include <iostream>
using namespace std;

template <class T>
class Set
{
	int size;
	T* data;
public:
	Set(int s, T k);
	Set(const Set<T>& a);
	~Set();
	Set& operator=(const Set<T>& a);
	T& operator[](int index);
	bool operator!=(const Set<T>& a);
	bool operator<(int n);
	friend istream& operator>> <>(istream& in, Set<T>& a);
	friend ostream& operator<< <>(ostream& out, const Set<T>& a);
};

template <class T>
Set<T>::Set(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <class T>
Set<T>::Set(const Set<T>& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}

template <class T>
Set<T>::~Set()
{
	delete[] data;
	data = 0;
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& a)
{
	if (this == &a)
	{
		return *this;
	}
	size = a.size;
	if (data != 0)
	{
		delete[] data;
	}
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	return *this;
}

template <class T>
T& Set<T>::operator[](int index)
{
	if (index < size)
	{
		return data[index];
	}
	else
	{
		cout << "Error" << endl;
	}
}

//!= - проверка на неравенство
template <class T>
bool Set<T>::operator!=(const Set<T>& a) {
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
template <class T>
bool Set<T>::operator<(int n) {
	bool ans = false;
	for (int i = 0; i < size; i++) {
		ans += data[i] < n;
	}
	return ans;
}

template <class T>
istream& operator>> (istream& in, Set<T>& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
}

template <class T>
ostream& operator<< (ostream& out, const Set<T>& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.data[i] << ' ';
	}
	return out;
}