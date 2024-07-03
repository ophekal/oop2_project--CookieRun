
#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Menu.h"
#include "InfoBar.h"



typedef std::pair<sf::Text, Button> levelbutton;
typedef std::pair<levelbutton, std::unique_ptr<MenuInterfaceCommand>> LevelOption;

class Player;

class StartGameCommand : public MenuInterfaceCommand
{
public:
	StartGameCommand(sf::RenderWindow& window, Player& player);
	void execute()override;

private:
	sf::RenderWindow& m_window;
	Player& m_player;
	sf::Sprite m_background;
	std::vector<LevelOption> m_levels;
	std::vector<int> m_minCoinsForLevel;
	Button m_backToMenuButton;
	InfoBar m_infoBar;

	void render();
	void updateGameInfo(int currLevel);
	bool checkIfPassedLevel(int levelIndex);
	int getLevelMinCoins(int level)const;
	void updateLevelButton(int levelIndex);
	void createLevelOptionsVector();
	void createLevelOptions(const std::vector<std::string>& levelsNames);
	void createCoinsForLevelsVector();
};