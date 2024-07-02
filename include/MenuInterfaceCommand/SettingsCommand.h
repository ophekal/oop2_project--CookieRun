#pragma once
#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Button.h"


typedef std::pair<std::unique_ptr<Button>, std::unique_ptr<MenuInterfaceCommand>> optionInSetting;


class SettingsCommand : public MenuInterfaceCommand
{
public:
	SettingsCommand(sf::RenderWindow& window);
	void execute() override;

private:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	Button m_backToMenuButton;
	std::vector<optionInSetting> m_buttons;	//holds the music and sound  buttons

	void render();
	void updateButtons();
	void handleButtonClick(const sf::Vector2f& location);
};