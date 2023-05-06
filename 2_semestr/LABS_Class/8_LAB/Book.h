#pragma once
#include <iostream>
#include <string>
#include "Print.h"
using namespace std;

class Book : public Print
{
protected:
	string publishingHouse;
	int amountPages;
public:
	Book(void);
	~Book(void);
	void Show();
	void Input();
	Book(string, string, string, int);
	Book(const Book&);
	void setPublishingHouse(string);
	void setAmountPages(int);
	string getPublishingHouse(void);
	int getAmountPages(void);
	Book& operator=(const Book&);
};