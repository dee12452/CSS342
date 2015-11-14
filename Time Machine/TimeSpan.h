#include "stdafx.h"
#include <iostream>
using namespace std;

class TimeSpan
{
public:
	TimeSpan();
	TimeSpan(double Hours, double Minutes, double Seconds); 
	TimeSpan(double Minutes, double Seconds); 
	TimeSpan(double Seconds);
	
	~TimeSpan(); 
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	bool setTime(int Hours, int Minutes, int Seconds);
	TimeSpan operator+(const TimeSpan &Ts) const;
	TimeSpan operator-(const TimeSpan &Ts) const;
	TimeSpan& operator-();
	bool operator==(const TimeSpan &Ts) const;
	bool operator!=(const TimeSpan &Ts) const;
	TimeSpan& operator+=(const TimeSpan &Ts);
	TimeSpan& operator-=(const TimeSpan &Ts);
	friend std::ostream& operator<<(std::ostream &outStream, TimeSpan &time);
	friend std::istream& operator>>(std::istream &outStream, TimeSpan &time); 
private:
	int hours;
	int minutes;
	int seconds;
	float ProcessTime() const;
};

