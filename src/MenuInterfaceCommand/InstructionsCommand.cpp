#include <SFML/Graphics.hpp>
#include "MenuInterfaceCommand/InstructionsCommand.h"
#include "HandleResources.h"
#include "Macros.h"

//--------------------------------------------------------------------------------------------
InstructionsCommand::InstructionsCommand (sf::RenderWindow& window)
	: m_window(window), m_backToMenuButton(*(HandleResources::instance().getButtonTexture(B_BACK)), BACK_X, BACK_Y, BACK_SIZE)
{
	m_background.setTexture(*HandleResources::instance().getBackgroundTexture(INSTRUCTIONS));

	// Get the texture size
	sf::Vector2u textureSize = m_background.getTexture()->getSize();

	// Calculate scale factors
	float scaleX = static_cast<float>(WINDOW_WIDTH) / textureSize.x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / textureSize.y;

	// Apply the scale to the sprite
	m_background.setScale(scaleX, scaleY);
}


//--------------------------------------------------------------------------------------------
void InstructionsCommand::execute()
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
				if (m_backToMenuButton.onClick(location))
				{
					return;
				}

			}
		}
	}
}

//------------------------------------------------------------------------------
void InstructionsCommand::render()
{
	m_window.clear();
	m_window.draw(m_background);

	// print the button
	m_window.draw(m_backToMenuButton.getRectangleButton());

	m_window.display();
}
