#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book(void) : Print()
{
	publishingHouse = "";
	amountPages = 0;
}
Book::~Book(void)
{
}
void Book::Show(void)
{
	cout << "Название: " << Name << endl;
	cout << "Автор: " << Author << endl;
	cout << "Издательство: " << publishingHouse << endl;
	cout << "Кол-во страниц: " << amountPages << endl;
}
void Book::Input(void)
{
	cout << "Название: ";
	cin >> Name;
	cout << "Автор: ";
	cin >> Author;
	cout << "Издательство: ";
	cin >> publishingHouse;
	cout << "Кол-во страниц: ";
	cin >> amountPages;
	cout << endl;
}
Book::Book(string name, string author, string publishing_house , int amount_pages) : Print(name, author)
{
	publishingHouse = publishing_house;
	amountPages = amount_pages;
}
Book::Book(const Book& s)
{
	Name = s.Name;
	Author = s.Author;
	publishingHouse = s.publishingHouse;
	amountPages = s.amountPages;
}
void Book::setPublishingHouse(string publishing_house)
{
	publishingHouse = publishing_house;
}
void Book::setAmountPages(int amount_pages)
{
	amountPages = amount_pages;
}
string Book::getPublishingHouse(void)
{
	return publishingHouse;
}
int Book::getAmountPages(void)
{
	return amountPages;
}
Book& Book::operator=(const Book& s)
{
	if (this == &s)
	{
		return *this;
	}
	Name = s.Name;
	Author = s.Author;
	publishingHouse = s.publishingHouse;
	amountPages = s.amountPages;
	return *this;
}