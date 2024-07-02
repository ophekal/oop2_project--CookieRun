
#include <memory>
#include "GameObject.h"
#include "AnimationObject/MovingObstcale.h"
#include "AnimationObject/AnimationObject.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"

// Register the obstcales, different colors represent different obstcales
bool MovingObstcale::m_register = ObjectFactory<AnimationObject>::registerObject(sf::Color(185, 122, 87), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject>
{
	sf::Sprite sprite;
	float speed = 40.f;
	sf::Time animationTime = sf::seconds(0.2f);
	AnimationType type;	
	switch (level)
	{
	case 1:
		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_ANI_OBSTACLE1));
		type = ANI_OVEN_OBSTCALE1;
		break;
	case 2:
		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_ANI_OBSTACLE1));
		type = ANI_KITCH_OBSTCALE1;
		break;
	case 3:
		sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_ANI_OBSTACLE1));
		type = ANI_GARDEN_OBSTCALE1;
		break;
	}
	return std::make_unique<MovingObstcale>(sprite, speed, animationTime, type, position);
})
&&
ObjectFactory<AnimationObject>::registerObject(sf::Color(181, 230, 29), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject>
{
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_FLAG));
	float speed = 120.f;
	sf::Time animationTime = sf::seconds(0.2f);
	AnimationType type = ANI_FLAG;
	return std::make_unique<MovingObstcale>(sprite, speed, animationTime, type, position);
});


//--------------------------------------------------------------------------------------
MovingObstcale::MovingObstcale(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position)
:AnimationObject(sprite, speed, animationTime, type, position)
{
	m_object.setPosition(position);
}

