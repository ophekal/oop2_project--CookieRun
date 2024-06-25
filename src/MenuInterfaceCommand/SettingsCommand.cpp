#include <SFML/Graphics.hpp>
#include "MenuInterfaceCommand/SettingsCommand.h"
#include "HandleResources.h"
#include "MenuInterfaceCommand/MusicCommand.h"
#include "MenuInterfaceCommand/SoundCommand.h"
#include "Macros.h"
#include "Button.h"


//--------------------------------------------------------------------------------------------
SettingsCommand::SettingsCommand(sf::RenderWindow& window)
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

	updateButtons();
}

//--------------------------------------------------------------------------------------------
void SettingsCommand::updateButtons()
{
	//Button music(*HandleResources::instance().getButtonTexture(B_MUSIC_ON), MUSIC_Y, SOUND_X, MUSIC_SIZE);
	//Button sound(*HandleResources::instance().getButtonTexture(B_SOUND_ON), SOUND_Y, SOUND_X, MUSIC_SIZE);

	//m_buttons.emplace_back(option(music, std::make_unique<MusicCommand>(music)));
	//m_buttons.emplace_back(option(sound, std::make_unique<SoundCommand>(sound)));
	
	 // Allocate Button objects dynamically using std::make_unique
	std::unique_ptr<Button> musicButton = std::make_unique<Button>(*HandleResources::instance().getButtonTexture(B_MUSIC_ON), MUSIC_Y, SOUND_X, MUSIC_SIZE);
	std::unique_ptr<Button> soundButton = std::make_unique<Button>(*HandleResources::instance().getButtonTexture(B_SOUND_ON), SOUND_Y, SOUND_X, MUSIC_SIZE);

	// Create corresponding commands with references to the Button objects
	std::unique_ptr<MenuInterfaceCommand> musicCommand = std::make_unique<MusicCommand>(*musicButton);
	std::unique_ptr<MenuInterfaceCommand> soundCommand = std::make_unique<SoundCommand>(*soundButton);

	// Add these unique_ptrs to Button objects and their associated commands to m_buttons vector
	m_buttons.emplace_back(std::move(musicButton), std::move(musicCommand));
	m_buttons.emplace_back(std::move(soundButton), std::move(soundCommand));

}

//--------------------------------------------------------------------------------------------
void SettingsCommand::execute()
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
				else if (m_buttons[0].first->onClick(location))	//music button
				{
					m_buttons[0].second->execute();
				}
				else if (m_buttons[1].first->onClick(location))	//sound button
				{
					m_buttons[1].second->execute();
				}
			}
		}
	}
}

//------------------------------------------------------------------------------
void SettingsCommand::render()
{
	m_window.clear();
	m_window.draw(m_background);

	// print the button
	m_window.draw(m_backToMenuButton.getRectangleButton());
	
	//draw the music buttons
	for (auto i = 0; i < m_buttons.size(); i++)
	{
		m_window.draw(m_buttons[i].first->getRectangleButton());
	}

	m_window.display();
}
