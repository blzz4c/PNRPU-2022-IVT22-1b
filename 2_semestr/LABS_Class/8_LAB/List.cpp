#include <iostream>
#include "List.h"
#include "Book.h"
using namespace std;

List::List(void)
{
	beg = nullptr;
	size = 0;
	cur = 0;
}
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
List::~List(void)
{
	if (beg != 0)
	{
		delete[] beg;
	}
	beg = 0;
}
void List::Add(void)
{
	Object* tmp;
	cout << "1.Печатное издание " << " или " << "2.Книга" << endl;
	int c;
	cin >> c;
	if (c == 1)
	{
		Print* p = new Print;
		p->Input();
		tmp = p;
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	else if (c == 2)
	{
		Book* s = new Book;
		s->Input();
		tmp = s;
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	else
	{
		return;
	}
}

void List::Show()
{
	if (cur == 0)
	{
		cout << "Пусто" << endl;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
int List::operator()()
{
	return cur;
}
void List::Del(void)
{
	if (cur == 0)
	{
		return;
	}
	cur--;
}
void List::Find(int tmp)
{
	beg[tmp];
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		if (i == tmp - 1)
		{
			cout << "Название: " << (*p)->getName();
		}
		p++;
	}
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}