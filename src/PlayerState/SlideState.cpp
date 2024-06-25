
#include "MovingObject/Player.h"
#include "PlayerState/SlideState.h"
#include "PlayerState/RunState.h"

#include <iostream>

SlideState::SlideState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	: m_animation(data, sprite, animationTime)
{
}
//--------------------------------------------------------------------------------------
PlayerState* SlideState::handleEvent(Player& player, KeyboardInput pressed)
{
    if (pressed == K_NONE) 
    {
        return m_runState;
    }
    else if (pressed == K_DOWN)
    {
        return this;
    }

    return this;
}
//---------------------------------------------------------------------------------------
void SlideState::update(Player& player, sf::Time deltaTime)
{
    player.resetGravity();
    player.setPosition(player.getPosition().x, player.getPosition().y + (player.getSize().height / 2)); 
    player.move(deltaTime.asSeconds());

    m_animation.update(deltaTime);
}

//--------------------------------------------------------------------------------
void SlideState::setMembers(RunState& runState)
{
	m_runState = &runState;
}
//----------------------------------------------------------------------------------------------
void SlideState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
    m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------
