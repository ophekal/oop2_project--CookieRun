#pragma once
#include <string>
#include <memory>
#include "StaticObject/StaticObject.h"
//#include "MovingObject/Enemy.h"

class Enemy;

class MoveStrategy
{
public:
	virtual ~MoveStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy) = 0;
};