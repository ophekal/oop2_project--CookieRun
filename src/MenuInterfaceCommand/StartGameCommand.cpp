
#include "MenuInterfaceCommand/StartGameCommand.h"
#include "Macros.h"
#include "Button.h"
#include "MenuInterfaceCommand/LevelCommand.h"
#include "HandleResources.h"
#include "MenuInterfaceCommand/BackCommand.h"
#include "MovingObject/Player.h"
#include <string>
#include <fstream>
#include <sstream>

//--------------------------------------------------------------------------------------------
StartGameCommand::StartGameCommand(sf::RenderWindow& window, Player& player)
	:m_window(window), m_player(player), m_backToMenuButton(*(HandleResources::instance().getButtonTexture(B_BACK)), BACK_X, BACK_Y, BACK_SIZE)
{
	m_background.setTexture(*HandleResources::instance().getBackgroundTexture(STARTGAME));

	// Get the texture size
	sf::Vector2u textureSize = m_background.getTexture()->getSize();

	// Calculate scale factors
	float scaleX = static_cast<float>(WINDOW_WIDTH) / textureSize.x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / textureSize.y;

	// Apply the scale to the sprite
	m_background.setScale(scaleX, scaleY);

	createLevelOptionsVector();
	createCoinsForLevelsVector();
}

//--------------------------------------------------------------------------------------------
// This function reads from a playlist file the number of levels and creates buttons per level
// accordingly

void StartGameCommand::createLevelOptionsVector()
{
	std::vector<std::string> levelsNames;

	// open streams for reading from level parts playlist
	auto line = std::string();
	auto file = std::ifstream("LevelPlaylist.txt");
	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open LevelPlaylist.txt");
	}

	// reading the number of level from the playlist
	while (std::getline(file, line))
	{
		levelsNames.emplace_back(line);
	}

	createLevelOptions(levelsNames);
}

//--------------------------------------------------------------------------------------------
// This function is responsible of creating the buttons for the different levels and enters
// them into the vector

void StartGameCommand::createLevelOptions(const std::vector<std::string>& levelsNames)
{
	const sf::Font& font = *HandleResources::instance().getFont();
	float verticalSpacing = 100.0f;  // Define the space between buttons in pixels

	// Initialize the m_levels with sf::Text objects
	for (size_t i = 0; i < levelsNames.size(); ++i)
	{
		// Create the level text
		sf::Text levelText;
		levelText.setFont(font);
		levelText.setCharacterSize(60);
		levelText.setFillColor(sf::Color::Black);

		// Set the position with added spacing
		levelText.setPosition(LEVEL_X + 50, LEVEL_Y + i * (BUTTON_SIZE.y + verticalSpacing) + 15);
		levelText.setString(levelsNames[i]);

		// Create the level button
		Buttons buttonTexture = (i == 0) ? B_LEVEL_ON : B_LEVEL_OFF;

		// Set the position with added spacing
		Button levelButton(*HandleResources::instance().getButtonTexture(buttonTexture), LEVEL_Y + i * (BUTTON_SIZE.y + verticalSpacing), LEVEL_X, BUTTON_SIZE);

		// Create the command for the level
		auto levelCommand = std::make_unique<LevelCommand>(m_window, m_player, m_infoBar, *HandleResources::instance().getBackgroundTexture(Background(L1_BACKGROUND + i)), (i == 0), i + 1);

		// Emplace the constructed pair into the vector
		m_levels.emplace_back(std::make_pair(std::make_pair(levelText, levelButton), std::move(levelCommand)));
	}
}

//--------------------------------------------------------------------------------------------
void StartGameCommand::createCoinsForLevelsVector()
{
	m_minCoinsForLevel.emplace_back(L1_COIN_MIN);
	m_minCoinsForLevel.emplace_back(L2_COIN_MIN);
	m_minCoinsForLevel.emplace_back(L3_COIN_MIN);
}
//--------------------------------------------------------------------------------------------
// This function is responsible of handeling the poll events in the startGameCommand window

void StartGameCommand::execute()
{
	while (m_window.isOpen())
	{
		render();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					m_window.close();
					return;
				}
				case sf::Event::MouseButtonPressed:
				{
					auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

					// iterate through the level vector and check if the mouse click was on one of the buttons
					for (auto index = 0; index < m_levels.size(); index++)
					{
						if (m_levels[index].first.second.onClick(location))
						{
							m_levels[index].second->execute();
							updateGameInfo(index);
						}
					}
					if (m_backToMenuButton.onClick(location))
					{
						return;
					}
				}
			}

		}
	}
}

//--------------------------------------------------------------------------------------------
void StartGameCommand::render()
{
	m_window.clear();
	m_window.draw(m_background);

	// print the buttons
	for (const auto& button : m_levels)
	{
		m_window.draw(button.first.second.getRectangleButton());
		m_window.draw(button.first.first);
	}

	m_backToMenuButton.printButton(m_window);
	m_window.display();
}

//--------------------------------------------------------------------------------------------
// This function checks if the next level can be opened and updates accordingly the buttons
// texture, and opens the level

void StartGameCommand::updateGameInfo(int levelIndex)
{
	if (levelIndex < m_levels.size() - 1)
	{
		int nextLevelIndex = levelIndex + 1;
		LevelCommand* nextLevelPtr = dynamic_cast<LevelCommand*>(m_levels[nextLevelIndex].second.get());
		if (nextLevelPtr != nullptr)
		{
			int minCoinsToOpenLevel = getLevelMinCoins(nextLevelIndex + 1);
			if (!(nextLevelPtr->isOpen()) && m_player.getCoins() >= minCoinsToOpenLevel)
			{
				m_player.setCoins(m_player.getCoins() - minCoinsToOpenLevel);
				updateLevelButton(nextLevelIndex + 1);
				nextLevelPtr->openLevel();
			}
		}
	}
}

//--------------------------------------------------------------------------------------------
int StartGameCommand::getLevelMinCoins(int level)const
{
	return m_minCoinsForLevel[level - 1];
}

//--------------------------------------------------------------------------------------------
// This function updates the level button in the vector of the level

void StartGameCommand::updateLevelButton(int levelNumber)
{
	m_levels[levelNumber - 1].first.second.setButtonTexture(HandleResources::instance().getButtonTexture(B_LEVEL_ON));

}



