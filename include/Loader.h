#pragma once
#include "AnimationObject/AnimationObject.h"
#include "StaticObject/StaticObject.h"
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"
#include "AnimationObject/Coin.h"
#include "LevelPartGenerator.h"


class Loader
{
public:
    Loader() = default;
    void updateMembers(int levelNumber, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
        std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
        std::vector< std::unique_ptr<Coin>>& coins, sf::Vector2f& flagPosition);
    
private:
    void addObjectsToVectors(int levelNumber, level& levelPart, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
        std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
        std::vector< std::unique_ptr<Coin>>& coins);
    void createRandomEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, float startX, float endX,int levelNumber);

    sf::Vector2f m_lastObjectPosition = { 0,0 };

};
