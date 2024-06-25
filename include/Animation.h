#pragma once

//#include "Direction.h"
//#include "AnimationData.h"

#include <SFML/Graphics.hpp>
#include <Vector>

class Animation
{
public:
    Animation(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    void update(sf::Time delta);
    void changeAnimation(std::vector<sf::IntRect>& frameSheet, sf::Sprite& sprite);
    void setIndex(int index);

private:
    void update();

    std::vector<sf::IntRect> m_frameSheet;
    sf::Time m_elapsed = {};
    const sf::Time m_animationTime;
    int m_frameIndex = 0;
    sf::Sprite& m_sprite;
};