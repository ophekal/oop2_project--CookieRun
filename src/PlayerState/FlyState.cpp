#include "MovingObject/Player.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"


#include <iostream>
//-------------------------------------------------------------------------------
FlyState::FlyState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
    : PlayerState(data, sprite, animationTime), m_flyDuration(sf::seconds(7)), m_moveDirection(0, 0)
{
}
//---------------------------------------------------------------------------------
std::unique_ptr<PlayerState> FlyState::handleEvent(Player& player, KeyboardInput pressed)
{
    std::cout << "on ground in handle input : " << player.onGround() << "\n";

    handleInput(pressed);

    // Transition to RunState if the player has landed and fly duration is over
    if ( pressed == K_NONE && player.onGround())
    {
        player.setIsFlyState(false);
        m_arriveToTarget = false;
        AnimationType aniType = getRunAnimationType(player.getPlayerType());
        return std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.1f));
    }

    return nullptr; // Stay in FlyState
}
//--------------------------------------------------------------------------
void FlyState::update(Player& player, sf::Time deltaTime)
{

    sf::Time elapsedTime = player.getGiftClock().getElapsedTime();
    sf::Time timeRemaining = m_flyDuration - elapsedTime;

    std::cout << "on ground: " << player.onGround() << "\n";
    std::cout << "remain time: " << timeRemaining.asSeconds() << "\n";

    if (timeRemaining > sf::Time::Zero)
    {
        // Target height and vertical bounds for flying
        sf::Vector2f targetPosition(player.getPosition().x, 100.0f);

        if (player.getPosition().y > targetPosition.y && !m_arriveToTarget)
        {
            moveTowardsTarget(player, deltaTime, targetPosition);
        }
        else
        {
            freeMovement(player, deltaTime);
        }
    }
    else
    {
        returnToGround(player, deltaTime);
    }

    // Update the animation for the player sprite
    m_animation.update(deltaTime);
}
//---------------------------------------------------------------------------
void FlyState::handleInput(KeyboardInput pressed)
{
    if (pressed == K_UP)
    {
        m_moveDirection = sf::Vector2f(0, -1); // Move up
    }
    else if (pressed == K_DOWN)
    {
        m_moveDirection = sf::Vector2f(0, 1);  // Move down
    }
    else if (pressed == K_NONE)
    {
        m_moveDirection = sf::Vector2f(0, 0); // Stop vertical movement
    }
}
//--------------------------------------------------------------------------
void FlyState::moveTowardsTarget(Player& player, sf::Time deltaTime, const sf::Vector2f& target)
{
    std::cout << "move to target on ground : " << player.onGround() << "\n";
    float moveAmount = -player.getSpeed() * deltaTime.asSeconds();
    player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

    // Ensure the player does not move past the target height
    if (player.getPosition().y < target.y)
    {
        m_arriveToTarget = true;
        player.setPosition(player.getPosition().x, target.y);
    }
}
//------------------------------------------------------------------------------------
void FlyState::freeMovement(Player& player, sf::Time deltaTime)
{
    // Define the vertical bounds for free movement in the fly state
    float upperBound = 30.0f;

    // Movement amount is proportional to the player's speed and the direction vector
    sf::Vector2f movement(player.getSpeed() * deltaTime.asSeconds(), m_moveDirection.y * player.getSpeed() * deltaTime.asSeconds());
    sf::Vector2f newPosition = player.getPosition() + movement;

    // Constrain the new position within the specified vertical bounds
    if (newPosition.y < upperBound)
    {
        newPosition.y = upperBound;
    }
    else if (newPosition.y >= PLAYER_INIT_POSITION.y)
    {
        newPosition.y = PLAYER_INIT_POSITION.y;
        player.setOnGround(true);
    }

    player.setPosition(newPosition.x, newPosition.y);
}
//-----------------------------------------------------------------------------------
void FlyState::returnToGround(Player& player, sf::Time deltaTime)
{

    if (player.getPosition().y < PLAYER_INIT_POSITION.y)
    {
        float moveAmount = player.getSpeed() * deltaTime.asSeconds();
        player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

        // Ensure the player doesn't go below the ground position
        if (player.getPosition().y > PLAYER_INIT_POSITION.y)
        {
            player.setPosition(player.getPosition().x, PLAYER_INIT_POSITION.y);
            player.setOnGround(true); // For transitioning to run state
            player.setIsFlyState(false);
        }
    }
    else
    {
        // Reset player to the ground position
        player.setPosition(player.getPosition().x, PLAYER_INIT_POSITION.y);
        player.setOnGround(true); // For transitioning to run state
        player.setIsFlyState(false);
    }
}
