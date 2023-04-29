#pragma once
class Object
{
public:
	Object(void) {};
	~Object() {};
	virtual void Show() = 0;
};