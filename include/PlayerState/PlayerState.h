
#pragma once
//#include "MovingObject/Player.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"

class Player;



class PlayerState 
{
public:
    PlayerState() = default; 
    virtual ~PlayerState() = default;
    virtual PlayerState* handleEvent(Player& player, KeyboardInput pressed)=0;
    virtual void update(Player& player, sf::Time deltaTime) = 0;

};