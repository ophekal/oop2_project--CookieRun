
#include <memory>
#include "GameObject.h"
#include "StaticObject/StaticObstcale.h"
#include "StaticObject/StaticObject.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the obstcales into the factory, different colors represent different obstcales
bool StaticObstcale::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(34, 177, 76), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject>
{
	sf::Sprite sprite;
	switch (level)
	{
	case 1:
		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE1));
		break;
	case 2:
		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE1));
		break;
	case 3:
		sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE1));
		break;
	}
	return std::make_unique<StaticObstcale>(sprite, position);
})
&& 

ObjectFactory<StaticObject>::registerObject(sf::Color(0, 162, 232), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> 
{
	sf::Sprite sprite;
	switch (level)
	{
		case 1:
			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE2));
			break;
		case 2:
			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE2));
			break;
		case 3:
			sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE2));
			break;
	}
	return std::make_unique<StaticObstcale>(sprite, position);
})
&&

ObjectFactory<StaticObject>::registerObject(sf::Color(163, 73, 164), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject>
{
	sf::Sprite sprite;
	switch (level)
	{
	case 1:
		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE3));
		break;
	case 2:
		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE3));
		break;
	case 3:
		sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE3));
		break;
	}
	return std::make_unique<StaticObstcale>(sprite, position);
});


//-------------------------------------------------------------------------------------
StaticObstcale::StaticObstcale(const sf::Sprite& sprite, const sf::Vector2f& position)
	:StaticObject(sprite, position) {}