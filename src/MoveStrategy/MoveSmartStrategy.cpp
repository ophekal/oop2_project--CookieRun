
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveSmartStrategy.h"
#include "MovingObject/Player.h"


bool MoveSmartStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveSmartStrategy>(); });

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// this movment not is not effected by obstcales

void MoveSmartStrategy::move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)
{
    //    std::cout << "in smart enemy movement\n";
    //
    //
    //    sf::Vector2f newPosition = enemy.getPosition();
    //
    //    // Move towards the player in the x direction
    //    if (newPosition.x > playerPosition.x) 
    //    {
    //        newPosition.x--; // Move left
    //    }
    //
    //    // Move towards the player in the y direction
    //    if (newPosition.y < playerPosition.y) 
    //    {
    //        newPosition.y++; // Move down
    //    }
    //    else if (newPosition.y > playerPosition.y) {
    //        newPosition.y--; // Move up
    //    }
    //
    //    // Set the enemy's new position
    //    enemy.setPosition(newPosition.x,newPosition.y);
    //};

    int direction = LEFT;
    sf::Vector2f newPosition = enemy.getPosition();
    sf::Vector2f movement(direction * 4, 0.f);
    enemy.setSpriteFlipped(direction);

    // Move towards the player in the x direction
    if (newPosition.x > playerPosition.x)
    {
        newPosition.x--; // Move left
    }

    newPosition += movement;

    enemy.setPosition(newPosition.x, newPosition.y);
}