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
   // void setMembers(RunState& runState);
    //void updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);

private:
   // Animation m_animation;
    sf::Time m_flyDuration;
    //RunState* m_runState;

    sf::Vector2f m_moveDirection;
};