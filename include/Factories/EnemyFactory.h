
#pragma once
#include <memory>
#include "MoveStrategy/MoveStrategy.h"
#include "MovingObject/Enemy.h"


using moveFunc = std::unique_ptr<MoveStrategy>(*)();
//using FactoryEnemyMap = std::map<std::string, std::unique_ptr<Enemy>(*)(const sf::Vector2f&, int)>;

class EnemyFactory
{
public:
	static bool registerMove(moveFunc mf);
	//static bool registerEnemy(const std::string& type, std::unique_ptr<Enemy>(*f)(const sf::Vector2f& position, int level));
	static std::unique_ptr<Enemy> createEnemy(const std::string& name, const sf::Vector2f& position, int levelNumber);

private:
	static std::vector<moveFunc>& getMoveVec();
	/*static FactoryEnemyMap& getMap()
	{
		static FactoryEnemyMap m_map;
		return m_map;
	}*/

};