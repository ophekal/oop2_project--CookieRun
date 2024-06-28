
#include "Loader.h"
#include "AnimationObject\Coin.h"
#include "StaticObject\Floor.h"
#include "StaticObject\JellyBean.h"
#include "StaticObject\StaticObstcale.h"
#include "HandleResources.h"
#include "Factories/AnimationObjectFactory.h"
#include "Factories/StaticObjectFactory.h"
#include "Factories/ObjectFactory.h"
#include "MovingObject/Enemy.h"
#include "Factories/EnemyFactory.h"


//--------------------------------------------------------------------------------------------------------------
// This function reads the level image and according to the pixels color it calls on the appropriate factory and
// creates the object. ObjectFactory is based on pixel colors.

void Loader::updateMembers(int levelNumber, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
	std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
	std::vector< std::unique_ptr<Coin>>& coins, sf::Vector2f & flagPosition)
{

	level levelPart;

	for (int i = 0; i < NUM_OF_PARTS_PER_LEVEL; i++)
	{
		levelPart = LevelPartGenerator::instance().getRandomLevel(levelNumber);
		addObjectsToVectors(levelNumber,levelPart,animationObjects,staticObjects,enemies,coins);
	}

	auto lastLevelPart = LevelPartGenerator::instance().getLastLevelSection();
	addObjectsToVectors(levelNumber, lastLevelPart, animationObjects, staticObjects, enemies, coins);
	flagPosition = m_lastObjectPosition;
	flagPosition.x += 6000;
	m_lastObjectPosition = { 0,0 };
}

//--------------------------------------------------------------------------------------
void Loader::addObjectsToVectors(int levelNumber, level& levelPart, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
	std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
	std::vector< std::unique_ptr<Coin>>& coins)
{
	float startX =0, endX=0;

	for (size_t object = 0; object < levelPart.size(); object++)
	{
		sf::Vector2f newPosition = { levelPart[object].second.x + m_lastObjectPosition.x, levelPart[object].second.y };

		if (auto animationObject = ObjectFactory<AnimationObject>::create(levelPart[object].first, newPosition, levelNumber))
		{
			animationObjects.emplace_back(std::move(animationObject));
		}
		else if (auto staticObject = ObjectFactory<StaticObject>::create(levelPart[object].first, newPosition, levelNumber))
		{
			staticObjects.emplace_back(std::move(staticObject));
			if (object == 0)
			{
				startX = newPosition.x;
			}
		}
		else if (auto coin = ObjectFactory<Coin>::create(levelPart[object].first, newPosition, levelNumber))
		{
			coins.emplace_back(std::move(coin));
		}

		if (object == 50)
		{
			m_lastObjectPosition.x += staticObjects[object]->getObject().getPosition().x;
			endX = newPosition.x;
		}
	}

	createRandomEnemy(enemies, startX, endX, levelNumber);
	createRandomEnemy(enemies, startX, endX, levelNumber);

}

//-------------------------------------------------------------------------------
void Loader::createRandomEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, float startX, float endX, int levelNumber)
{
	// Define the range for the random y-coordinate
	int minY = 250;
	int maxY = 688;

	// Generate a random y-coordinate within the specified range
	float randomY = minY + std::rand() % (maxY - minY + 1);

	// Generate a random x-coordinate within the specified range
	float randomX = startX + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (endX - startX)));

	// Create an enemy at a random position
	enemies.emplace_back(EnemyFactory::createEnemy({ randomX, randomY },levelNumber));
}
