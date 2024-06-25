#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject/MovingObject.h"
#include "MovingObject/Enemy.h"
#include "HandleResources.h"


// Register the enemy type with the factory
//bool Enemy::m_register = EnemyFactory::registerEnemy("enemy", [](const sf::Vector2f& position, int level) -> std::unique_ptr<Enemy> {
//
//	float speed = 350.f;
//	sf::Sprite sprite;
//	AnimationType type;
//
//	switch (level)
//	{
//		case 1:
//		{
//			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_ENEMY));
//			type = ANI_DEVIL_COOKIE;
//			break;
//		}
//		case 2:
//		{
//			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_ENEMY));
//			type = ANI_CARROT_COOKIE;			
//			break;
//		}
//		case 3:
//		{
//			//sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L3_ENEMY));
//			//AnimationType type = ANI_ZOMBIE_COOKIE;
//			//break;
//		}
//	}
//
//	//auto& movement = EnemyFactory::getRandomMoveStrategy();
//	return std::make_unique<Enemy>(sprite, speed, position, type);//, std::move(movement));
//	});


//-------------------------------------------------------------------------------------------------------------
Enemy::Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type)//std::unique_ptr<MoveStrategy> movement)
	: /*m_move(std::move(movement)),*/ MovingObject(sprite, speed, position),
	m_animation(HandleResources::instance().getAnimationData(type), m_object, sf::seconds(0.1f))  {};


////-------------------------------------------------------------------------------------------------------------
//void Enemy::setMoveStrategy(std::unique_ptr<MoveStrategy> movement)
//{
//	m_move = std::move(movement);
//}