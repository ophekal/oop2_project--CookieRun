#pragma once
#include <memory>
#include <vector>
#include "Macros.h"
#include "Button.h"
#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>


typedef std::pair<Button, std::unique_ptr<MenuInterfaceCommand>> option;


class Menu
{
public:
	Menu(sf::RenderWindow& window);
	~Menu() = default;
	void addToOptions(const Button & button, std::unique_ptr<MenuInterfaceCommand> option);
	void activate();

private:
	sf::Sprite m_background;
	sf::RenderWindow& m_window;
	std::vector<option> m_options;

	void render();
};