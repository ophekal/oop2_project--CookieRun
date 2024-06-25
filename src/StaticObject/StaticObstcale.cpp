
#include <memory>
#include "GameObject.h"
#include "StaticObject/StaticObstcale.h"
#include "StaticObject/StaticObject.h"
#include "HandleResources.h"
#include "Factories/StaticObjectFactory.h"


// Register the obstcale type with the factory
bool StaticObstcale::m_register = StaticObjectFactory::registerObject("obstcale", [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {

	sf::Sprite sprite;

	switch (level)
	{
		case 1:
		{
			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE1));
			break;
		}
		case 2:
		{
			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_OBSTACLE1));
			break;
		}
		case 3:
		{
			sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_OBSTACLE1));
			break;
		}
	}
	return std::make_unique<StaticObstcale>(sprite, position);
	});



//bool StaticObstacle::m_register = StaticObjectFactory::registerObject("obstacle", [](const sf::Vector2f& position) -> std::unique_ptr<StaticObject> {
//    // Decide which type of obstacle to create based on position or other criteria
//    obstcaleType type = obstcaleType::obstacle1;
//
//    sf::Sprite sprite;
//    switch (type) 
//    {
//    case obstcaleType::obstacle1:
//        sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE1));
//        break;
//    case obstcaleType::obstacle2:
//        sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE2));
//        break;
//    case obstcaleType::obstacle3:
//        sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_OBSTACLE3));
//        break;    }
//
//    return std::make_unique<StaticObstacle>(type, sprite, position);
//    });


//-----------------------------------------------------------------
StaticObstcale::StaticObstcale(const sf::Sprite& sprite, const sf::Vector2f& position)
	:StaticObject(sprite, position) {}

//StaticObstcale::StaticObstacle(obstcaleType type, const sf::Sprite& sprite, const sf::Vector2f& position)
//    : m_type(type), StaticObject(sprite, position) {}
