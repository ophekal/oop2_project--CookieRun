#pragma once
#include "Gift.h"

class Boost : public Gift
{
public:
	Boost(const sf::Sprite& sprite, const sf::Vector2f& position);
private:
	static bool m_register;
};
