
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
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

//------------------------------------------------------------------------------------------------------
void MoveRandomStrategy::move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, const sf::Vector2f& enemyPosition)
{
    // Generate a random direction (left or right)
    int direction = std::rand() % 2 == 0 ? -1 : 1; // -1 for left, 1 for right

    // Set the movement speed
    float speed = 25.f;

    // Calculate movement based on direction
    sf::Vector2f movement(0.f, 0.f);
    movement.x += direction * speed;

    // Update the position of the enemy
    auto newEnemyPosition = enemyPosition + movement;
}