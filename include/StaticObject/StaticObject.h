#pragma once
#include "GameObject.h"


class StaticObject :public GameObject
{
public:
	StaticObject(const sf::Sprite& sprite, const sf::Vector2f& position);
	virtual ~StaticObject() = default;
};