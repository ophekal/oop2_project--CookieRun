
#pragma once

#include "Macros.h"
#include "MovingObject/Player.h"



class GameStatus
{
public:
	GameStatus() = default; //for compile!!!
	//GameStatus(int levelNum, int coinsNum, int dynamitesNum);
	void setCoins(int numofCoins);
	void setNumOfDynamites(int numOfDynamite);
	int getCoins()const;	// sends back the nuumber of coins the player picked = in order to unlock a level
	int getNumOfDynamites()const; // sends back the num of dynamites the player collected


private:
	int m_levelNumber = 1;
	int m_coins=0;
	int m_numOfDynamite=0;	// holds the number of dynamites 
	
};