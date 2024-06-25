#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <memory>

class ExitCommand : public MenuInterfaceCommand
{
public:
	ExitCommand(sf::RenderWindow& window) : m_window(window) {};
	void execute() { m_window.close();}

private:
	sf::RenderWindow& m_window;
};