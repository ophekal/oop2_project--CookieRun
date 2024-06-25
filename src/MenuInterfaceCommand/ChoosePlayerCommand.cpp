
#include "MenuInterfaceCommand/ChoosePlayerCommand.h"
#include "Macros.h"
#include "HandleResources.h"
#include <memory>
#include "MovingObject/Player.h"


//----------------------------------------------------------------------
ChoosePlayerCommand::ChoosePlayerCommand(sf::RenderWindow& window, Player& player)
	:m_window(window),
	 m_backButtonToMenu(*(HandleResources::instance().getButtonTexture(B_BACK)), BACK_X, BACK_Y, BACK_SIZE),
	 m_player(player)
{

	m_background.setTexture(*HandleResources::instance().getBackgroundTexture(CHOOSE_PLAYER));

	// Get the texture size
	sf::Vector2u textureSize = m_background.getTexture()->getSize();

	// Calculate scale factors
	float scaleX = static_cast<float>(WINDOW_WIDTH) / textureSize.x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / textureSize.y;

	// Apply the scale to the sprite
	m_background.setScale(scaleX, scaleY);

	setPlayerSprites();
	

}
//------------------------------------------------------------------------
void ChoosePlayerCommand::execute()
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
				if (m_backButtonToMenu.onClick(location))
				{
					return;
				}
				else if (m_players[CHOOSE_PLAYER_BRAVE].getGlobalBounds().contains(location))
				{
					m_player.setPlayer(PLAYER_BRAVE);
				}
				else if (m_players[CHOOSE_PLAYER_BRIGHT].getGlobalBounds().contains(location))
				{
					m_player.setPlayer(PLAYER_BRIGHT);
				}
			}
		}
	}

}
//---------------------------------------------------------------------------------
void ChoosePlayerCommand::setPlayerSprites()
{
	m_players.resize(2);

	// Set properties of existing elements
	m_players[CHOOSE_PLAYER_BRAVE].setSize(PLAYERS_SIZE);
	m_players[CHOOSE_PLAYER_BRAVE].setPosition(BRAVE_X, PLAYERS_Y);
	m_players[CHOOSE_PLAYER_BRAVE].setTexture(HandleResources::instance().getPlayerTexture(CHOOSE_PLAYER_BRAVE));

	m_players[CHOOSE_PLAYER_BRIGHT].setSize(PLAYERS_SIZE);
	m_players[CHOOSE_PLAYER_BRIGHT].setPosition(BRIGHT_X, PLAYERS_Y);
	m_players[CHOOSE_PLAYER_BRIGHT].setTexture(HandleResources::instance().getPlayerTexture(CHOOSE_PLAYER_BRIGHT));
}
//-----------------------------------------------------------------
void ChoosePlayerCommand::render()
{
	m_window.clear();
	m_window.draw(m_background);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	// loop for increasing the buttons when the mouse is ontop of them
	for (int i = 0; i < m_players.size(); i++)
	{
		sf::FloatRect bounds = m_players[i].getGlobalBounds();

		if (bounds.contains(mousePosF))
		{
			m_players[i].setScale(1.05f, 1.05f);
		}
		else
		{
			m_players[i].setScale(1.0f, 1.0f);
		}
	}
	// print the player options
	for (auto i = 0; i < m_players.size(); i++)
	{
		m_window.draw(m_players[i]);
	}

	m_window.draw(m_backButtonToMenu.getRectangleButton());
	m_window.display();
}