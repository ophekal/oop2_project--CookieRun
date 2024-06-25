#pragma once
#include "StaticObject/StaticObject.h"

class Floor : public StaticObject
{
public:
	Floor(const sf::Sprite& sprite, const sf::Vector2f& position);

private:
	static bool m_register;
};