#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Print : public Object
{
protected:
	string Name;
	string Author;
public:
	Print(void);
	virtual ~Print(void);
	void Show(void);
	void Input(void);
	Print(string, string);
	Print(const Print&);
	void setName(string);
	void setAuthor(string);
	string getName(void);
	string getAuthor(void);
	Print& operator=(const Print&);
	void HandleEvent(const TEvent&);
};