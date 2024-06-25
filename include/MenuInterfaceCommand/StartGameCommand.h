
#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Menu.h"
#include "InfoBar.h"

class Player;

class StartGameCommand : public MenuInterfaceCommand
{
public:
	StartGameCommand(sf::RenderWindow& window,Player& player);
	void execute()override;

private:
	sf::RenderWindow& m_window;
	Player& m_player;
	sf::Sprite m_background;

	std::vector<option> m_levels;
	Button m_backToMenuButton;
	InfoBar m_infoBar;

	void render();
	void updateGameInfo(int currLevel);
	int getLevelMinCoins(int level)const ;
	void updateLevelButton(int levelIndex);


};