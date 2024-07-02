
#include <memory>
#include "GameObject.h"
#include "StaticObject/Magnet.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the magnet into the factory
bool Magnet::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(249,54,9), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_MAGNET));
	return std::make_unique<Magnet>(sprite, position);});


//---------------------------------------------------------------------
Magnet::Magnet(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}

