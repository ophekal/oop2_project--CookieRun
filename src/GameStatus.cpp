
#include "GameStatus.h"


////---------------------------------------------------------------------------------
//GameStatus::GameStatus(int levelNum, int coinsNum, int dynamitesNum)
//	: m_levelNumber(levelNum), m_coins(coinsNum), m_numOfDynamite(dynamitesNum) {}


//---------------------------------------------------------------------------------
void GameStatus::setCoins(int numofCoins)
{
	//m_coins++;
	m_coins = numofCoins;
}

//---------------------------------------------------------------------------------
void GameStatus::setNumOfDynamites(int numOfDynamite)
{
	//m_numOfDynamite++;
	m_numOfDynamite = numOfDynamite;
}

//---------------------------------------------------------------------------------
int GameStatus::getCoins()const
{
	return m_coins;
}

//---------------------------------------------------------------------------------
int GameStatus::getNumOfDynamites()const
{
	return m_numOfDynamite;
}
