
#include "MovingObject/Player.h"
#include "PlayerState/PlayerState.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/RunState.h"
#include "PlayerState/SlideState.h"
#include "HandleResources.h"

#include <iostream>

//-----------------------------------------------------------------------------------------------
RunState::RunState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
    : PlayerState(data, sprite, animationTime)
{

}
//--------------------------------------------------------------------------------------
std::unique_ptr<PlayerState> RunState::handleEvent(Player& player, KeyboardInput pressed)
{
    if (pressed == K_NONE)
    {
        return nullptr;
    }
    else if (pressed == K_UP)
    {
        AnimationType aniType = getJumpAnimationType(player.getPlayerType());
        return std::make_unique<JumpState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.3f));
        
    }
    else if (pressed == K_DOWN)
    {
        //player.setPosition(player.getPosition().x, player.getPosition().y + (player.getSize().height / 2));
        AnimationType aniType = getSlideAnimationType(player.getPlayerType());
        return std::make_unique<SlideState>(HandleResources::instance().getAnimationData(aniType), player.getPlayerSpriteForAnimation(), sf::seconds(0.1f));
    }

    return nullptr;
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
