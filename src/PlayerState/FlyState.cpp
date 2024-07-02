#include "MovingObject/Player.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"

//-------------------------------------------------------------------------------------------------
FlyState::FlyState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
    : PlayerState(data, sprite, animationTime), m_flyDuration(sf::seconds(7)), m_moveDirection(0, 0) {}


//-------------------------------------------------------------------------------------------------
// This function is responsible for handeling the key presses and sending back pointers to the
// next state the player needs to transfer into according to the pressed variable

std::unique_ptr<PlayerState> FlyState::handleEvent(Player& player, KeyboardInput pressed)
{
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

//-------------------------------------------------------------------------------------------------
void FlyState::handleInput(KeyboardInput pressed)
{
    if (pressed == K_UP)
    {
        m_moveDirection = DIRECTION_UP;
    }
    else if (pressed == K_DOWN)
    {
        m_moveDirection = DIRECTION_DOWN;
    }
    else if (pressed == K_NONE)
    {
        m_moveDirection = DIRECTION_NONE;
    }
}
//-------------------------------------------------------------------------------------------------
void FlyState::update(Player& player, sf::Time deltaTime)
{
    // Set the origin of the player's sprite to its center
    sf::FloatRect bounds = player.getPlayerSpriteForAnimation().getGlobalBounds();
    player.getPlayerSpriteForAnimation().setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    sf::Time elapsedTime = player.getGiftClock().getElapsedTime();
    sf::Time timeRemaining = m_flyDuration - elapsedTime;

    if (timeRemaining > sf::Time::Zero)
    {
        handleFlightBehavior(player, deltaTime);
    }
    else
    {
        returnToGround(player, deltaTime);
    }

    // Update the animation for the player sprite
    m_animation.update(deltaTime);
}

//-------------------------------------------------------------------------------------------------
// This function handles the flight behavior

void FlyState::handleFlightBehavior(Player& player, sf::Time deltaTime)
{
    // Target height and vertical bounds for flying
    sf::Vector2f targetPosition(player.getPosition().x, UP_BOUND);

    if (player.getPosition().y > targetPosition.y && !m_arriveToTarget)
    {
        moveTowardsTarget(player, deltaTime, targetPosition);
    }
    else
    {
        freeMovement(player, deltaTime);
    }
}

//-------------------------------------------------------------------------------------------------
// This function is called when the player enters the flight state and it makes sure the player
// gets to the target height defined

void FlyState::moveTowardsTarget(Player& player, sf::Time deltaTime, const sf::Vector2f& target)
{
    float moveAmount = -player.getSpeed() * deltaTime.asSeconds();
    player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

    // Ensure the player does not move past the target height
    if (player.getPosition().y < target.y)
    {
        m_arriveToTarget = true;
        player.setPosition(player.getPosition().x, target.y);
    }
}

//-------------------------------------------------------------------------------------------------
// This function allows the player once he arrives the target height to move freely. It moves him
// according to the direction that's sotred in m_moveDirection which was updated according to the
// key pressed in handleInput

void FlyState::freeMovement(Player& player, sf::Time deltaTime)
{
    // Movement amount is proportional to the player's speed and the direction vector
    sf::Vector2f movement(player.getSpeed() * deltaTime.asSeconds(), m_moveDirection.y * player.getSpeed() * deltaTime.asSeconds());
    sf::Vector2f newPosition = player.getPosition() + movement;

    // Constrain the new position within the specified vertical bounds
    if (newPosition.y < UP_BOUND)
    {
        newPosition.y = UP_BOUND;
    }
    else if (newPosition.y >= PLAYER_INIT_POSITION.y)
    {
        newPosition.y = PLAYER_INIT_POSITION.y;
        player.setOnGround(true);
    }

    player.setPosition(newPosition.x, newPosition.y);
}

//-------------------------------------------------------------------------------------------------
void FlyState::returnToGround(Player& player, sf::Time deltaTime)
{

    if (player.getPosition().y < PLAYER_INIT_POSITION.y)
    {
        float moveAmount = player.getSpeed() * deltaTime.asSeconds();
        player.move({ player.getSpeed() * deltaTime.asSeconds(), moveAmount });

        // Ensure the player doesn't go below the ground position
        if (player.getPosition().y > PLAYER_INIT_POSITION.y)
        {
            resetPlayerToGround(player);
        }
    }
    else
    {
        resetPlayerToGround(player);
    }
}

//-------------------------------------------------------------------------------------------------
//This function resets the player to the ground position
void FlyState::resetPlayerToGround(Player& player)
{
    player.setPosition(player.getPosition().x, PLAYER_INIT_POSITION.y);
    player.setOnGround(true); // For transitioning to run state
    player.setIsFlyState(false);
}