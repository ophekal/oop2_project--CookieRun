#include "MovingObject/MovingObject.h"
#include <SFML/Graphics.hpp>
#include "HandleResources.h"

//--------------------------------------------------------------------------------------------
MovingObject::MovingObject(const sf::Sprite& sprite, float speed, const sf::Vector2f& position)
    :GameObject(sprite, position), /*m_spriteSheet(HandleResources::instance().getAnimationData(type), m_object, animationTime),*/ m_objectSpeed(speed)//picture, position, size)//, m_position(position), m_initPosition(position)
{
    // m_object.setTexture(&picture);
    // m_object.setPosition(position);
}
//-----------------------------------------------------------------------------------------
void MovingObject::setPosition(float x, float y)
{
    m_object.setPosition(x, y);
}
//--------------------------------------------------------------------------------
sf::Vector2f MovingObject::getPosition()const
{
    return m_object.getPosition();
}
//--------------------------------------------------------------------------------
void MovingObject::updatePosition(const sf::Vector2f& position)
{
    m_position = position;
}
//-------------------------------------------------------------------------------
void MovingObject::setObjectSpeed(float speed)
{
    m_objectSpeed = speed;
}
//-------------------------------------------------------------------------------
float MovingObject::getSpeed()const
{
    return m_objectSpeed;
}