#pragma once
#include "AnimationObject/AnimationObject.h"
#include "StaticObject/StaticObject.h"
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"



class Loader
{
public:
    Loader() = default;
    void updateMembers(int levelNumber, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
        std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies);

    // Move constructor
    //Loader(Loader&&) = default;

    // Move assignment operator
   // Loader& operator=(Loader&&) = default;

    // Delete copy constructor and copy assignment operator
   // Loader(const Loader&) = delete;
    //Loader& operator=(const Loader&) = delete;
};
