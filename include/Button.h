#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(const sf::Texture& background, float y, float x, const sf::Vector2f size);
	void printButton(sf::RenderWindow& window) const;
	const sf::RectangleShape& getRectangleButton()const;
	void setButtonTexture(const sf::Texture* texture);
	bool onClick(const sf::Vector2f location) const;

private:
	sf::RectangleShape m_rectangle;
};