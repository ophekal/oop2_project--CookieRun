#pragma once
#include <string>
#include <memory>
#include "StaticObject/StaticObject.h"

class Enemy;

class MoveStrategy
{
public:
	virtual ~MoveStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, Enemy& enemy) = 0;
};