#pragma once
#include "AnimationObject/AnimationObject.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

class Coin : public AnimationObject
{
public:
	Coin(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position);
	void updatePositionTowardsPlayer(const sf::Vector2f& playerPosition, float deltaTime);

private:
	static bool m_register;

};