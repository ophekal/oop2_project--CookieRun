
#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include "Button.h"

class Player;

class ChoosePlayerCommand : public MenuInterfaceCommand
{
public:
	ChoosePlayerCommand(sf::RenderWindow& window, Player& player);
	void execute()override;

private:
	void setPlayerSprites();
	void render();

	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	Button m_backButtonToMenu;
	std::vector<sf::RectangleShape> m_players;	//holds the possible players
	Player& m_player;

};