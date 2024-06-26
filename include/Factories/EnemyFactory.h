
#pragma once
#include <memory>
#include "MoveStrategy/MoveStrategy.h"
#include "MovingObject/Enemy.h"


using moveFunc = std::unique_ptr<MoveStrategy>(*)();

class EnemyFactory
{
public:
	static bool registerMove(moveFunc mf);
	static std::unique_ptr<Enemy> createEnemy(const sf::Vector2f& position, int levelNumber);

private:
	static std::vector<moveFunc>& getMoveVec();

};