
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
	m_lastObjectPosition = { 0,0 };
}

//--------------------------------------------------------------------------------------
void Loader::addObjectsToVectors(int levelNumber, level& levelPart, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
	std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies,
	std::vector< std::unique_ptr<Coin>>& coins)
{
	for (size_t object = 0; object < levelPart.size(); object++)
	{
		if (object == levelPart.size() - 1)
		{
			m_lastObjectPosition = levelPart[object].second;
		}

		sf::Vector2f newPosition = { levelPart[object].second.x + m_lastObjectPosition.x, levelPart[object].second.y };

		if (auto animationObject = ObjectFactory<AnimationObject>::create(levelPart[object].first, newPosition, levelNumber))
		{
			animationObjects.emplace_back(std::move(animationObject));
		}
		else if (auto staticObject = ObjectFactory<StaticObject>::create(levelPart[object].first, newPosition, levelNumber))
		{
			staticObjects.emplace_back(std::move(staticObject));
		}
		else if (auto coin = ObjectFactory<Coin>::create(levelPart[object].first, newPosition, levelNumber))
		{
			coins.emplace_back(std::move(coin));
		}
	}
}
