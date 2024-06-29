#include "MenuInterfaceCommand/LevelCommand.h"
#include "Macros.h"
#include "HandleResources.h"
#include "Collisions/HandleCollision.h"
#include <memory>
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"
#include "Factories/EnemyFactory.h"
#include "InfoBar.h"

//--------------------------------------------------------------------------------------------------------------------------------
LevelCommand::LevelCommand(sf::RenderWindow& window, Player& player, InfoBar& infoBar, const sf::Texture& background, bool levelOpen, int levelNumber)
	:m_window(window), m_player(player), m_infoBar(infoBar), m_levelOpen(levelOpen),
	m_backButton(*(HandleResources::instance().getButtonTexture(B_BACK)), BACK_X, BACK_Y, BACK_SIZE),
	m_levelNumber(levelNumber),
	m_boomSpriteSheet(*HandleResources::instance().getGiftTexture(G_BOOM)),
	m_boomAnimation(HandleResources::instance().getAnimationData(ANI_BOOM), m_boomSpriteSheet, sf::seconds(0.3f))
{
	m_background.setSize({ WINDOW_WIDTH ,WINDOW_HEIGHT });
	m_background.setTexture(&background);
	m_boomSpriteSheet.setOrigin(sf::Vector2f(m_boomSpriteSheet.getTextureRect().getSize() / 2));
}

//--------------------------------------------------------------------------------------------------------------------------------
//This function checks if the level is open and if so calls the function thats responsible of the event handeling in the level
void LevelCommand::execute()
{
	if (!m_levelOpen)
	{
		return;
	}

	//m_loader.updateMembers(m_levelNumber, m_animationObjects, m_staticObjects, m_enemies,m_coins, m_flagPosition);
	m_player.setPosition(PLAYER_INIT_POSITION.x, PLAYER_INIT_POSITION.y + 2);

	//in each execute we load diff level 
	m_loader.updateMembers(*this);

	handleEvent();

}

//--------------------------------------------------------------------------------------------------------------------------------
void LevelCommand::handleEvent()
{
	m_clock = sf::Clock();
	render();

	while (m_window.isOpen())
	{
		const auto deltaTime = m_clock.restart();

		updatePlayerEnergy(deltaTime);
		checkIfNeedToExplode();

		m_infoBar.updateInfoBar(m_player, m_levelNumber);

		//render();

		levelPollEvent();
		if (m_levelOver)
		{
			handleLevelExit();
			return;
		}

		//const auto deltaTime = clock.restart();
		updateAnimation(deltaTime);
		movePlayer(deltaTime);
		moveEnemies(deltaTime);

		handleExplosion(deltaTime); // Update and render explosion animation

		if (checkAndUpdateLevelStatus())
		{
			handleLevelExit();
			return;
		}

		render();
	}
}
//------------------------------------------------------------------------------------------------------

void LevelCommand::levelPollEvent()
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
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
			auto currView = m_window.getView();
			m_window.setView(m_window.getDefaultView());
			auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			if (m_backButton.onClick(location))
			{
				m_levelOver = true;
				return;
			}
			m_window.setView(currView);
			break;
		}
		case sf::Event::KeyPressed:
		{
			m_player.keyPressed(event.key);
			break;
		}
		case sf::Event::KeyReleased:
		{
			m_player.keyReleased(event.key);
			break;
		}
		default:
			break;
		}
	}

}

