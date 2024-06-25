#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"


class SlideState;
class JumpState;
class DoubleJumpState;



class RunState : public PlayerState
{
public:
    RunState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime,
        SlideState& slideState, JumpState& jumpState, DoubleJumpState& doubleJump);
    PlayerState* handleEvent(Player& player, KeyboardInput pressed) override;
    void update(Player& player, sf::Time deltaTime) override;
    void restartAnimation();
    void updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);

private:
    Animation m_animation;
    SlideState& m_slideState;
    JumpState& m_jumpState;
    DoubleJumpState& m_doubleJumpState;

};