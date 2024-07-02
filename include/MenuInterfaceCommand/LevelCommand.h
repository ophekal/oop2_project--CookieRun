#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Macros.h"
#include "Menu.h"
#include "Loader.h"
#include "MovingObject/Enemy.h"
#include "Animation.h"
#include "AnimationObject/Coin.h"


class Player;
class InfoBar;

class LevelCommand : public MenuInterfaceCommand
{
public:
	LevelCommand(sf::RenderWindow& window, Player& player, InfoBar& infoBar, const sf::Texture& background, bool levelOpen, int levelNumber);
	void execute()override;
	bool isOpen()const { return m_levelOpen; }
	void openLevel() { m_levelOpen = true; }
	int getLevelNumber()const;
	void setFlagPosition(sf::Vector2f position);
	void addToAnimationObjectVector(std::unique_ptr<AnimationObject> object);
	void addToStaticObjectVector(std::unique_ptr<StaticObject> object);
	void addToCoinsVector(std::unique_ptr<Coin> object);
	float getLastFloorXPosition(int cell) const;
	void addToEnemiesVector(float  startX, float endX);


private:
	sf::RenderWindow& m_window;
	Player& m_player;
	InfoBar& m_infoBar;
	Button m_backButton;
	sf::RectangleShape m_background;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	std::vector<std::unique_ptr<AnimationObject>> m_animationObjects;
	std::vector<std::unique_ptr<Coin>> m_coins; //for fast search when player has a magnet gift
	sf::Vector2f m_flagPosition;
	int m_levelNumber;
	bool m_levelOpen;
	bool m_levelOver = false;
	Loader m_loader;
	sf::Clock m_clock;
	sf::Time m_energyReductionElapsedTime = sf::Time::Zero; // Elapsed time for energy reduction
	bool m_isExploding = false;                // Flag to indicate if an explosion is in progress
	sf::Clock m_explosionClock;                // Clock to track the explosion duration
	std::vector<sf::Vector2f> m_explosionPositions; // Positions of explosions
	sf::Sprite m_boomSpriteSheet;
	Animation m_boomAnimation;                 


	void handleExplosion(sf::Time deltaTime);  // Method to handle explosion animation
	void handleExplosionStart();               // Method to start explosion handling
	void render();
	void handleEvent();
	void levelPollEvent();
	void moveAndDrawBackground();
	void printInformation();
	void updateAnimation(sf::Time deltaTime);
	void movePlayer(sf::Time deltaTime);
	void moveEnemies(sf::Time deltaTime);
	void checkAnimationObjectCollision();
	void checkStaticObjectCollision();
	void checkEnemyCollision();
	bool collide(GameObject& object1, GameObject& object2);
	void handleLevelExit();
	bool checkAndUpdateLevelStatus();
	void updatePlayerEnergy(sf::Time deltaTime);
	void printFeedback(const sf::Texture& feedback, GameSound sound);
	void checkIfNeedToExplode();
	sf::FloatRect getCurrentViewBounds();
	std::vector<sf::Vector2f> markEnemiesForExplosion(const sf::FloatRect& viewBounds);
	void drawGameObjects();
	void cleanVectors();
	template<typename T>
	void markOutOfViewObjectsForDeletion(std::vector<std::unique_ptr<T>>& objects, float playerPositionX, const sf::FloatRect& viewBounds);
	template<typename T>
	void removeMarkedObjects(std::vector<std::unique_ptr<T>>& objects);
};


//-------------------------------template fuctions---------------------------------------
//---------------------------------------------------------------------------------------
// Template function for marking objects for deletion

template<typename T>
void LevelCommand::markOutOfViewObjectsForDeletion(std::vector<std::unique_ptr<T>>& objects, float playerPositionX, const sf::FloatRect& viewBounds) 
{
	for (auto& object : objects)
	{
		float objectPositionX = object->getObject().getPosition().x;
		if (objectPositionX + WINDOW_WIDTH < playerPositionX && !viewBounds.contains(object->getObject().getPosition()))
		{
			object->markForDeletion();
		}
	}
}
//---------------------------------------------------------------------------------------
// Template function for removing objects for the vector
 
template <typename T>
void LevelCommand::removeMarkedObjects(std::vector<std::unique_ptr<T>>& objects)
{
	std::erase_if(objects, [](const std::unique_ptr<T>& object) {
		return object->isMarkedForDeletion();
		});
}
