
#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Macros.h"


class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Sprite& sprite, float speed, const sf::Vector2f& position);
	virtual ~MovingObject() = default;
	virtual void setPosition(float x, float y);
	sf::Vector2f getPosition()const;
	float getSpeed()const;
	void setObjectSpeed(float speed);

protected:
	float m_objectSpeed = 80.f;		//each object will update accordingly

};