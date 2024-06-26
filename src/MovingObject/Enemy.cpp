#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject/MovingObject.h"
#include "MovingObject/Enemy.h"
#include "HandleResources.h"
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveSmartStrategy.h"
#include <iostream>
#include "MoveStrategy/MoveRandomStrategy.h"


//-------------------------------------------------------------------------------------------------------------
Enemy::Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type, std::unique_ptr<MoveStrategy> movement)
		: m_move(std::move(movement)), MovingObject(sprite, speed, position),
		  m_animation(HandleResources::instance().getAnimationData(type), m_object, sf::seconds(0.1f))  
{
	m_object.setOrigin(sf::Vector2f(m_object.getTextureRect().getSize() / 2));
	std::cout << sf::Vector2f(m_object.getTextureRect().getSize() / 2).x << sf::Vector2f(m_object.getTexture()->getSize() / 2u).y;
}


//-------------------------------------------------------------------------------------------------------------
void Enemy::moveEnemy(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects,
	                  sf::Time deltaTime)
{
	m_move->move(playerPosition, staticObjects,*this);
	m_animation.update(deltaTime);

}

//-------------------------------------------------------------------------------------------------------------
void Enemy::setMoveStrategy(std::unique_ptr<MoveStrategy> movement)
{
	m_move = std::move(movement);
}

//-----------------------------------------------------------------------------------------------------------
void Enemy::updateAnimation(sf::Time deltaTime)
{
	m_object.move(sf::Vector2f{ 0,0 }*deltaTime.asSeconds() * m_objectSpeed);
	m_animation.update(deltaTime);
}

//----------------------------------------------------------------------------
void Enemy::setSpriteFlipped(int direction)
{
	if (direction == LEFT)
	{
		m_object.setScale(1.f, 1.f); // Flip horizontally
	}
	else
	{
		m_object.setScale(-1.f, 1.f); // Normal scale
	}
}
	