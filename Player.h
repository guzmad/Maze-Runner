///////////////////////////////////////////////////////////////////////
// Names		     : Diego Guzman
// Date				 : 10/22/2017
// Project			 : Maze Runner
// Course			 : CSS 342
// File Description  : This is the header file for the player object 
///////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
	public:
		///////////////////Destructor////////////////////////
		~Player();
		///////////////////Constructor///////////////////////
		Player();
		///////////////////Constructor//////////////////////
		Player(int r, int c);
		///////////////////Setters///////////////////////////
		void setCurrentR(int r);
		void setCurrentC(int c);
		//////////Methods to control the object movements////
		Player goNorth();
		Player goEast();
		Player goSouth();
		Player goWest();
		///////////////////getters///////////////////////////
		int getinitialR() const { return initialR; }
		int getinitialC() const { return initialC; }
		int getCurrentR() { return currentR; }
		int getCurrentC() const { return currentC; }
		///////////////////output operator overload//////////
		friend ostream & operator<<(ostream & output, const Player & rhs);

	private:
		////Variables save the initial object location///////
		int initialR;
		int initialC;
		////Variables save the current object location///////
		int currentR;
		int currentC;
};

#endif 

