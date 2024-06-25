
#include <memory>
#include "GameObject.h"
#include "StaticObject/JellyBean.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the jellybean type with the factory
bool JellyBean::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(234, 63, 247), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_JELLY));
	return std::make_unique<JellyBean>(sprite, position);
});


//-----------------------------------------------------------------
JellyBean::JellyBean(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}


