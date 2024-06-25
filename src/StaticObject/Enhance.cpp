
#include <memory>
#include "GameObject.h"
#include "StaticObject/Enhance.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/StaticObjectFactory.h"


// Register the jellybean type with the factory
bool Enhance::m_register = StaticObjectFactory::registerObject("enhance", [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_ENHANCE));
	return std::make_unique<Enhance>(sprite, position);
	});


//-----------------------------------------------------------------
Enhance::Enhance(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}


