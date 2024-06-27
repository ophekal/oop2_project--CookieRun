#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"

class RunState;

class FlyState : public PlayerState
{
public:
    FlyState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    std::unique_ptr<PlayerState> handleEvent(Player& player, KeyboardInput pressed);
    void update(Player& player, sf::Time deltaTime);

private:
    sf::Time m_flyDuration;
    sf::Vector2f m_moveDirection;
};