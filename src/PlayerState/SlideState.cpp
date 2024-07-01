
#include "MovingObject/Player.h"
#include "PlayerState/SlideState.h"
#include "PlayerState/RunState.h"
#include "HandleResources.h"

#include <iostream>

SlideState::SlideState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	: PlayerState(data, sprite, animationTime)
{
}
//--------------------------------------------------------------------------------------
std::unique_ptr<PlayerState> SlideState::handleEvent(Player& player, KeyboardInput pressed)
{
    if (pressed == K_NONE) 
    {
        player.setPosition(player.getPosition().x, player.getPosition().y - (player.getSize().height /2)+5);
        AnimationType aniType = getRunAnimationType(player.getPlayerType());
        return std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.1f));
    }
    else if (pressed == K_DOWN)
    {
        return nullptr;
    }

    return nullptr;
}
//---------------------------------------------------------------------------------------
void SlideState::update(Player& player, sf::Time deltaTime)
{
    // Set the origin of the player's sprite to its center
    sf::FloatRect bounds = player.getPlayerSpriteForAnimation().getGlobalBounds();
    player.getPlayerSpriteForAnimation().setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);


    if (player.onGround())
    {
        player.resetGravity();
    }
    else
    {
        player.updateGravity(deltaTime.asSeconds() * 350);
    }
    player.move(deltaTime.asSeconds());

    m_animation.update(deltaTime);
}
