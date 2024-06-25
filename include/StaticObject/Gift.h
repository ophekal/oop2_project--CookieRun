#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject/StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(const sf::Sprite& sprite, const sf::Vector2f& position) : StaticObject(sprite, position) {};
};