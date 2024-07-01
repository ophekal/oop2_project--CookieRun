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
	void addToEnemiesVector(float  randomX, float randomY);


private:
	sf::RenderWindow& m_window;
	Player& m_player;
	InfoBar& m_infoBar;
	Button m_backButton;
	sf::RectangleShape m_background;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	std::vector<std::unique_ptr<AnimationObject>> m_animationObjects;
	std::vector<std::unique_ptr<Coin>> m_coins; //for fast search in the gift magnet
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
	sf::Sprite m_boomSpriteSheet;              // Sprite sheet for explosion animation
	Animation m_boomAnimation;                 // Animation for explosion

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
	//void handleExpolsion();
	//void performExplosionAnimation(const std::vector<sf::Vector2f>& explosionPositions);
	void drawGameObjects();
	void removeMarkedEnemies();
};