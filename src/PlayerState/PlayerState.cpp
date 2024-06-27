

#include "PlayerState/PlayerState.h"


PlayerState::PlayerState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
	:m_animation(data, sprite, animationTime){}

//----------------------------------------------------------------------------------------------
void PlayerState::updateAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
	m_animation.changeAnimation(frameSheet, sprite);
}
//---------------------------------------------------------------------------------------------

AnimationType PlayerState::getRunAnimationType(Players player)
{
    switch (player)
    {
    case PLAYER_BRAVE:
        return ANI_COOKIEBRAVE_RUN;
        break;
    case PLAYER_BRIGHT:
        return ANI_COOKIEBRAVE_RUN;
        break;
    }
    return ANI_COOKIEBRAVE_RUN; //never get here
}
//---------------------------------------------------------------------------------------------
AnimationType PlayerState::getSlideAnimationType(Players player)
{
    switch (player)
    {
    case PLAYER_BRAVE:
        return ANI_COOKIEBRAVE_SLIDE;
        break;
    case PLAYER_BRIGHT:
        return ANI_COOKIEBRAVE_SLIDE;
        break;
    }
    return ANI_COOKIEBRAVE_SLIDE; //never get here
}
//--------------------------------------------------------------------------------------------
AnimationType PlayerState::getJumpAnimationType(Players player)
{
    switch (player)
    {
    case PLAYER_BRAVE:
        return ANI_COOKIEBRAVE_JUMP;
        break;
    case PLAYER_BRIGHT:
        return ANI_COOKIEBRAVE_JUMP;
        break;
    }
    return ANI_COOKIEBRAVE_JUMP; //never get here
}
