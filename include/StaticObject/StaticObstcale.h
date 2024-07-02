#pragma once
#include "StaticObject/StaticObject.h"

class StaticObstcale : public StaticObject
{
public:
	StaticObstcale(const sf::Sprite& sprite, const sf::Vector2f& position);
private:
	static bool m_register;
};