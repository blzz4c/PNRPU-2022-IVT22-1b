#pragma once
class Object
{
public:
	Object(void) {};
	virtual ~Object() {};
	virtual void Show() = 0;
};