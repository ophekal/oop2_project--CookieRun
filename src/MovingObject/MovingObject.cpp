#include "MovingObject/MovingObject.h"
#include <SFML/Graphics.hpp>
#include "HandleResources.h"

//--------------------------------------------------------------------------------------------
MovingObject::MovingObject(const sf::Sprite& sprite, float speed, const sf::Vector2f& position)
    :GameObject(sprite, position),  m_objectSpeed(speed)
{
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