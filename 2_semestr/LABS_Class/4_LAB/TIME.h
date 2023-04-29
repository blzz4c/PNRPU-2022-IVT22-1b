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

	bool operator==(TIME& tim) {
		return hour == tim.hour && min == tim.min && sec == tim.sec;
	};
	bool operator!=(TIME& tim) {
		return hour != tim.hour && min != tim.min && sec != tim.sec;
	};
	bool operator>(TIME& tim) {
		bool h = hour > tim.hour;
		bool m = hour == tim.hour && min > tim.min;
		bool s = hour == tim.hour && min == tim.min && sec > tim.sec;
		bool result = h + m + s;
		return result;
	};
	bool operator<(TIME& tim) {
		bool h = hour < tim.hour;
		bool m = hour == tim.hour && min < tim.min;
		bool s = hour == tim.hour && min == tim.min && sec < tim.sec;
		bool result = h + m + s;
		return result;
	};

	friend std::istream& operator>>(std::istream& in, TIME& tim);
	friend std::ostream& operator<<(std::ostream& out, const TIME& tim);
};