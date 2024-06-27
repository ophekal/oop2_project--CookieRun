#include "AnimationObject/AnimationObject.h"
#include <SFML/Graphics.hpp>
#include "HandleResources.h"

//--------------------------------------------------------------------------------------------
AnimationObject::AnimationObject(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position)
    :MovingObject(sprite, speed, position), m_spriteSheet(HandleResources::instance().getAnimationData(type), m_object, animationTime)/*,m_objectSpeed(speed)*///picture, position, size)//, m_position(position), m_initPosition(position)
{
}

//-----------------------------------------------------------------
void AnimationObject::updateAnimation(sf::Time deltaTime)
{
	m_object.move(sf::Vector2f{ 0,0 }*deltaTime.asSeconds() * m_objectSpeed);
	m_spriteSheet.update(deltaTime);

}