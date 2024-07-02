
#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "MovingObject/MovingObject.h"
#include "Animation.h"
#include "Macros.h"


class AnimationObject : public MovingObject
{
public:
	AnimationObject(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position);
	virtual ~AnimationObject() = default;
	virtual void updateAnimation(sf::Time deltaTime);

protected:
	Animation m_spriteSheet;
};