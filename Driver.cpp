///////////////////////////////////////////////////////////////////////
// Names		    			 : Diego Guzman
// Date							 : 10/22/2017
// Project						 : Maze Runner
// Course					     : CSS 342
// File Description              : This file represents the console application
//					             entry point which contains the main() method and
//					             all the funtionalitites of the Maze game.
///////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Player.h"

using namespace std;

///////////////////sets the values to the maze/////////////////////////////////
void insertMazeValues(string p, int height, int width, vector< vector<char> > &maze)
{
		vector<char> temp;
		for (int j = 0; j < width; j++)
		{
			temp.push_back((char)p[j]);
		}
		maze.push_back(temp);
}
///////////////It displays what is inside the maze/////////////////////////////
void printMaze(vector< vector<char> > &maze)
{
	for (int b = 0; b < maze.size(); b++)
	{
		for (int c = 0; c < maze[b].size(); c++)
		{
			cout << maze[b][c];
		}
		cout << endl;
	}
}
////Recursively traverse over the entire maze until it finds the exit////////
bool findPath(vector< vector<char> > & maze, Player mario, vector<Player> & moves)
{
	int height = maze.size();
	int width = maze[0].size();
	//Checks if the player is inside the boundaries
	if (mario.getCurrentR() < 0 || mario.getCurrentC() < 0 || mario.getCurrentC() >= width || mario.getCurrentR() >= height)
	{
		return false;
	}
	//Checks if the player started at the exit location
	if (maze[mario.getCurrentR()][mario.getinitialC()] == 'o')
	{
		moves.push_back(mario);
		return true;
	}
	//Check if the the player started at a valid position
	if (maze[mario.getCurrentR()][mario.getCurrentC()] != ' ')
	{
		return false;
	}
	maze[mario.getCurrentR()][mario.getCurrentC()] = '+';
	if (findPath(maze,mario.goNorth(),moves))   // North
	{
		moves.push_back(mario);
		return true;
	}
	if (findPath(maze, mario.goEast(),moves))   // East
	{
		moves.push_back(mario);
		return true;
	}
	if (findPath(maze,mario.goSouth(),moves))   // South
	{
		moves.push_back(mario);
		return true;
	}
	if (findPath(maze,mario.goWest(),moves))   // West
	{
		moves.push_back(mario);
		return true;
	}
	maze[mario.getCurrentR()][mario.getCurrentC()] = ' ';
	return false;
}
/////////////////////Main method///////////////////////////////////////////////////
int main()
{	//Reads the file
	fstream infile("mazeSimple");

	if (infile.fail())
	{
		cout << "Can't find the file!" << endl;
	}
	else
	{
		string s; // This string contains the first line in the file

		if (infile.good())  // it reads the first line of the file containing the
		{					// height and width from the maze and the starting location
			getline(infile, s);
		}

		int height = 0;		//for storing the height of the maze
		int width = 0;		//for storing width of the maze
		int startingR = 0;  // for storing the starting x coordinate
		int startingC = 0;  // for storing the starting Y coordinate
		vector<vector<char>> maze; // A 2D vector representing the maze

		stringstream firstline(s);
		firstline >> height >> width >> startingR >> startingC;
		string p;

		////Storing file character values into the 2d vector line by line////////////
		while (getline(infile, p))
		{
			insertMazeValues(p, height, width, maze);
		}
		printMaze(maze);
		cout << endl;
		//Creating a new player object
		Player mario(startingR,startingC);
		// A vector to store the player movements
		vector<Player> moves;
		//Returns a boolean value if the exit was found
		bool found = findPath(maze,mario,moves);
		//if exit is not found display a message, else print the maze and the moves//
		if (!found)
		{
			cout << "No exit found :( " << endl;
		}else
		{
			cout<< endl;
			printMaze(maze);
			for (int i = moves.size() - 1; i >= 0; i--) {
				cout << moves[i];
			}
		}
	}
	system("pause");
    return 0;
}
