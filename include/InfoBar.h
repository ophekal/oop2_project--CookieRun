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

	std::vector<sf::Text> m_infoBar;
	std::vector<sf::RectangleShape> m_infoBarIcons;
	std::vector<std::pair<bool, sf::RectangleShape>> m_gifts; 	// Texture and visibility management for gifts

	void setInfoBarIcons();
	void setGiftTexture();
};