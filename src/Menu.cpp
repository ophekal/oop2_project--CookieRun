
#include <vector>
#include <string.h>
#include <SFML/Graphics.hpp>
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
		render();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			
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
