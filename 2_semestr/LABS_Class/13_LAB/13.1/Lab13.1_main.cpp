#include <iostream>
#include <deque>
#include <algorithm>
#include "Money.h"

using namespace std;

typedef deque<Money> TDeque;
Money key;
Money p;

TDeque make_deque(int n) {
	Money a;
	TDeque d;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d.push_back(a);
	}
	return d;
}

void print_deque(TDeque d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << "\n";
	}
	cout << "\n";
}

int find_elem(TDeque d, Money el) {
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == el) {
			return i;
		}
	}
	cout << "\nThe element does not exist";
}

void del_elem(TDeque d, int pos) {
	d.erase(d.begin() + pos);
}

Money mid_value(TDeque d) {
	Money s = d[0];
	for (int i = 0; i < d.size(); i++) {
		s = s + d[i];
	}
	int n = d.size();
	return s / n;
}

void add_value(Money& value) {
	value = value + p;
}

struct Equal_key
{
	bool operator()(Money t)
	{
		return t == key;
	}
};

void main() {
	int n;
	cout << "N?";
	cin >> n;
	TDeque d;
	d = make_deque(n);
	print_deque(d);

	cout << "Task 3:\n";
	TDeque::iterator i;
	i = max_element(d.begin(), d.end());
	cout << "max = " << (*i) << endl;
	Money max = (*i);
	d.push_back(max);
	print_deque(d);

	cout << "Task 4:\n";
	cout << "Enter key: ";
	cin >> key;
	d.erase(remove_if(d.begin(), d.end(), Equal_key()), d.end());
	print_deque(d);

	cout << "Task 5:\n";
	p = mid_value(d);
	for_each(d.begin(), d.end(), add_value);
	print_deque(d);
}