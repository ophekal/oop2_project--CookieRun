#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const sf::Sprite& sprite, const sf::Vector2f& position);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window);
	void markForDeletion();
	bool isMarkedForDeletion()const;
	sf::FloatRect getSize()const;
	const sf::Sprite& getObject()const;
	sf::FloatRect getGlobalBounds()const;

protected:
	sf::Sprite m_object;
	bool toBeDeleted = false;
};