#pragma once
#include "LevelPartGenerator.h"

class LevelCommand;

class Loader
{
public:
    Loader() = default;
    void updateMembers(LevelCommand& level);
    
private:   
    sf::Vector2f m_lastObjectPosition = { 0,0 };

    void addObjectsToVectors(LevelCommand& currLevel, const level& levelPart);
    void createEnemeis(LevelCommand& currLevel, float startX, float endX);
};
