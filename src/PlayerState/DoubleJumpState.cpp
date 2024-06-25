
#include "MovingObject/Player.h"
#include "PlayerState/DoubleJumpState.h"
#include "PlayerState/RunState.h"

DoubleJumpState::DoubleJumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	:m_animation(data, sprite, animationTime)
{
}
//--------------------------------------------------------------------------------------
PlayerState* DoubleJumpState::handleEvent(Player& player, KeyboardInput pressed)
{
	std::cout << "distance in doublejump0 : " << m_jumpDistance << "\n";

	if (pressed == K_NONE && player.onGround()) // end his jump
	{
		std::cout << "distance in doublejump1 : " << m_jumpDistance << "\n";
		m_jumpDistance = 0;
		return m_runState;
	}
	else if (pressed == K_NONE)
	{
		std::cout << "distance in jdoublejump2 : " << m_jumpDistance << "\n";
		return this; // Stay in jump state
	}

    // No state change
    return this;
}
//---------------------------------------------------------------------------------------
void DoubleJumpState::update(Player& player, sf::Time deltaTime)
{
	m_jumpDistance += std::abs(player.getGravity()) * deltaTime.asSeconds(); // Track absolute distance

	if (!(player.onGround()) && m_jumpDistance >= MaxDoubleJump)   // the player need to get to the ground
	{
		m_jumpDistance = 0;
		player.setGravity(5);
	}

	player.updateGravity(0.2);

	player.move(deltaTime.asSeconds());


	m_animation.update(deltaTime);;

}
//--------------------------------------------------------------------------------
void DoubleJumpState::setMembers(RunState& runState)
{
	m_runState = &runState;
}
//----------------------------------------------------------------------------------------------
void DoubleJumpState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
	m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------
