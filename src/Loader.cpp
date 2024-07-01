
#include "Loader.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"
#include "MovingObject/Enemy.h"
#include "Factories/EnemyFactory.h"
#include "MenuInterfaceCommand/LevelCommand.h"


//--------------------------------------------------------------------------------------------------------------
// This function reads the level image and according to the pixels color it calls on the appropriate factory and
// creates the object. ObjectFactory is based on pixel colors.

void Loader::updateMembers(LevelCommand& currLevel)
{
	level levelPart;

	for (int i = 0; i < NUM_OF_PARTS_PER_LEVEL; i++)
	{
		levelPart = LevelPartGenerator::instance().getRandomLevel(currLevel.getLevelNumber());
		addObjectsToVectors(currLevel,levelPart);
	}

	auto lastLevelPart = LevelPartGenerator::instance().getLastLevelSection(currLevel.getLevelNumber());
	addObjectsToVectors(currLevel, lastLevelPart);
	currLevel.setFlagPosition(m_lastObjectPosition);
	m_lastObjectPosition = { 0,0 };
}


//---------------------------------------------------------------------------------------
// This function goes over the level that was generated and adds the objects in the level
// into the level's vectors

void Loader::addObjectsToVectors(LevelCommand& currLevel, const level& levelPart)
{
	float startX = 0, endX = 0;
	float lastPositionX = 0;

	for (size_t object = 0; object < levelPart.size(); object++)
	{
		sf::Vector2f newPosition = { levelPart[object].second.x + m_lastObjectPosition.x, levelPart[object].second.y };

		if (auto animationObject = ObjectFactory<AnimationObject>::create(levelPart[object].first, newPosition, currLevel.getLevelNumber()))
		{
			currLevel.addToAnimationObjectVector(std::move(animationObject));
		}
		else if (auto staticObject = ObjectFactory<StaticObject>::create(levelPart[object].first, newPosition, currLevel.getLevelNumber()))
		{
			currLevel.addToStaticObjectVector(std::move(staticObject));
			if (object == 0)
			{
				startX = newPosition.x+ PLAYER_INIT_POSITION.x+ 350;
			}
		}
		else if (auto coin = ObjectFactory<Coin>::create(levelPart[object].first, newPosition, currLevel.getLevelNumber()))
		{
			currLevel.addToCoinsVector(std::move(coin));
		}

		if (object == POSITION_OF_LAST_FLOOR)
		{
			lastPositionX = currLevel.getLastFloorXPosition(object);
		}
	}

	m_lastObjectPosition.x += lastPositionX;
    endX = m_lastObjectPosition.x;

	createEnemeis(currLevel, startX, endX);
}
//------------------------------------------------------------------------------
void Loader::createEnemeis(LevelCommand& currLevel, float startX, float endX)
{
	float randomNumOfEnemies = 0 + std::rand() % (ENEMIES_PER_LEVEL - 0 + 1);

	for (int i = 0; i < randomNumOfEnemies; i++)
	{
		createRandomEnemy(currLevel, startX, endX);
	}
}
//-------------------------------------------------------------------------------
void Loader::createRandomEnemy(LevelCommand& currLevel, float startX, float endX)
{
	// Define the range for the random y-coordinate
	int minY = 180;
	int maxY = PLAYER_INIT_POSITION.y;

	// Generate a random y-coordinate within the specified range
	float randomY = minY + std::rand() % (maxY - minY + 1);

	// Generate a random x-coordinate within the specified range
	float randomX = startX + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (endX - startX)));

	// Create an enemy at a random position
	currLevel.addToEnemiesVector(randomX, randomY);
}
