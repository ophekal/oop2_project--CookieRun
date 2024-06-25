
#include <iostream>
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MoveStrategy/MoveStrategy.h"
#include "MoveStrategy/MoveSmartStrategy.h"
#include "MovingObject/Player.h"


bool MoveSmartStrategy::m_register = EnemyFactory::registerMove([]()->std::unique_ptr<MoveStrategy> { return std::make_unique<MoveSmartStrategy>(); });

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void MoveSmartStrategy::move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy)
{
    //MovingObjects::setObjectSpeed(25.f);
    //srand(time(nullptr));
    //m_clock.restart();

    //Direction direction = static_cast<Direction>(rand() % 4); // Generate a random direction

    ////Calculate movement vector based on direction and speed
    //sf::Vector2f movement(0.f, 0.f);
    //switch (direction)
    //{
    //case (D_LEFT):
    //    m_object.setTexture(HandleResources::instance().getObjectTexture(I_L_CAT));
    //    movement.x -= m_objectSpeed * deltaTime.asSeconds();
    //    break;
    //case D_RIGHT:
    //    m_object.setTexture(HandleResources::instance().getObjectTexture(I_R_CAT));
    //    movement.x += m_objectSpeed * deltaTime.asSeconds();
    //    break;
    //case D_UP:
    //    movement.y -= m_objectSpeed * deltaTime.asSeconds();
    //    break;
    //case D_DOWN:
    //    movement.y += m_objectSpeed * deltaTime.asSeconds();
    //    break;
    //}
    //add random movement, enemy walks from side to side trying when colliding with object chaninging direction
};
