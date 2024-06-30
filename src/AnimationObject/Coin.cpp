
#include <memory>
#include "GameObject.h"
#include "AnimationObject/AnimationObject.h"
#include "AnimationObject/Coin.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"
#include <cmath>

// Register the Coin type with the factory
bool Coin::m_register = ObjectFactory<Coin>::registerObject(sf::Color(255, 242, 0), [](const sf::Vector2f& position, int level) -> std::unique_ptr<Coin> {
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getGiftTexture(G_COIN));
	float speed = 1000.f;
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
//-----------------------------------------------------------------------
void Coin::updatePositionTowardsPlayer(const sf::Vector2f& playerPosition, float deltaTime)
{
    sf::Vector2f direction = playerPosition - m_object.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 1.0f)
    {
        direction = direction / distance;
        sf::Vector2f movement = direction * m_objectSpeed * deltaTime;
        m_object.move(movement);
    }
}
