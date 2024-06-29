
#pragma once
#include "Gift.h"

class Magnet : public Gift
{
public:
	Magnet(const sf::Sprite& sprite, const sf::Vector2f& position);
private:
	static bool m_register;
};
