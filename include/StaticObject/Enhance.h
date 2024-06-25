#pragma once
#include "Gift.h"

class Enhance : public Gift
{
public:
	Enhance(const sf::Sprite& sprite, const sf::Vector2f& position);
private:
	static bool m_register;
};
