
#include "MovingObject/Player.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"
#include <iostream>

JumpState::JumpState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
    : PlayerState(data, sprite, animationTime) {}

//-------------------------------------------------------------------------------------------------
// This function is responsible for handeling the key presses and sending back pointers to the
// next state the player needs to transfer into according to the pressed variable

std::unique_ptr<PlayerState> JumpState::handleEvent(Player& player, KeyboardInput pressed)
{

    if (pressed == K_NONE && player.onGround()) // end his jump
    {
        AnimationType aniType = getRunAnimationType(player.getPlayerType());
        return std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.1f));
    }
    else if (pressed == K_NONE)
    {
        return nullptr; // Stay in jump state
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
void JumpState::update(Player& player, sf::Time deltaTime)
{
    // Set the origin of the player's sprite to its center
    sf::FloatRect bounds = player.getPlayerSpriteForAnimation().getGlobalBounds();
    player.getPlayerSpriteForAnimation().setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    if (player.onGround()) // start the jump
    {
        player.setVelocityY(-10);
        player.setOnGround(false);
    }

    // Apply gravity to the vertical component
    player.updateGravity(deltaTime.asSeconds());
    player.move(deltaTime.asSeconds());
    m_animation.update(deltaTime);
}
