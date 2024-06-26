//
//#include <memory>
//#include "GameObject.h"
//#include "AnimationObject/MovingObstcale.h"
//#include "AnimationObject/AnimationObject.h"
//#include "HandleResources.h"
//#include "Factories/ObjectFactory.h"
//
//// Register the obstcales, different colors represent different obstcales
//bool MovingObstcale::m_register = ObjectFactory<AnimationObject>::registerObject(sf::Color(34, 177, 76), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject>
//{
//	sf::Sprite sprite;
//	switch (level)
//	{
//	case 1:
//		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE1));
//		break;
//	case 2:
//		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE1));
//		break;
//	case 3:
//		sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE1));
//		break;
//	}
//	return std::make_unique<AnimationObject>(sprite, position);
//})
//&&
//
//ObjectFactory<AnimationObject>::registerObject(sf::Color(0, 162, 232), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject>
//	{
//		sf::Sprite sprite;
//		switch (level)
//		{
//		case 1:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE2));
//			break;
//		case 2:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE2));
//			break;
//		case 3:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE2));
//			break;
//		}
//		return std::make_unique<AnimationObject>(sprite, position);
//	})
//&&
//
//ObjectFactory<AnimationObject>::registerObject(sf::Color(163, 73, 164), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject>
//{
//		sf::Sprite sprite;
//		switch (level)
//		{
//		case 1:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE3));
//			break;
//		case 2:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE3));
//			break;
//		case 3:
//			sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE3));
//			break;
//		}
//		return std::make_unique<AnimationObject>(sprite, position);
//});
//
////-----------------------------------------------------------------
//MovingObstcale::MovingObstcale(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position)
//:AnimationObject(sprite, speed, animationTime, type, position)
//{
//m_object.setPosition(position);
//}
//
////-----------------------------------------------------------------
//void MovingObstcale::updateAnimation(sf::Time deltaTime)
//{
//	m_object.move(sf::Vector2f{ 0,0 }*deltaTime.asSeconds() * m_objectSpeed);
//	m_spriteSheet.update(deltaTime);
//
//}