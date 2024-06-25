#include "AnimationObject/AnimationObject.h"
#include <SFML/Graphics.hpp>
#include "HandleResources.h"

//--------------------------------------------------------------------------------------------
AnimationObject::AnimationObject(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position)
    :MovingObject(sprite, speed, position), m_spriteSheet(HandleResources::instance().getAnimationData(type), m_object, animationTime)/*,m_objectSpeed(speed)*///picture, position, size)//, m_position(position), m_initPosition(position)
{
    // m_object.setTexture(&picture);
    // m_object.setPosition(position);
}
////-----------------------------------------------------------------------------------------
//void AnimationObject::setPosition(float x, float y)
//{
//    m_object.setPosition(x, y);
//}
////--------------------------------------------------------------------------------
//sf::Vector2f AnimationObject::getPosition()const
//{
//    return m_object.getPosition();
//}
////--------------------------------------------------------------------------------
//void AnimationObject::updatePosition(const sf::Vector2f& position)
//{
//    m_position = position;
//}
////-------------------------------------------------------------------------------
//void AnimationObject::setObjectSpeed(float speed)
//{
//    m_objectSpeed = speed;
//}