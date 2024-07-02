
#include "Loader.h"
#include "HandleResources.h"
#include "Factories/ObjectFactory.h"
#include "MovingObject/Enemy.h"
#include "Factories/EnemyFactory.h"
#include "MenuInterfaceCommand/LevelCommand.h"


//--------------------------------------------------------------------------------------------------------------
// This function reads the level section image and according to the pixel's color it calls on the factory of the 
// appropriate type and creates the object. ObjectFactory is a factory that's based on pixel colors.

void Loader::updateMembers(LevelCommand& currLevel)
{
	level levelPart;

	for (int i = 0; i < NUM_OF_PARTS_PER_LEVEL; i++)
	{
		levelPart = LevelPartGenerator::instance().getRandomLevel(currLevel.getLevelNumber());
		addObjectsToVectors(currLevel,levelPart);
	}

	level& lastLevelPart = LevelPartGenerator::instance().getLastLevelSection(currLevel.getLevelNumber());
	addObjectsToVectors(currLevel, lastLevelPart);
	currLevel.setFlagPosition(m_lastObjectPosition);
	m_lastObjectPosition = { 0,0 };
}


//---------------------------------------------------------------------------------------
// This function goes over the level part that was generated and adds the objects into
// the level's vectors by calling on the appropriate functions from levelCommand.
// It calls on a function that creates enemies randomly in this section

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

//-----------------------------------------------------------------------------
// This function randomly creates the enemies in the level section by drawing 
// the number of enemies in the current section and by sending the enemyFactory
// a range of positions from which it creates them

void Loader::createEnemeis(LevelCommand& currLevel, float startX, float endX)
{
	float randomNumOfEnemies = 0 + std::rand() % (ENEMIES_PER_LEVEL - 0 + 1);

	for (int i = 0; i < randomNumOfEnemies; i++)
	{
		currLevel.addToEnemiesVector(startX, endX);
	}
}
