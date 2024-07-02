
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveRandomStrategy.h"
#include "MovingObject/Player.h"


bool MoveRandomStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveRandomStrategy>(); });

//------------------------------------------------------------------------------------------------------
MoveRandomStrategy::MoveRandomStrategy()
    :m_direction(START), m_timeSinceLastChange(sf::Time::Zero) 
{
    m_clock.restart();
}

//------------------------------------------------------------------------------------------------------
// This is the movement function for the random movement, the enemy moves randomly left or right every 3
// seconds, movement is only in the x axis

void MoveRandomStrategy::move(const sf::Vector2f& playerPosition, Enemy& enemy)
{
    m_timeSinceLastChange += m_clock.restart();

    // Change direction every 5 seconds
    if (m_timeSinceLastChange.asSeconds() > 3.0f)
    {
        m_direction = (std::rand() % 2 == 0) ? LEFT : RIGHT;
        enemy.setSpriteFlipped(m_direction);
        m_timeSinceLastChange = sf::Time::Zero;
    }

    // Set initial direction if not set
    if (m_direction == 0)
    {
        m_direction = (std::rand() % 2 == 0) ? LEFT : RIGHT;
        enemy.setSpriteFlipped(m_direction);
    }

    sf::Vector2f movement(m_direction * 4, 0.f);
    sf::Vector2f newPosition = enemy.getPosition() + movement;

    enemy.setPosition(newPosition.x, newPosition.y);
}
