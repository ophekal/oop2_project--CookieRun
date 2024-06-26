#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject/MovingObject.h"
#include "MovingObject/Enemy.h"
#include "HandleResources.h"
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveSmartStrategy.h"
#include "MoveStrategy/MoveRandomStrategy.h"


// Register the enemy type with the factory
bool Enemy::m_register = EnemyFactory::registerMove([](const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)-> std::unique_ptr<MoveStrategy>
{
	return std::make_unique<MoveSmartStrategy>();
}) 
&&
EnemyFactory::registerMove([](const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy) -> std::unique_ptr<MoveStrategy>
	{
		return std::make_unique<MoveRandomStrategy>();
	});

//-------------------------------------------------------------------------------------------------------------
Enemy::Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type, std::unique_ptr<MoveStrategy> movement)
		: m_move(std::move(movement)), MovingObject(sprite, speed, position),
		  m_animation(HandleResources::instance().getAnimationData(type), m_object, sf::seconds(0.1f))  {};


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
// In Enemy.cpp (or the appropriate source file)
void Enemy::setSpriteFlipped(bool flipped) 
{
	if (flipped) 
	{
		m_object.setScale(-1.f, 1.f); // Flip horizontally
	}
	else
	{
		m_object.setScale(1.f, 1.f); // Normal scale
	}

	m_isFlipped = flipped; // Update internal state
}
//------------------------------------------------------------------------------

	