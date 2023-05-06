#include <iostream>
#include <string>
#include "Print.h"
using namespace std;

Print::Print(void)
{
	Name = "";
	Author = "";
}
Print::~Print(void)
{
}
void Print::Show(void)
{
	cout << "Название: " << Name << endl;
	cout << "Автор: " << Author << endl;
}
void Print::Input(void)
{
	cout << "Название: ";
	cin >> Name;
	cout << "Автор: ";
	cin >> Author;
	cout << endl;
}
Print::Print(string name, string author)
{
	Name = name;
	Author = author;
}
Print::Print(const Print& p)
{
	Name = p.Name;
	Author = p.Author;
}
void Print::setName(string name)
{
	Name = name;
}
void Print::setAuthor(string author)
{
	Author = author;
}
string Print::getName(void)
{
	return Name;
}
string Print::getAuthor(void)
{
	return Author;
}
Print& Print::operator=(const Print& p)
{
	if (this == &p)
	{
		return *this;
	}
	Name = p.Name;
	Author = p.Author;
	return *this;
}
void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Название: " << getName() << endl;
			break;
		}
	}
}