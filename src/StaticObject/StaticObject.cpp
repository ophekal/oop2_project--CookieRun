#include "StaticObject/StaticObject.h"
#include <SFML/Graphics.hpp>

//--------------------------------------------------------------------------------------------
StaticObject::StaticObject(const sf::Sprite& sprite, const sf::Vector2f& position)
    :GameObject(sprite, position) {};