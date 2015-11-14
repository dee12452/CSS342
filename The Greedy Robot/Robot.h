#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Struct used for treasure coordinates, the number of paths, and a vector of strings to print out after the treasure is found.
struct Coordinates
{
	int Tx;
	int Ty;
	int numOfPaths = 0;
	string path;
	vector<string> paths;
};

class Robot
{
public:
	//constructors
	Robot();
	~Robot();
	Robot(int, int, int, int);

	//getters and setters
	int getRobotX() const;
	int getRobotY() const;
	void setRobotX(int x);
	void setRobotY(int y);

	//functions
	int findTreasure(int x, int y, string p);
	void printPaths();

	
private:
	int RobotY;
	int RobotX;
	Coordinates coord;
};

