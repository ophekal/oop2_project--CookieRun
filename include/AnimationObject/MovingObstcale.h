#pragma once
#include "AnimationObject/AnimationObject.h"

class MovingObstcale : public AnimationObject
{
public:
	MovingObstcale(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position);

private:
	static bool m_register;
};