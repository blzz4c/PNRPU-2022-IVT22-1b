#include <iostream>
#include <deque>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef deque<int>Deq;

Deq make_deque(int n) {
	Deq d;
	for (int i = 0; i < n; i++) {
		int a = rand() % 100 - 50;
		d.push_back(a);
	}
	return d;
}

void print_deque(Deq d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " \n";
	}
}

int max_elem(Deq d) {
	int mx = d[0];
	for (int i = 1; i < d.size(); i++) {
		if (d[i] > mx) {
			mx = d[i];
		}
	}
	return mx;
}

void add_deque(Deq& d, int el) {
	d.push_back(el);
}

int find_elem(Deq& d, int el) {
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == el) {
			return i;
		}
	}
	cout << "\nThe element does not exist";
}

void del_elem(Deq& d, int pos) {
	d.erase(d.begin() + pos);
}

int mid_value(Deq& d) {
	int mv = 0;
	for (int i = 0; i < d.size(); i++) {
		mv += d[i];
	}
	int n = d.size();
	return mv / n;
}

void add_value(Deq& d, int value) {
	for (int i = 0; i < d.size(); i++) {
		d[i] += value;
	}
}

void main() {
	try {
		deque<int> d;
		deque<int>::iterator di = d.begin();
		int n;
		cout << "N?"; cin >> n;
		d = make_deque(n);
		print_deque(d);
		cout << "Ex 3\n";
		int el = max_elem(d);
		add_deque(d, el);
		print_deque(d);
		cout << "Ex 4\n";
		int key;
		cout << "Print the key: "; cin >> key;
		int pos = find_elem(d, key);
		del_elem(d, pos);
		print_deque(d);
		cout << "Ex 5\n";
		int mid = mid_value(d);
		add_value(d, mid);
		print_deque(d);
	}
	catch (int) {
		cout << "Error!";
	}
}