
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveRandomStrategy.h"
#include "MovingObject/Player.h"


bool MoveRandomStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveRandomStrategy>(); });

//------------------------------------------------------------------------------------------------------
MoveRandomStrategy::MoveRandomStrategy()
    :m_direction(0)//change to enum
{
    // Seed the random number generator once globally
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
}

//------------------------------------------------------------------------------------------------------
// Move randomly left or right and handle collisions with obstacles

void MoveRandomStrategy::move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)
{
    std::cout << "in random enemy movement\n";

    if (m_direction == 0)
    {
        // Generate a random direction (left or right)
        m_direction = (std::rand() % 2 == 0) ? LEFT : RIGHT;
    }
   

    // Check for collision with obstacles
    bool collisionDetected = false;
    for (const auto& obstacle : staticObjects) 
    {
        if (enemy.getGlobalBounds().intersects(obstacle->getGlobalBounds())) 
        {
            collisionDetected = true;
            m_direction *= -1;
            enemy.setSpriteFlipped(m_direction);
            break;
        }
    }

    sf::Vector2f movement(m_direction * 4, 0.f);
    sf::Vector2f newPosition = enemy.getPosition() + movement;

    enemy.setPosition(newPosition.x, newPosition.y);
}