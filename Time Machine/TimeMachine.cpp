// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "TimeSpan.h"

void main()
{
	int waitVar;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8, dur9, dur10(1,1,1);
	dur7 = dur1 + dur3;
	cout << dur1;
	cout << dur2;
	cout << dur3;
	cout << dur4;
	cout << dur5;
	cout << dur6;
	cout << dur7;
	dur7 += dur3;
	cout << dur3;
	cout << dur7;
	if (dur3 != dur6)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}
	cout << "Now enter 3 integers for a new duration!" << endl;
	cin >> dur9;
	cout << "Your entered duration is:" << endl;
	cout << dur9;
	dur9 -= dur10;
	cout << "Here is the duration minus an hour, a minute and a second" << endl;
	cout << dur9;
	cout << "Here is the duration after unary negation" << endl;
	-dur9;
	cout << dur9;
	int end;
	TimeSpan dur;
	dur.setTime(10, -90, -500);
	cout << dur;
	cout << "Type in any key and press enter to exit application" << endl;
	cin >> end;
}