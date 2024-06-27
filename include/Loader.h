#pragma once
#include "AnimationObject/AnimationObject.h"
#include "StaticObject/StaticObject.h"
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"
#include "AnimationObject/Coin.h"



class Loader
{
public:
    Loader() = default;
    void updateMembers(int levelNumber, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
        std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
        std::vector< std::unique_ptr<Coin>>& coins, sf::Vector2f& flagPosition);

};
