
#include "MovingObject/Player.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"

FlyState::FlyState(std::vector<sf::IntRect>& data, sf::Sprite& sprite,const sf::Time& animationTime)
	: m_animation(data, sprite, animationTime), m_flyDuration(sf::seconds(7))
{
}
//--------------------------------------------------------------------------------------
PlayerState* FlyState::handleEvent(Player& player, KeyboardInput pressed)
{
	if (pressed ==K_NONE && !player.onGround())
	{
		return this;
	}
	else if(pressed == K_NONE && player.onGround())
	{
		return m_runState;
	}
    else if (pressed == K_UP)
    {
        m_moveDirection = sf::Vector2f(0, -1); // Move up
    }
    else if (pressed == K_DOWN)
    {
        m_moveDirection = sf::Vector2f(0, 1);  // Move down
    }      
	return this;
}
//--------------------------------------------------------------------------------------------
void FlyState::update(Player& player, sf::Time deltaTime)
{
    sf::Time elapsedTime = player.getGiftClock().getElapsedTime();
    sf::Vector2f targetPosition = { player.getPosition().x, 100 }; // Target height during the fly state
    sf::Vector2f groundPosition = { player.getPosition().x, PLAYER_INIT_POSITION.y };
    sf::Time timeRemaining = m_flyDuration - elapsedTime;

    // Define the vertical bounds for free movement in the fly state
    float upperBound = 30.0f;

    if (timeRemaining > sf::Time::Zero)
    {
        if (player.getPosition().y > targetPosition.y)
        {
            // Ignore player input and move the player up to the target height
            float moveAmount = -player.getSpeed() * deltaTime.asSeconds();
            player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

            // Ensure the player does not move past the target height
            if (player.getPosition().y < targetPosition.y)
            {
                player.setPosition(player.getPosition().x, targetPosition.y);
            }
        }
        else
        {
            // Allow free movement within bounds after reaching the target height
            sf::Vector2f movement(player.getSpeed() * deltaTime.asSeconds(), m_moveDirection.y * player.getSpeed() * deltaTime.asSeconds());
            sf::Vector2f newPosition = player.getPosition() + movement;

            // Constrain the new position within the specified vertical bounds
            if (newPosition.y < upperBound)
            {
                newPosition.y = upperBound;
            }

            player.setPosition(newPosition.x,newPosition.y);
        }
    }
    else
    {
        // Ignore player input and move the player back to the ground when fly time is up
        if (player.getPosition().y < groundPosition.y)
        {
            float moveAmount = player.getSpeed() * deltaTime.asSeconds();
            player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

            // Ensure the player doesn't go below the ground position
            if (player.getPosition().y > groundPosition.y)
            {
                player.setPosition(player.getPosition().x, groundPosition.y);
            }
        }
        else
        {
            // Reset player to the ground position
            player.setPosition(groundPosition.x, groundPosition.y);
            player.setOnGround(true); // For transitioning to run state
        }
    }

    // Update the animation for the player sprite
    m_animation.update(deltaTime);
}

////---------------------------------------------------------------------------------------
//void FlyState::update(Player& player, sf::Time deltaTime)
//{
//    sf::Time elapsedTime = player.getGiftClock().getElapsedTime();
//    sf::Vector2f targetPosition = { player.getPosition().x, 100 }; // Example upper part position
//    sf::Vector2f groundPosition = { player.getPosition().x, PLAYER_INIT_POSITION.y };
//    sf::Time timeRemaining = m_flyDuration - elapsedTime;
//
//
//    // Apply movement based on input
//    sf::Vector2f movement(player.getSpeed() * deltaTime.asSeconds(), m_moveDirection.y * player.getSpeed() * deltaTime.asSeconds());
//
//    if (timeRemaining > sf::Time::Zero)
//    {
//        if (player.getPosition().y > targetPosition.y)
//        {
//            float moveAmount = -player.getSpeed() * deltaTime.asSeconds();
//            player.move({ player.getSpeed() * deltaTime.asSeconds(),moveAmount });
//
//            if (player.getPosition().y < targetPosition.y)
//            {
//                player.setPosition(player.getPosition().x, targetPosition.y);
//            }
//        }
//        else
//        {
//            // Allow free movement when in the fly state after reaching the target height
//            player.move(movement);
//        }
//    }
//    else
//    {
//        if (player.getPosition().y < groundPosition.y)
//        {
//            float moveAmount = player.getSpeed() * deltaTime.asSeconds();
//            player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });
//
//            if (player.getPosition().y > groundPosition.y)
//            {
//                player.setPosition(player.getPosition().x, groundPosition.y);
//            }
//        }
//        else
//        {
//            player.setPosition(groundPosition.x, groundPosition.y);
//
//            // how to change back the texture to the original oven 
//
//            player.setOnGround(true); // for the  next handle event to go back to run state 
//        }
//    }
//   
//    m_animation.update(deltaTime);
//}
//--------------------------------------------------------------------------------
void FlyState::setMembers(RunState& runState)
{
	m_runState = &runState;
}
//----------------------------------------------------------------------------------------------
void FlyState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
    m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------
