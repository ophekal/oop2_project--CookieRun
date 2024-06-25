
#include "MovingObject/Player.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/RunState.h"

#include <iostream>

JumpState::JumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	: m_animation(data, sprite, animationTime)
{
}
//-------------------------------------------------------------------------------
PlayerState* JumpState::handleEvent(Player& player, KeyboardInput pressed)
{
    std::cout << "distance in jump0 : " << m_jumpDistance << "\n";

    if (pressed == K_NONE && player.onGround()) // end his jump
    {
        std::cout << "distance in jump1 : " << m_jumpDistance << "\n";
        m_jumpDistance = 0;
        return m_runState;
    }
    else if (pressed == K_NONE)
    {
        std::cout << "distance in jump2 : " << m_jumpDistance << "\n";
        return this; // Stay in jump state
    }
    else if (pressed == K_UP && m_jumpDistance >= 0.4 && m_jumpDistance <= 0.8)
    {
        std::cout << "distance in jump3 : " << m_jumpDistance << "\n";
        m_jumpDistance = 0;
        return m_doubleJumpState;
    }

    // No state change
  
    return this;
}
//---------------------------------------------------------------------------------------
void JumpState::update(Player& player, sf::Time deltaTime)
{
	// Update jump distance
	m_jumpDistance += std::abs(player.getGravity())* deltaTime.asSeconds() ; // Track absolute distance

    if (player.onGround()) // start the jump
    {
        player.setGravity(-5);
    }
    else if( !(player.onGround()) && m_jumpDistance >= MaxJump)   // the player need to get to the ground
    {
        m_jumpDistance = 0;
        player.setGravity(5);
    }

    player.updateGravity(0.2);
   

    player.move(deltaTime.asSeconds());

	m_animation.update(deltaTime);
}
//--------------------------------------------------------------------------------
void JumpState::setMembers(RunState& runState, DoubleJumpState& doubleJump)
{
	m_runState = &runState;
	m_doubleJumpState = &doubleJump;
}
//----------------------------------------------------------------------------------------------
void JumpState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
    m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------
