#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject/MovingObject.h"
#include "MovingObject/Enemy.h"
#include "HandleResources.h"
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"


//// Register the enemy type with the factory
//bool Enemy::m_register = EnemyFactory::registerMove([](const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)-> std::unique_ptr<MoveStrategy>
//{
//	return std::make_unique<MoveSmartStrategy>;//, std::move(movement));
//});

bool Enemy::m_register = EnemyFactory::registerMove([](const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy) -> std::unique_ptr<MoveStrategy>
	{
		return std::make_unique<MoveSmartStrategy>();
	});

//-------------------------------------------------------------------------------------------------------------
Enemy::Enemy(const sf::Sprite& sprite, float speed, const sf::Vector2f& position, AnimationType type, std::unique_ptr<MoveStrategy> movement)
	:m_move(std::move(movement)), MovingObject(sprite, speed, position),
	m_animation(HandleResources::instance().getAnimationData(type), m_object, sf::seconds(0.1f))  {};


//-------------------------------------------------------------------------------------------------------------
void Enemy::moveEnemy(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects)
{
	m_move->move(playerPosition, staticObjects,*this);
}


//-------------------------------------------------------------------------------------------------------------
void Enemy::setMoveStrategy(std::unique_ptr<MoveStrategy> movement)
{
	m_move = std::move(movement);
}





	//switch (level)
	//{
	//	case 1:
	//	{
	//		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_ENEMY));
	//		type = ANI_DEVIL_COOKIE;
	//		break;
	//	}
	//	case 2:
	//	{
	//		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_ENEMY));
	//		type = ANI_CARROT_COOKIE;			
	//		break;
	//	}
	//	case 3:
	//	{
	//		//sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L3_ENEMY));
	//		//AnimationType type = ANI_ZOMBIE_COOKIE;
	//		//break;
	//	}
	//}

	//auto& movement = EnemyFactory::getRandomMoveStrategy();