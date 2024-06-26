#pragma once
#include "AnimationObject/AnimationObject.h"

class MovingObstcale : AnimationObject
{
public:
	MovingObstcale::MovingObstcale(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position);
	void updateAnimation(sf::Time deltaTime)

private:
	static bool m_register;
};