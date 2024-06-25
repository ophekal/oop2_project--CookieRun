#pragma once
#include <string>
#include <memory>
#include "StaticObject/StaticObject.h"

class MoveStrategy
{
public:
	virtual ~MoveStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, const sf::Vector2f& enemyPosition) = 0;
};