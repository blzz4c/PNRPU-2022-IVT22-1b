#pragma once
#include "TRIAD.h"

class TIME :public TRIAD {
protected:
	int hour = first;
	int min = second;
	int sec = third;
public:
	TIME();
	~TIME();
	TIME(int, int, int);
	TIME(const TIME&);
	TIME& operator=(const TIME&);

	void Show();

	bool operator==(TIME& tim) {
		return hour == tim.hour && min == tim.min && sec == tim.sec;
	};
	bool operator!=(TIME& tim) {
		return hour != tim.hour && min != tim.min && sec != tim.sec;
	};
	bool operator>(TIME& tim) {
		return hour > tim.hour && min > tim.min && sec > tim.sec;
	};
	bool operator<(TIME& tim) {
		return hour < tim.hour && min < tim.min && sec < tim.sec;
	};

	friend std::istream& operator>>(std::istream& in, TIME& tim);
	friend std::ostream& operator<<(std::ostream& out, const TIME& tim);
};