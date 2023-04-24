#pragma once
#include "TRIAD.h"

class TIME :public TRIAD {
protected:
	int hour;
	int min;
	int sec;
public:
	TIME();
	~TIME() {};
	TIME(int, int, int);
	TIME(const TIME&);
	TIME& operator=(const TIME&);

	friend std::istream& operator>>(std::istream& in, TIME& tim);
	friend std::ostream& operator<<(std::ostream& out, const TIME& tim);
};