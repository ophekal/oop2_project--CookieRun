#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InfoItem.h"
#include <string.h>
#include "MovingObject/Player.h"

class MovingObjects;

class InfoBar
{
public:
	InfoBar();
	void draw(sf::RenderWindow& window);
	void updateInfoBar(const Player& player, int levelNumber);

private:
	std::string m_numOfCoins;
    std::string m_levelNumber;
	std::string m_playerEnergy;
	std::string m_numOfWeapons;
	std::vector<sf::Text> m_infoBar;
	sf::RectangleShape m_jelly;
	sf::RectangleShape m_coin;
	sf::RectangleShape m_weapon;
};