
#include <vector>
#include <string.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <filesystem>
#include "Menu.h"
#include "Macros.h"
#include "Controller.h"
#include "MenuInterfaceCommand/BackCommand.h"
#include "HandleResources.h"


//----------------------------------------------------------------------------------------------------------------------
Menu::Menu(sf::RenderWindow& window)
	: m_window(window)
{
	m_background.setTexture(*HandleResources::instance().getBackgroundTexture(MENU));
	// Get the texture size
	sf::Vector2u textureSize = m_background.getTexture()->getSize();

	// Calculate scale factors
	float scaleX = static_cast<float>(WINDOW_WIDTH) / textureSize.x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / textureSize.y;

	// Apply the scale to the sprite
	m_background.setScale(scaleX, scaleY);
}
//---------------------------------------------------------------------------------------------------------------------
void Menu::addToOptions(const Button& button, std::unique_ptr<MenuInterfaceCommand> options)
{
	m_options.emplace_back(option(button, std::move(options)));
}
//------------------------------------------------------------------------------------------------------------------

void Menu::activate()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			render();
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				return;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				// iterate through the options vector and check if the mouse click was on one of the buttons
				for (auto& commandOption  : m_options)
				{
					if (commandOption.first.onClick(location))
					{
						commandOption.second->execute();

						//BackCommand* command = dynamic_cast<BackCommand*>(commandOption.second.get());
						//if (command != nullptr)
						//{
						//	return;
						//}
					}
				}
			}
		}

	}


}
//------------------------------------------------------------------------------
void Menu::render()
{
	m_window.clear();
	m_window.draw(m_background);

	// print the buttons
	for (const auto& button : m_options)
	{
		m_window.draw(button.first.getRectangleButton());
	}

	m_window.display();
}

////----------------------------------------------------------------------------------------------------------------------
//void Menu::updateButton()
//{
//	m_buttons.push_back(std::make_unique<ChoosePlayerButton>(*HandleResources::instance().getButtonTexture(B_PLAYER), START_X, CHOOSEPLAYER_Y, BUTTON_SIZE, m_choosePlayer));
//	m_buttons.push_back(std::make_unique<ExitButton>(*HandleResources::instance().getButtonTexture(B_EXIT), EXIT_X, EXIT_Y, EXIT_SIZE,m_window));
//	m_buttons.push_back(std::make_unique<SettingsButton>(*HandleResources::instance().getButtonTexture(B_SETTINGS), START_X, SETTINGS_Y, BUTTON_SIZE, m_settings));
//	m_buttons.push_back(std::make_unique<InstructionsButton>(*HandleResources::instance().getButtonTexture(B_INSTRUCTIONS), START_X, INSTRUCTIONS_Y, BUTTON_SIZE, m_instruction));
//	m_buttons.push_back(std::make_unique<StartGameButton>(*HandleResources::instance().getButtonTexture(B_START), START_X, START_Y, BUTTON_SIZE, m_startGame));
//}

////--------------------------------------------------------------------------------------------
//GameState* Menu::handleEvent() 
//{
//	sf::Event event;
//	while (m_window.pollEvent(event)) 
//	{
//		render();
//		if (event.type == sf::Event::Closed) 
//		{
//			m_window.close();
//			return nullptr;
//		}
//
//		if (event.type == sf::Event::MouseButtonPressed) 
//		{
//			auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
//
//			// iterate through the buttons vector and check if the mouse click was on one of them
//			for (auto& button : m_buttons) 
//			{
//				if (button->getRectangleButton().getGlobalBounds().contains(location)) {
//					return button->onClick();
//				}
//			}
//		}
//	}
//	return nullptr;
//}






////--------------------------------------------------------------------------------------------
//void Menu::print(const sf::Sprite& background)
//{
//	m_window.clear();
//	m_window.draw(background);
//	printButtons();
//	m_window.display();
//}


//auto location = m_window.mapPixelToCoords({ event.x,event.y  });
//
//	if (m_buttons[M_PLAYER].getSpriteButton().getGlobalBounds().contains(location))
//	{
//		return &(m_Player);	// calls on controller and starts the game
//	}
//	else if (m_buttons[M_EXIT].getSpriteButton().getGlobalBounds().contains(location))
//	{
//		m_window.close();
//		return;
//	}
//	else if (m_buttons[M_SETTINGS].getSpriteButton().getGlobalBounds().contains(location))
//	{
//		return &(m_settings);
//	}
//	else if (m_buttons[M_RULES].getSpriteButton().getGlobalBounds().contains(location))
//	{
//		return &(m_instruction);	// creates a window that explains the game
//	}
//	else if (m_buttons[M_START].getSpriteButton().getGlobalBounds().contains(location))
//	{
//		return &(m_levels);
//	}
//	return nullptr;
//
//}