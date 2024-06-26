#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const sf::Sprite& sprite, const sf::Vector2f& position); // Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window);
	void markForDeletion() { toBeDeleted = true; }
	bool isMarkedForDeletion() const { return toBeDeleted; }
	sf::FloatRect getSize()const { return m_object.getLocalBounds(); }
	const sf::Sprite& getObject()const { return m_object; }
	sf::FloatRect getGlobalBounds()const { return m_object.getGlobalBounds(); }

protected:
	sf::Sprite m_object;
	bool toBeDeleted = false;
};