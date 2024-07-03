#pragma once
#include <memory>
#include "MovingObject/MovingObject.h"
#include "MoveStrategy/MoveStrategy.h"
#include "Animation.h"


class Enemy : public MovingObject
{
public:
	Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type, std::unique_ptr<MoveStrategy> movement);
	void moveEnemy(const sf::Vector2f& playerPosition, sf::Time deltaTime);
	void setSpriteFlipped(int direction);

private:
	std::unique_ptr<MoveStrategy> m_move;
	static bool m_register;
	Animation m_animation;
};