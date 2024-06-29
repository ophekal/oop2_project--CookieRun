
#include <memory>
#include "GameObject.h"
#include "StaticObject/Weapon.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the weapon into the factory
bool Weapon::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(63, 72, 204), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_WEAPON));
	return std::make_unique<Weapon>(sprite, position);
	});


//-----------------------------------------------------------------
Weapon::Weapon(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}


