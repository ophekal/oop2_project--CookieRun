#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"


class SlideState;
class JumpState;
class DoubleJumpState;


class RunState : public PlayerState
{
public:
    RunState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    std::unique_ptr<PlayerState> handleEvent(Player& player, KeyboardInput pressed) override;
    void update(Player& player, sf::Time deltaTime) override;
};