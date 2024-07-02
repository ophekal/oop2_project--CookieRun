
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveSmartStrategy.h"
#include "MovingObject/Player.h"


bool MoveSmartStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveSmartStrategy>(); });

//------------------------------------------------------------------------------------------------------
// This is the movement function for the smart movement, the enemy moves towards the player and moves in
// x and y axis

void MoveSmartStrategy::move(const sf::Vector2f& playerPosition, Enemy& enemy)
{
    int direction = LEFT;
    sf::Vector2f newPosition = enemy.getPosition();
    sf::Vector2f movement(direction * 4, 0.f);
    enemy.setSpriteFlipped(direction);

    // Move towards the player in the x direction
    if (newPosition.x > playerPosition.x)
    {
        newPosition.x--; // Move left
    }

     //Move towards the player in the y direction
    if (newPosition.y < playerPosition.y) 
    {
        newPosition.y++; // Move down
    }
    else if (newPosition.y > playerPosition.y) 
    {
        newPosition.y--; // Move up
    }
   
    newPosition += movement;
    enemy.setPosition(newPosition.x, newPosition.y);
}