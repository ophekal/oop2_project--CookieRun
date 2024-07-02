
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//----------------------------------------------------------------------------------------
GameObject::GameObject(const sf::Sprite& sprite, const sf::Vector2f& position)
	:m_object(sprite)
{
	m_object.setPosition(position);
}

//----------------------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_object);
}