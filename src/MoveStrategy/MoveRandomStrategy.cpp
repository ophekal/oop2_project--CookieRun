
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveRandomStrategy.h"
#include "MovingObject/Player.h"


bool MoveRandomStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> 
{ return std::make_unique<MoveRandomStrategy>(); });

//------------------------------------------------------------------------------------------------------
MoveRandomStrategy::MoveRandomStrategy()
{
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
// Move randomly left or right and handle collisions with obstacles

void MoveRandomStrategy::move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)
{
    // Generate a random direction (left or right)
    int direction = std::rand() % 2 == 0 ? -1 : 1; // -1 for left, 1 for right

    // Calculate movement based on direction
    sf::Vector2f movement(0.f, 0.f);
    movement.x += direction * enemy.getSpeed();

    // Update the position of the enemy
    auto newEnemyPosition = enemy.getPosition() + movement;

    //// Create a temporary sprite to represent the new position (for collision checking)
    //sf::Sprite tempSprite = enemy.getSprite(); // Assuming Enemy class has getSprite method
    //tempSprite.setPosition(newEnemyPosition);

    // Check for collision with obstacles
    bool collisionDetected = false;
    for (const auto& obstacle : staticObjects) {
        if (enemy.getGlobalBounds().intersects(obstacle->getGlobalBounds())) {
            // Collision detected, reverse direction
            movement.x = -movement.x; // Change direction
            collisionDetected = true;

            // Update sprite facing direction (assuming sprite can be flipped horizontally)
            enemy.setSpriteFlipped(direction == 1); // Flip sprite based on the initial direction

            // Update new position after reversing direction
            newEnemyPosition = enemy.getPosition() + movement;
            break; // Break out after handling the first collision
        }
    }

    // If no collision was detected, update the enemy's position normally
    if (!collisionDetected) {
        enemy.setPosition(newEnemyPosition.x, newEnemyPosition.y);
    }
    else {
        // If collision was detected and direction reversed, update to new position after reversing
        enemy.setPosition(newEnemyPosition.x, newEnemyPosition.y);
    }
}