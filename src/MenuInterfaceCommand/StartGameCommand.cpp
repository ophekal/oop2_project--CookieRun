
#include "MenuInterfaceCommand/StartGameCommand.h"
#include "Macros.h"
#include "Button.h"
#include "MenuInterfaceCommand/LevelCommand.h"
#include "HandleResources.h"
#include "MenuInterfaceCommand/BackCommand.h"
#include "MovingObject/Player.h"

//----------------------------------------------------------------------------
StartGameCommand::StartGameCommand(sf::RenderWindow& window,Player& player)
	:m_window(window), m_player(player), m_backToMenuButton(*(HandleResources::instance().getButtonTexture(B_BACK)), BACK_X, BACK_Y, BACK_SIZE)//, m_menu(window, STARTGAME)
{
	m_levels.emplace_back(Button(*HandleResources::instance().getButtonTexture(B_LEVEL1_ON), LEVEL1_X, LEVEL_Y, BUTTON_SIZE), std::make_unique<LevelCommand>(m_window, m_player,m_infoBar, *HandleResources::instance().getLevel1Texture(L1_BACKGROUND), true,1));
	m_levels.emplace_back(Button(*HandleResources::instance().getButtonTexture(B_LEVEL2_OFF), LEVEL2_X, LEVEL_Y, BUTTON_SIZE), std::make_unique<LevelCommand>(m_window, m_player, m_infoBar, *HandleResources::instance().getLevel2Texture(L2_BACKGROUND),false,2));
	m_levels.emplace_back(Button(*HandleResources::instance().getButtonTexture(B_LEVEL3_OFF), LEVEL3_X, LEVEL_Y, BUTTON_SIZE), std::make_unique<LevelCommand>(m_window, m_player, m_infoBar, *HandleResources::instance().getLevel3Texture(L3_BACKGROUND), false,3));
	
	m_background.setTexture(*HandleResources::instance().getBackgroundTexture(STARTGAME));

	// Get the texture size
	sf::Vector2u textureSize = m_background.getTexture()->getSize();

	// Calculate scale factors
	float scaleX = static_cast<float>(WINDOW_WIDTH) / textureSize.x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / textureSize.y;

	// Apply the scale to the sprite
	m_background.setScale(scaleX, scaleY);
}

//-----------------------------------------------------------------------------------------
void StartGameCommand::execute()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			render();

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
				for (auto index =0 ; index < m_levels.size(); index++)
				{
					if (m_levels[index].first.onClick(location))
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
		render();
	}


}
//------------------------------------------------------------------------------
void StartGameCommand::render()
{
	m_window.clear();
	m_window.draw(m_background);

	// print the buttons
	for (const auto& button : m_levels)
	{
		m_window.draw(button.first.getRectangleButton());
	}

	m_backToMenuButton.printButton(m_window);

	m_window.display();
}
//-------------------------------------------------------------------------------

void StartGameCommand::updateGameInfo(int levelIndex)
{
	//check if the next level need to be open
	if (levelIndex < m_levels.size()-1)
	{
		int nextLevelIndex = levelIndex + 1;
		LevelCommand* nextLevelPtr = dynamic_cast<LevelCommand*>(m_levels[nextLevelIndex].second.get());
		if (nextLevelPtr != nullptr)
		{
			int minCoinsToOpenLevel = getLevelMinCoins(nextLevelIndex+1);
			if (!(nextLevelPtr->isOpen()) && m_player.getCoins() >= minCoinsToOpenLevel)
			{
				m_player.setCoins(m_player.getCoins() - minCoinsToOpenLevel);
				updateLevelButton(nextLevelIndex+1);
				nextLevelPtr->openLevel();
			}
		}

	}
}

//------------------------------------------------------------------------------

int StartGameCommand::getLevelMinCoins(int level)const
{
	switch (level)
	{
	case 1:
		return L1_COIN_MIN;
	case 2:
		return L2_COIN_MIN;
	case 3:
		return L3_COIN_MIN;
	default:
		break;
	}

	return L1_COIN_MIN;
}
//----------------------------------------------------------------------------
void StartGameCommand::updateLevelButton(int levelNumber)
{
	Buttons button = B_LEVEL1_ON;
	switch (levelNumber)
	{
	case 2:
		button = B_LEVEL2_ON;
		break;
	case 3:
		button = B_LEVEL3_ON;
		break;
	}

	// update the level button in the vector of the level
	m_levels[levelNumber-1].first.setButtonTexture(HandleResources::instance().getButtonTexture(button));

}
//-----------------------------------------------------------------------------




