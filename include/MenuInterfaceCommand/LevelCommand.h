
#pragma once

#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Macros.h"
#include "Menu.h"
#include "Loader.h"
#include "MovingObject/Enemy.h"


class Player;
class InfoBar;

class LevelCommand : public MenuInterfaceCommand
{
public:
	LevelCommand(sf::RenderWindow& window,Player& player,InfoBar& infoBar, const sf::Texture& background, bool levelOpen,int levelNumber);
	void execute()override;
	bool isOpen()const { return m_levelOpen; }
	void openLevel() { m_levelOpen = true; }
	void addEnemies();


private:
	sf::RenderWindow& m_window;
	Player& m_player;	
	InfoBar& m_infoBar;
	Button m_backButton;
	sf::RectangleShape m_background;
	Loader m_loader;
	
	// for now trying to see if enemy is printed
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	//---------------------------


	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	std::vector<std::unique_ptr<AnimationObject>> m_animationObjects;

	sf::Time m_energyReductionElapsedTime = sf::Time::Zero; // Elapsed time for energy reduction

	int m_levelNumber;
	bool m_levelOpen;
	bool m_levelOver = false;


	void render();
	void handleEvent();
	void levelPollEvent();
	void moveAndDrawBackground();
	void printInformation();
	void updateAnimation(sf::Time deltaTime);
	void movePlayer(sf::Time deltaTime);
	void moveMovingObjects(sf::Time deltaTime);
	void updateObjectVector();
	void checkAnimationObjectCollision(Player& player);
	void checkStaticObjectCollision(Player& player);
	bool collide(GameObject& object1, GameObject& object2);
	void handleLevelExit();
	bool checkAndUptadeLevelstatus();
	void updatePlayerEnergy(sf::Time deltaTime);
	void printFeedback(const sf::Texture& feedback/*, GameSound sound*/);
};