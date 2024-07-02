
#include <memory>
#include "GameObject.h"
#include "StaticObject/FlyingGift.h"
#include "StaticObject/Gift.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"


// Register the flying gift into the factory
bool FlyingGift::m_register = ObjectFactory<StaticObject>::registerObject(sf::Color(136, 0, 21), [](const sf::Vector2f& position, int level) -> std::unique_ptr<StaticObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_FLIGHT));
	return std::make_unique<FlyingGift>(sprite, position);});


//-----------------------------------------------------------------------------
FlyingGift::FlyingGift(const sf::Sprite& sprite, const sf::Vector2f& position)
	:Gift(sprite, position) {}