//--------------------------------------------------------------------------------------------------------------------------------
void LevelCommand::render()
{
	m_window.clear();

	moveAndDrawBackground();

	// change view
	auto currView = m_window.getView();
	auto center = currView.getCenter();
	center = sf::Vector2f(m_player.getPosition().x + 400, center.y);

	m_window.setView(sf::View(center, currView.getSize()));

	drawGameObjects();

	if (m_isExploding) 
	{
		handleExplosion(sf::seconds(0)); // Render explosion if active
	}

	m_window.display();
}
//-----------------------------------------------------------------------------
void LevelCommand::updatePlayerEnergy(sf::Time deltaTime)
{
	// Update the cumulative elapsed time for energy reduction
	m_energyReductionElapsedTime += deltaTime;

	// Check if 2 seconds have passed for energy reduction
	if (m_energyReductionElapsedTime >= sf::seconds(2.0f))
	{
		// Reduce player's energy
		m_player.setEnergy(m_player.getEnergy() - 1);
		// Reset the elapsed time, accounting for any extra time
		m_energyReductionElapsedTime -= sf::seconds(2.0f);
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
//Printing the information while making sure we save the view of the window while printing
void LevelCommand::printInformation()
{
	auto currView = m_window.getView();
	m_window.setView(m_window.getDefaultView());

	m_window.draw(m_backButton.getRectangleButton());
	m_infoBar.draw(m_window);

	m_window.setView(currView);
}

//------------------------------------------------------------------------------
void LevelCommand::movePlayer(sf::Time deltaTime)
{
	m_player.movement(deltaTime);
	checkAnimationObjectCollision();
	checkStaticObjectCollision();
	checkEnemyCollision();
}

//----------------------------------------------------------------------------------------
void LevelCommand::checkAnimationObjectCollision()
{
	//checking if collided with animation object
	for (auto& animationObject : m_animationObjects)
	{
		if (collide(m_player, *animationObject))
		{
			HandleCollision::instance().processCollision(m_player, *animationObject);
		}
	}
	//checking if collided with animation object
	for (auto& coin : m_coins)
	{
		if (collide(m_player, *coin))
		{
			HandleCollision::instance().processCollision(m_player, *coin);
		}
	}

	std::erase_if(m_animationObjects, [](const auto& animationObject) {
		return animationObject->isMarkedForDeletion();
		});
	std::erase_if(m_coins, [](const auto& coin) {
		return coin->isMarkedForDeletion();
		});
}

//----------------------------------------------------------------------------------------
void LevelCommand::checkStaticObjectCollision()
{
	//checking if collided with animation object
	for (auto& staticObject : m_staticObjects)
	{
		if (collide(m_player, *staticObject))
		{
			HandleCollision::instance().processCollision(m_player, *staticObject);
		}
	}

	std::erase_if(m_staticObjects, [](const auto& staticObject) {
		return staticObject->isMarkedForDeletion();
		});

}
//---------------------------------------------------------------------------------------
// This function checks 
void LevelCommand::checkEnemyCollision()
{
	for (auto& enemy : m_enemies)
	{
		if (collide(m_player, *enemy))
		{
			HandleCollision::instance().processCollision(m_player, *enemy);
		}
	}
}

//----------------------------------------------------------------------------------------
bool LevelCommand::collide(GameObject& object1, GameObject& object2)
{
	if (&object1 == &object2)
	{
		return false;
	}

	const int OVERLAP = 10;
	sf::FloatRect overlap;

	object1.getGlobalBounds().intersects(object2.getGlobalBounds(), overlap);

	if (overlap.height > OVERLAP && overlap.width > OVERLAP)
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------------------
void LevelCommand::moveEnemies(sf::Time deltaTime)
{
	for (auto& enemyObject : m_enemies)
	{
		enemyObject->moveEnemy(m_player.getPosition(), m_staticObjects, deltaTime);
	}
}
//--------------------------------------------------------------------------
void LevelCommand::updateAnimation(sf::Time deltaTime)
{
	for (auto& animationObject : m_animationObjects)
	{
		animationObject->updateAnimation(deltaTime);
	}
	for (auto& coinObject : m_coins)
	{
		coinObject->updateAnimation(deltaTime);
	}
}

//--------------------------------------------------------------------------
void LevelCommand::moveAndDrawBackground()
{
	float startbackgroundX = m_background.getGlobalBounds().left - 2 * WINDOW_WIDTH;
	float endbackgroundX = m_window.getView().getCenter().x + WINDOW_WIDTH;


	for (; startbackgroundX < endbackgroundX; startbackgroundX += m_background.getSize().x)
	{
		m_background.setPosition(startbackgroundX, m_background.getPosition().y);
		m_window.draw(m_background);
	}

}
//----------------------------------------------------------------------------
void LevelCommand::handleLevelExit()
{
	m_staticObjects.clear();
	m_animationObjects.clear();
	m_coins.clear();
	m_enemies.clear();
	m_player.handleExitFromLevel();
	m_levelOver = false; //for the next time we enter
	m_levelOpen = true;
	m_window.setView(m_window.getDefaultView());

	// set backgroung to start again
	m_background.setPosition(0, 0);

	printInformation(); // Redraw any UI elements immediatesly
	m_window.display(); // Ensure everything is displayed
}

//-------------------------------------------------------------------------------
bool LevelCommand::checkAndUpdateLevelStatus()
{
	if (m_player.isDead()) //to the next level
	{
		printFeedback(*HandleResources::instance().getFeedbackTexture(F_TRYAGAIN));
		return true;
	}
	else if( m_player.getPosition().x >= m_flagPosition.x)   //the game over with success if we arrive to the flag section
	{
		printFeedback(*HandleResources::instance().getFeedbackTexture(F_GOODJOB));
		return true;
	}

	return false;

}
//----------------------------------------------------------------------------------------
void LevelCommand::printFeedback(const sf::Texture& feedback /*, GameSound sound */ )
{
	sf::sleep(sf::seconds(1));

	sf::Sprite sprite(feedback);

	// Get the current view
	auto currentView = m_window.getView();
	auto viewCenter = currentView.getCenter();
	auto viewSize = currentView.getSize();

	// Calculate the position to center the sprite within the current view
	float spriteX = viewCenter.x - sprite.getLocalBounds().width / 2.0f;
	float spriteY = viewCenter.y - sprite.getLocalBounds().height / 2.0f;

	sprite.setPosition(spriteX, spriteY);

	// Clear the window
	m_window.clear();

	// Redraw the background
	moveAndDrawBackground();

	// Draw the feedback sprite centered in the current view
	m_window.draw(sprite);
	m_window.display();

	sf::sleep(sf::seconds(1));
}

////----------------------------------------------------------------------------------------
//void LevelCommand::checkIfNeedToExplode()
//{
//	if (m_player.getKeyPressed() == K_ENTER && m_player.getWeapons()>0)
//	{
//		handleExpolsion();
//		m_player.setWeapon(m_player.getWeapons() - 1);
//		m_clock.restart();
//	}
//}
//----------------------------------------------------------------------------------
void LevelCommand::handleExplosion(sf::Time deltaTime)
{
	if (!m_isExploding) 
	{
		return; // If not exploding, do nothing
	}

	// Update the explosion animation
	m_boomAnimation.update(deltaTime);

	// Draw explosion animation at the stored positions
	for (const auto& position : m_explosionPositions)
	{
		m_boomSpriteSheet.setPosition(position);
		m_window.draw(m_boomSpriteSheet);
	}

	// Check if the explosion duration has elapsed
	if (m_explosionClock.getElapsedTime() >= sf::seconds(1.0f))
	{
		m_isExploding = false;
		removeMarkedEnemies(); // Remove enemies marked for deletion after the explosion
	}
}
//----------------------------------------------------------------------------------------
// Helper function to get the current view bounds
sf::FloatRect LevelCommand::getCurrentViewBounds()
{
	auto currentView = m_window.getView();
	auto viewCenter = currentView.getCenter();
	auto viewSize = currentView.getSize();
	return sf::FloatRect(viewCenter.x - viewSize.x / 2, viewCenter.y - viewSize.y / 2, viewSize.x, viewSize.y);
}

//----------------------------------------------------------------------------------------
// This function marks the enemies within view bounds as ones needed to be deleted,  
// and returns their positions

std::vector<sf::Vector2f> LevelCommand::markEnemiesForExplosion(const sf::FloatRect& viewBounds)
{
	std::vector<sf::Vector2f> explosionPositions;
	for (auto& enemy : m_enemies)
	{
		if (viewBounds.intersects(enemy->getGlobalBounds()))
		{
			explosionPositions.push_back(enemy->getPosition());
			enemy->markForDeletion();
		}
	}
	return explosionPositions;
}

////----------------------------------------------------------------------------------------
//// Helper function to perform the explosion animation
//void LevelCommand::performExplosionAnimation(const std::vector<sf::Vector2f>& explosionPositions)
//{
//	sf::Sprite boomSpriteSheet(*HandleResources::instance().getGiftTexture(G_BOOM));
//	Animation boomAnimation(HandleResources::instance().getAnimationData(ANI_BOOM), boomSpriteSheet, sf::seconds(0.3f));
//
//	boomSpriteSheet.setOrigin(sf::Vector2f(boomSpriteSheet.getTextureRect().getSize() / 2));
//
//	sf::Clock boomClock;
//	sf::Time boomDuration = sf::seconds(1.0f); // Duration for explosion animation
//	sf::Time boomElapsedTime = sf::Time::Zero;
//
//	while (boomElapsedTime < boomDuration)
//	{
//		auto deltaTime = boomClock.restart();
//		boomElapsedTime += deltaTime;
//		boomAnimation.update(deltaTime);
//
//		// Clear the window
//		m_window.clear();
//
//		// Redraw the background
//		moveAndDrawBackground();
//
//		// Draw static and animated objects
//		drawGameObjects();
//
//		// Draw explosion animation at the stored positions
//		for (const auto& position : explosionPositions)
//		{
//			boomSpriteSheet.setPosition(position);
//			m_window.draw(boomSpriteSheet);
//		}
//
//		m_window.display();
//	}
//}

//--------------------------------------------------------------------------
// Helper function to draw game objects excluding marked enemies
void LevelCommand::drawGameObjects()
{
	for (const auto& staticObject : m_staticObjects) {
		staticObject->draw(m_window);
	}

	for (const auto& animatedObject : m_animationObjects) {
		animatedObject->draw(m_window);
	}
	for (const auto& coin : m_coins)
	{
		coin->draw(m_window);
	}

	printInformation();
	m_player.draw(m_window);

	for (const auto& enemy : m_enemies)
	{
		if (!enemy->isMarkedForDeletion())
		{
			enemy->draw(m_window);
		}
	}
}

//------------------------------------------------------------------------------
// Helper function to remove marked enemies from the game
void LevelCommand::removeMarkedEnemies()
{
	std::erase_if(m_enemies, [](const auto& enemy) {
		return enemy->isMarkedForDeletion();
		});
}
//------------------------------------------------------------------------------
void LevelCommand::checkIfNeedToExplode()
{
	if (m_player.getKeyPressed() == K_ENTER && m_player.getWeapons() > 0)
	{
		handleExplosionStart(); // Start explosion handling
		m_player.setWeapon(m_player.getWeapons() - 1);
		m_player.resetKeyPress();
	}
}

//-------------------------------------------------------------------------------
void LevelCommand::handleExplosionStart()
{
	// Get the current view bounds
	sf::FloatRect viewBounds = getCurrentViewBounds();

	// Identify and mark enemies within view for deletion
	m_explosionPositions = markEnemiesForExplosion(viewBounds);

	m_isExploding = true; // Set explosion flag
	m_explosionClock.restart(); // Start explosion timer
}

//-------------------------------------------------------------------------------
int LevelCommand::getLevelNumber() const
{
	return m_levelNumber;
}

//-------------------------------------------------------------------------------
void LevelCommand::setFlagPosition(const sf::Vector2f& position)
{
	m_flagPosition = position;
	m_flagPosition.x += 6000;
}

//-------------------------------------------------------------------------------
void LevelCommand::addToAnimationObjectVector(std::unique_ptr<AnimationObject> object)
{
	m_animationObjects.emplace_back(std::move(object));
}

//-------------------------------------------------------------------------------
void LevelCommand::addToStaticObjectVector(std::unique_ptr<StaticObject> object)
{
	m_staticObjects.emplace_back(std::move(object));
}

//-------------------------------------------------------------------------------
void LevelCommand::addToCoinsVector(std::unique_ptr<Coin> object)
{
	m_coins.emplace_back(std::move(object));
}

//-------------------------------------------------------------------------------
void LevelCommand::addToEnemiesVector(float  randomX, float randomY)
{
	m_enemies.emplace_back(EnemyFactory::createEnemy({ randomX, randomY }, m_levelNumber));
}

//-------------------------------------------------------------------------------
// This function gets the x position of the last floor in the level

float LevelCommand::getLastFloorXPosition(int cell) const
{
	return (m_staticObjects[cell]->getObject().getPosition().x);
}