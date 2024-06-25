#pragma once
#include "Gift.h"


class FlyingGift : public Gift
{
public:
	FlyingGift(const sf::Sprite& sprite, const sf::Vector2f& position);

private:
	static bool m_register;
};