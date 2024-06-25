#pragma once
#include <memory>
#include "MovingObject/MovingObject.h"
#include "MoveStrategy/MoveStrategy.h"
#include "Animation.h"


class Enemy : public MovingObject
{
public:
	Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type);
	//Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, std::unique_ptr<MoveStrategy> movement);
	//void moveEnemy() {m_move->move();}
	//void setMoveStrategy(std::unique_ptr<MoveStrategy> movement);

private:
	//std::unique_ptr<MoveStrategy> m_move;
	static bool m_register;
	Animation m_animation;

	//unique_ptr<ShootStrategy> m_shoot;
};