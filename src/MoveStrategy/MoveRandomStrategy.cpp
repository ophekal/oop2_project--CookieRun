
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveRandomStrategy.h"
#include "MovingObject/Player.h"


bool MoveRandomStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveRandomStrategy>(); });

//------------------------------------------------------------------------------------------------------
MoveRandomStrategy::MoveRandomStrategy()
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

    // Generate a random direction (left or right)
    int direction = (std::rand() % 2 == 0) ? LEFT : RIGHT;

    // Calculate movement based on direction
    sf::Vector2f movement(direction*4, 0.f);

    // Predict new position
    sf::Vector2f newPosition = enemy.getPosition() + movement;

    // Check for collision with obstacles
    bool collisionDetected = false;
    for (const auto& obstacle : staticObjects) 
    {
        if (enemy.getGlobalBounds().intersects(obstacle->getGlobalBounds())) 
        {
            collisionDetected = true;
            break;
        }
    }

    // If collision detected, stop movement
    if (collisionDetected) 
    {
        movement.x = 0.f;
    }
    else 
    {
        // Set the enemy's new position
        enemy.setPosition(newPosition.x, newPosition.y);
    }

    // Set the enemy's new position
    //newPosition = enemy.getPosition() + movement;
    //enemy.setPosition(newPosition.x, newPosition.y);

    // Update sprite facing direction based on movement
    enemy.setSpriteFlipped(direction == RIGHT);
}