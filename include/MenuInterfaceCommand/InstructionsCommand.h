#pragma once
#include "MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Button.h"


class InstructionsCommand : public MenuInterfaceCommand
{
public:
    InstructionsCommand(sf::RenderWindow& window);
    void execute() override;

private:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	Button m_backToMenuButton;

	void render();
};