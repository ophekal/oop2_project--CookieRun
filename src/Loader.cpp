
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
	std::vector < std::unique_ptr<StaticObject>>& staticObjects, std::vector<std::unique_ptr<Enemy>>& enemies)
{
	auto image = sf::Image();
	float location_y = 828.f;

	image.loadFromFile("level1.png");

	for (int y = int(image.getSize().y) - 1; y >= 0; y--)
	{
		float location_x = 0.f;
		for (int x = 0; x <int(image.getSize().x); x++)
		{
			sf::Color pixelColor = image.getPixel(x, y);
			sf::Vector2f position(location_x, location_y);

			if (auto animationObject = ObjectFactory<AnimationObject>::create(pixelColor, position, levelNumber)) 
			{
				animationObjects.emplace_back(std::move(animationObject));
			}
			else if (auto staticObject = ObjectFactory<StaticObject>::create(pixelColor, position, levelNumber)) 
			{
				staticObjects.emplace_back(std::move(staticObject));
			}
			location_x += 120.f;
		}

		location_y -= 90.f;
	}

	//add enemy
	enemies.emplace_back(EnemyFactory::createEnemy({2000,688}, levelNumber));
	enemies.emplace_back(EnemyFactory::createEnemy({2100,688}, levelNumber));
}