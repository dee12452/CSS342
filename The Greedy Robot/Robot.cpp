#include "stdafx.h"
#include "Robot.h"
#include <string>
#include <vector>
using namespace std;



Robot::Robot()
{
	RobotX = 0, RobotY = 0;
}


Robot::~Robot()
{
}

Robot::Robot(int Rx, int Ry, int Tx, int Ty)
{
	RobotX = Rx;
	RobotY = Ry;
	coord.Tx = Tx;
	coord.Ty = Ty;
}

//this function checks each direction that it may need to go and recursively goes that way
int Robot::findTreasure(int x, int y, string p)
{
	if (x == coord.Tx && y == coord.Ty)
	{
		coord.numOfPaths++;
		coord.paths.resize(coord.numOfPaths);
		coord.paths[coord.numOfPaths - 1] = coord.path;
	}
	else
	{
		int tempx = x;
		int tempy = y;
		
		if (y > coord.Ty)
		{
			coord.path = p;
			coord.path += "S";
			findTreasure(x, tempy - 1, coord.path);
		}
		if (y < coord.Ty)
		{
			coord.path = p;
			coord.path += "N";
			findTreasure(x, tempy + 1, coord.path);
		}

		if (x > coord.Tx)
		{
			coord.path = p;
			coord.path += "W";
			findTreasure(tempx - 1, y, coord.path);
		}
		if (x < coord.Tx)
		{
			coord.path = p;
			coord.path += "E";
			findTreasure(tempx + 1, y, coord.path);
		}


	}
	return coord.numOfPaths;
}

//function that is able to handle printing out the paths properly
void Robot::printPaths()
{
	if (coord.paths[0] == "")
	{
		cout << "Number of Paths: 0" << endl;
		return;
	}
	cout << "Number of Paths: " << coord.numOfPaths << endl;
	for (int i = 0; i < coord.paths.size(); i++)
	{
		cout << coord.paths[i] << endl;
	}
}

int Robot::getRobotX() const
{
	return RobotX;
}

int Robot::getRobotY() const
{
	return RobotY;
}

void Robot::setRobotX(int x)
{
	RobotX = x;
}

void Robot::setRobotY(int y)
{
	RobotY = y;
}

