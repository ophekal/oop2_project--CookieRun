#include "Animation.h"

#include "HandleResources.h"


//-----------------------------------------------------------------------------------------------------
Animation::Animation(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime)
    : m_frameSheet(data), m_sprite(sprite), m_animationTime(animationTime)
{
    update();
}

//-----------------------------------------------------------------------------------------------------
// This function updates the animation according to the time passed
void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= m_animationTime)
    {
        m_elapsed -= m_animationTime;
        m_frameIndex = (m_frameIndex + 1) % m_frameSheet.size();
        update();
    }
}

//-----------------------------------------------------------------------------------------------------
// This function updates the animation texture

void Animation::update()
{
    m_sprite.setTextureRect(m_frameSheet[m_frameIndex]);
}

//-----------------------------------------------------------------------------------------------------
void Animation::changeAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite)
{
    m_sprite = sprite;
    m_frameSheet.assign(frameSheet.begin(), frameSheet.end());
    setIndex(0);
}

//-----------------------------------------------------------------------------------------------------
void Animation::setIndex(int index)
{
    m_frameIndex = index;
    update();
}