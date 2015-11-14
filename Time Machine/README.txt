GreedyRobot
UW CSS342 Project 2

University of Washington, Bothell CSS 342: Data Structures, Algorithms, and Discrete Mathematics Fall 2014 Program 2: Recursion and Robots Assigned: Monday, October 6, 2014 Due: Wednesday, October 15, 2014, 10pm PST

Purpose The programming assignment will provide an exercise in using recursion to solve a path-finding problem in two dimensional space. The assignment will require the usage of recurrence as well as good class design. There is also minimal usage of the “new” keyword and pointers.

Problem: “The Greedy Robot” or “Lost in the Supermarket”

A robot is positioned on an integral point in a two-dimensional coordinate grid (x1,y1). There is a treasure that has been placed at a point in the same grid at (x2, y2). x1, x2, y1, and y2 are all integers. The robot can move up (North), down (South), left (West), or right (East). Commands can be given to the robot to move one position in one of the four direction. That is, “E” moves a robot one slot East (to the right) so if the robot was on position (3, 4), it would now be on (4, 4). The command N would move the robot one position north so a robot at position (4, 4) would be at (4, 5).

Write a recursive program which determines all the unique shortest paths from the robot to the treasure.

The input to the program will be the position of the robot (x1, y1) and the position of the treasure (x2, y2): four integers. For instance, an input of 1 3 -2 4 corresponds to the robot starting at position (1,3) and needing to get to position (-2, 4). Do not worry about error conditions on input as we will assume the input is well formed.

The output of the program should be the number of unique paths followed by the listing of these paths. A path should be output as a string of characters with each character corresponding to a direction the Robot should move. For instance, NNENE corresponds to having the robot move North, North, East, North and East. This would be one answer to the input: 3 3 5 6, which corresponds to (3,3) -> (5,6).

For the input 1 2 3 5 which corresponds to (1,2) -> (3,5) the output should be: Number of paths: 10 NNNEE NNENE NNEEN NENNE NENEN NEENN ENNNE ENNEN ENENN EENNN

Some Hints  Clearly state any assumptions you make in the headers of the .cpp and .h files.  It may be easiest to first make sure you have solved for counting the number of unique shortest paths.  To keep track of the paths you may consider passing a pointer to a string object to the recursive call. o You can print out this string as part of the base case o You can append to the string on each recursive call o The trick will be determining when to allocate or “new” the string for a unique path.
