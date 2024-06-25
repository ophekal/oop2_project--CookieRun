
#pragma once

#include "PlayerState/PlayerState.h"
#include "Animation.h"

class RunState;

class SlideState : public PlayerState
{
public:
    SlideState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    PlayerState* handleEvent(Player& player, KeyboardInput pressed) override;
    void update(Player& player, sf::Time deltaTime) override;
    void setMembers(RunState& runState);
    void updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);

private:
    Animation m_animation;
    RunState* m_runState;
};