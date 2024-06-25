
#include <memory>
#include "GameObject.h"
#include "AnimationObject/AnimationObject.h"
#include "AnimationObject/Coin.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"

// Register the Coin type with the factory
bool Coin::m_register = ObjectFactory<AnimationObject>::registerObject(sf::Color(255, 242, 0), [](const sf::Vector2f& position, int level) -> std::unique_ptr<AnimationObject> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_COIN));
	float speed = 40.f;
	sf::Time animationTime = sf::seconds(0.2f);
	AnimationType type = ANI_COIN;
	return std::make_unique<Coin>(sprite, speed, animationTime, type, position);
	});


//-----------------------------------------------------------------
Coin::Coin(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position)
	:AnimationObject(sprite, speed, animationTime, type, position)
{
	m_object.setPosition(position);
}

//-----------------------------------------------------------------
void Coin::updateAnimation(sf::Time deltaTime)
{
	m_object.move(sf::Vector2f{ 0,0 }*deltaTime.asSeconds() * m_objectSpeed);
	m_spriteSheet.update(deltaTime);

}
