
#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"

class RunState;
class EnhanceState;


class JumpState : public PlayerState
{
public:
    JumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    std::unique_ptr<PlayerState> handleEvent(Player& player, KeyboardInput pressed);
    void update(Player& player, sf::Time deltaTime);
    

private:
    float m_gravity;
    float m_jumpDistance = 0.0f;

};