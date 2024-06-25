
#include "MovingObject/Player.h"
#include "PlayerState/PlayerState.h"
#include "PlayerState/DoubleJumpState.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/RunState.h"
#include "PlayerState/SlideState.h"


#include <iostream>

//-----------------------------------------------------------------------------------------------
RunState::RunState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime,
    SlideState& slideState, JumpState& jumpState, DoubleJumpState& doubleJump)
    : m_animation(data, sprite, animationTime),
      m_slideState(slideState), m_jumpState(jumpState), m_doubleJumpState(doubleJump)
{

}
//--------------------------------------------------------------------------------------
PlayerState* RunState::handleEvent(Player& player, KeyboardInput pressed)
{
    if (pressed == K_NONE)
    {
        return this;
    }
    else if (pressed == K_UP)
    {
        return &m_jumpState;
    }
    else if (pressed == K_DOWN)
    {
        return &m_slideState;
    }

    return this;
}
//---------------------------------------------------------------------------------------
void RunState::update(Player& player, sf::Time deltaTime)
{
    if (player.onGround())
    {
        player.resetGravity();
    }
    else
    {
        player.updateGravity(deltaTime.asSeconds()*350);
    }
    player.move(deltaTime.asSeconds());

    m_animation.update(deltaTime);
}
//---------------------------------------------------------------------------------------
void RunState::restartAnimation()
{
    m_animation.setIndex(0);

}
//----------------------------------------------------------------------------------------------
void RunState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
    m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------
