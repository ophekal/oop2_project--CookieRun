
#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"

class RunState;
class EnhanceState;


class JumpState : public PlayerState
{
public:
    JumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    PlayerState* handleEvent(Player& player, KeyboardInput pressed);
    void update(Player& player, sf::Time deltaTime);
    void setMembers(RunState& runState);
    void updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);

private:
    Animation m_animation;
    RunState* m_runState;
   // DoubleJumpState* m_doubleJumpState;
    float m_jumpDistance = 0.0f;

};