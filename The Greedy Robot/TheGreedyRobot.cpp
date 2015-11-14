// Adam Charlton
// The Greedy Robot
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
#include "Robot.h"


int main()
{
	while (true)
	{
		string n = "";
		int RobotX, RobotY, TreasureX, TreasureY;
		cout << "Please enter the Robot's X, Robot's Y, Treasure's X, Treasure's Y:" << endl;
		cin >> RobotX >> RobotY >> TreasureX >> TreasureY;
		Robot rob(RobotX, RobotY, TreasureX, TreasureY);
		rob.findTreasure(rob.getRobotX(), rob.getRobotY(), n);
		rob.printPaths();
		cout << endl;
	}
	return 0;
}

