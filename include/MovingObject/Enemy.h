#pragma once
#include <memory>
#include "MovingObject/MovingObject.h"
#include "MoveStrategy/MoveStrategy.h"
#include "Animation.h"


class Enemy : public MovingObject
{
public:
	//Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type);
	Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type, std::unique_ptr<MoveStrategy> movement);
	void moveEnemy(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, sf::Time deltaTime);
	void setMoveStrategy(std::unique_ptr<MoveStrategy> movement);
	void updateAnimation(sf::Time deltaTime);
	void setSpriteFlipped(bool flipped);


private:
	std::unique_ptr<MoveStrategy> m_move;
	static bool m_register;
	Animation m_animation;

	bool m_isFlipped = false;
};