
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//----------------------------------------------------------------------------------------
GameObject::GameObject(const sf::Sprite& sprite, const sf::Vector2f& position)
	:m_object(sprite)
{
	m_object.setPosition(position);

	//m_object.setTexture(picture);

	// Get the texture size
	//sf::Vector2u textureSize = m_object.getTexture()->getSize();

	// Calculate scale factors
	//float scaleX = static_cast<float>(60) / textureSize.x;
	//float scaleY = static_cast<float>(60) / textureSize.y;

	// Apply the scale to the sprite
	//m_object.setScale(scaleX, scaleY);


	//m_object.setTexture(&picture);
	//m_object.setPosition(position);
}

//-------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_object);
}