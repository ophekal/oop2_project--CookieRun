
#include <memory>
#include "GameObject.h"
#include "StaticObject/StaticObject.h"
#include "StaticObject/Floor.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"
#include <iostream>


// Register the floor into the factory
bool Floor::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(0, 0, 0), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> 
{
	sf::Sprite sprite;
	switch (level)
	{
		case 1:
			sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_FLOOR));
			break;
		case 2:
			sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_FLOOR));
			break;
		case 3:
			sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_FLOOR));
			break;
	}
	return std::make_unique<Floor>(sprite, position);
});


//-----------------------------------------------------------------
Floor::Floor(const sf::Sprite& sprite, const sf::Vector2f& position)
	:StaticObject(sprite, position) {}