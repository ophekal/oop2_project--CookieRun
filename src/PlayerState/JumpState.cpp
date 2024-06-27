
#include "MovingObject/Player.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"
#include <iostream>

JumpState::JumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	: PlayerState(data, sprite, animationTime),m_gravity(0.35)
{
}
//-------------------------------------------------------------------------------
std::unique_ptr<PlayerState> JumpState::handleEvent(Player& player, KeyboardInput pressed)
{

    if (pressed == K_NONE && player.onGround()) // end his jump
    {
       // m_jumpDistance = 0;
        m_gravity = 0;
        AnimationType aniType = getRunAnimationType(player.getPlayerType());
        return std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.1f));
    }
    else if (pressed == K_NONE)
    {
        return nullptr; // Stay in jump state
    }

  
    return nullptr;
}
//---------------------------------------------------------------------------------------
void JumpState::update(Player& player, sf::Time deltaTime)
{
	// Update jump distance
	//m_jumpDistance += std::abs(player.getGravity())* deltaTime.asSeconds() ; // Track absolute distance

    if (player.onGround()) // start the jump
    {
        player.setVelocityY(-25);
        player.setOnGround(false);
    }

    player.updateGravity(0.2);
    player.move(deltaTime.asSeconds());

	m_animation.update(deltaTime);
}
