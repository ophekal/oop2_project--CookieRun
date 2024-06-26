#pragma once
#include "Gift.h"

class Weapon : public Gift
{
public:
	Weapon(const sf::Sprite& sprite, const sf::Vector2f& position);

private:
	static bool m_register;
};