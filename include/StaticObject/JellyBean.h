#pragma once
#include "Gift.h"

class JellyBean : public Gift
{
public:
	JellyBean(const sf::Sprite& sprite, const sf::Vector2f& position);

private:
	static bool m_register;
};