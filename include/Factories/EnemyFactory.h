
#pragma once
#include <memory>
#include "MoveStrategy/MoveStrategy.h"
#include "MovingObject/Enemy.h"


using moveFunc = std::unique_ptr<MoveStrategy>(*)();

class EnemyFactory
{
public:
	static bool registerMove(moveFunc mf);
	static std::unique_ptr<Enemy> createEnemy(float startX,float endX, int levelNumber);

private:
	static std::vector<moveFunc>& getMoveVec();
	static sf::Vector2f getRandomPosition(float startX, float endX);

};