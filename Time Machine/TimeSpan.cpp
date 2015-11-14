#include "stdafx.h"
#include "TimeSpan.h"
#include <iostream>
using namespace std;


TimeSpan::TimeSpan()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

//What I did for this constructor is I checked to see if seconds is 0, and if so, set everything to 0
//If we have positive Seconds, then I cast the double to an int and set the seconds to the parameter entered
//If its not positive Seconds, then cast to int but instead of adding .5, subtract .5 (since it's negative)
//Then I have two while loops to convert extra seconds to minutes, then extra minutes to hours
//I do the same steps for the negatives, do the if statements, then do the while loops to get proper format
TimeSpan::TimeSpan(double Seconds)
{
	if (Seconds == 0)
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
		return;
	}
	if (Seconds > 0)
	{
		Seconds = int(Seconds + 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	else
	{
		Seconds = int(Seconds - 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	if (seconds >= 60)
	{

		while (seconds >= 60)
		{
			minutes += 1;
			seconds -= 60;
		}
		while (minutes >= 60)
		{
			hours += 1;
			minutes -= 60;
		}
		return;
	}
	if (seconds <= -60)
	{

		while (seconds <= -60)
		{
			minutes -= 1;
			seconds += 60;
		}
		while (minutes <= -60)
		{
			hours -= 1;
			minutes += 60;
		}
		return;
	}
}

//For this constructor I converted all the minutes into seconds, then did the same
//exact steps I did for the (seconds) constructor (convert seconds to min to hrs if needed)
TimeSpan::TimeSpan(double Minutes, double Seconds)
{
	Minutes *= 60;
	Seconds += Minutes;
	Minutes = 0;
	if (Seconds == 0)
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
		return;
	}
	if (Seconds > 0)
	{
		Seconds = int(Seconds + 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	else
	{
		Seconds = int(Seconds - 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	if (seconds >= 60)
	{

		while (seconds >= 60)
		{
			minutes += 1;
			seconds -= 60;
		}
		while (minutes >= 60)
		{
			hours += 1;
			minutes -= 60;
		}
		return;
	}
	if (seconds <= -60)
	{

		while (seconds <= -60)
		{
			minutes -= 1;
			seconds += 60;
		}
		while (minutes <= -60)
		{
			hours -= 1;
			minutes += 60;
		}
		return;
	}
}

//For this constructor I converted hours to seconds and added to seconds
//then did the same for minutes as I did in the above constructor. Then
//I followed the exact same steps as the (seconds) constructor.
TimeSpan::TimeSpan(double Hours, double Minutes, double Seconds)
{
	Hours *= 3600;
	Seconds += Hours;
	Hours = 0;
	Minutes *= 60;
	Seconds += Minutes;
	Minutes = 0;
	if (Seconds == 0)
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
		return;
	}
	if (Seconds > 0)
	{
		Seconds = int(Seconds + 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	else
	{
		Seconds = int(Seconds - 0.5);
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	if (seconds >= 60)
	{

		while (seconds >= 60)
		{
			minutes += 1;
			seconds -= 60;
		}
		while (minutes >= 60)
		{
			hours += 1;
			minutes -= 60;
		}
		return;
	}
	if (seconds <= -60)
	{

		while (seconds <= -60)
		{
			minutes -= 1;
			seconds += 60;
		}
		while (minutes <= -60)
		{
			hours -= 1;
			minutes += 60;
		}
		return;
	}
}

TimeSpan::~TimeSpan()
{
}

//For set time I implemented the same algorithm for the constructors but removed
//the parts where I casted doubles to ints. Also I had to add some return cases 
//since setTime must return a boolean value
bool TimeSpan::setTime(int Hours, int Minutes, int Seconds)
{
	Hours *= 3600;
	Seconds += Hours;
	Hours = 0;
	Minutes *= 60;
	Seconds += Minutes;
	Minutes = 0;
	if (Seconds == 0)
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
		return true;
	}
	if (Seconds > 0)
	{
		hours = 0;
		minutes = 0;
		seconds = Seconds;
	}
	else
	{
		hours = 0;
		minutes = 0;
		seconds = Seconds;
		return true;
	}
	if (seconds >= 60)
	{

		while (seconds >= 60)
		{
			minutes += 1;
			seconds -= 60;
		}
		while (minutes >= 60)
		{
			hours += 1;
			minutes -= 60;
		}
		return true;
	}
	if (seconds <= -60)
	{

		while (seconds <= -60)
		{
			minutes -= 1;
			seconds += 60;
		}
		while (minutes <= -60)
		{
			hours -= 1;
			minutes += 60;
		}
		return true;
	}
	return false;
}

//converts all ints to floats and then converts to a float hour
//used for comparing two time durations
float TimeSpan::ProcessTime() const
{
	float hrs, mins, secs, total;
	hrs = (float)hours;
	mins = (float)minutes;
	secs = (float)seconds;
	mins = mins / 60;
	secs = secs / 3600;
	total = hrs + mins + secs;
	return total;
}


int TimeSpan::getHours() const
{
	return hours;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}

int TimeSpan::getSeconds() const
{
	return seconds;
}

TimeSpan TimeSpan::operator+(const TimeSpan &Ts) const
{
	TimeSpan temp(hours, minutes, seconds);
	temp.setTime(temp.getHours() + Ts.getHours(), temp.getMinutes() + Ts.getMinutes(), temp.getSeconds() + Ts.getSeconds());
	return temp;
}

TimeSpan TimeSpan::operator-(const TimeSpan &Ts) const
{
	TimeSpan temp(hours, minutes, seconds);
	temp.setTime(temp.getHours() - Ts.getHours(), temp.getMinutes() - Ts.getMinutes(), temp.getSeconds() - Ts.getSeconds());
	return temp;
}

TimeSpan& TimeSpan::operator-()
{
	hours *= -1;
	minutes *= -1;
	seconds *= -1;
	return *this;
}

bool TimeSpan::operator==(const TimeSpan &Ts) const
{
	TimeSpan temp(hours, minutes, seconds);
	if (temp.ProcessTime() == Ts.ProcessTime())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TimeSpan::operator!=(const TimeSpan &Ts) const
{
	TimeSpan temp(hours, minutes, seconds);
	if (temp.ProcessTime() != Ts.ProcessTime())
	{
		return true;
	}
	else
	{
		return false;
	}
}


TimeSpan& TimeSpan::operator+=(const TimeSpan &Ts)
{
	hours += Ts.getHours();
	minutes += Ts.getMinutes();
	seconds += Ts.getSeconds();
	return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &Ts)
{
	hours -= Ts.getHours();
	minutes -= Ts.getMinutes();
	seconds -= Ts.getSeconds();
	return *this;
}

std::ostream& operator<<(std::ostream &outStream, TimeSpan &time)
{
	while (time.getSeconds() >= 60 || time.getSeconds() <= -60)
	{
		if (time.getSeconds() >= 60)
		{
			time.setTime(time.getHours(), time.getMinutes() + 1, time.getSeconds() - 60);
			continue;
		}
		else if (time.getSeconds() <= -60)
		{
			time.setTime(time.getHours(), time.getMinutes() - 1, time.getSeconds() + 60);
			continue;
		}
		else
		{
			break;
		}
	}
	while (time.getMinutes() >= 60 || time.getMinutes() <= -60)
	{
		if (time.getMinutes() >= 60)
		{
			time.setTime(time.getHours() + 1, time.getMinutes() - 60, time.getSeconds());
			continue;
		}
		else if (time.getMinutes() <= -60)
		{
			time.setTime(time.getHours() - 1, time.getMinutes() + 60, time.getSeconds());
			continue;
		}
		else
		{
			break;
		}
	} 
	outStream << "Hours: " << time.getHours() << " Minutes: " << time.getMinutes() << " Seconds: " << time.getSeconds() << endl;
	return outStream;
}

std::istream& operator>>(std::istream &in, TimeSpan &time)
{
	int h, m, s;
	in >> h >> m >> s;
	time.setTime(h, m, s);
	return in;
}
