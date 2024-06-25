#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MovingObject/Player.h"
#include "HandleResources.h"



class Controller
{
public:
	Controller();
	void run();

private:
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	Menu m_menu;
	Player m_player;

};