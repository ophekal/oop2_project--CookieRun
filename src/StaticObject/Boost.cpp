
#include <memory>
#include "GameObject.h"
#include "StaticObject/Boost.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the boost type with the factory
bool Boost::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(255, 127, 39), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_BOOST));
	return std::make_unique<Boost>(sprite, position);
});


//-----------------------------------------------------------------
Boost::Boost(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}


