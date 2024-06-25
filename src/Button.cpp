
#include <SFML/Graphics.hpp>
#include "Button.h"

//---------------------------------------------------------------------------------------
Button::Button(const sf::Texture& background, float y, float x, const sf::Vector2f size) 
{
    m_rectangle.setSize(size);
    m_rectangle.setPosition(x, y);
    m_rectangle.setTexture(&background);
}

//---------------------------------------------------------------------------------------
void Button::printButton(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
}

//---------------------------------------------------------------------------------------
const sf::RectangleShape& Button::getRectangleButton() const
{
    return m_rectangle;
}

//---------------------------------------------------------------------------------------
void Button::setButtonTexture(const sf::Texture* texture)
{
    m_rectangle.setTexture(texture);
}

//---------------------------------------------------------------------------------------
bool Button::onClick(const sf::Vector2f location) const
{
    return  m_rectangle.getGlobalBounds().contains(location);
}
