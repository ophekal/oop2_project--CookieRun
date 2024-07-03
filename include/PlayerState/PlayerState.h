
#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"

class Player;


class PlayerState 
{
public:
    PlayerState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    virtual ~PlayerState() = default;
    virtual std::unique_ptr<PlayerState> handleEvent(Player& player, KeyboardInput pressed)=0;
    virtual void update(Player& player, sf::Time deltaTime) = 0;
    virtual void restartAnimation(); 
    void updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);
    AnimationType getRunAnimationType(Players player);
    AnimationType getSlideAnimationType(Players player);
    AnimationType getJumpAnimationType(Players player);

protected:
    Animation m_animation;
};