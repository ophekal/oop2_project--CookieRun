
#include "Loader.h"
#include "AnimationObject\Coin.h"
#include "StaticObject\Floor.h"
#include "StaticObject\JellyBean.h"
#include "StaticObject\StaticObstcale.h"
#include "HandleResources.h"
#include "Factories/AnimationObjectFactory.h"
#include "Factories/StaticObjectFactory.h"

//--------------------------------------------------------------------
void Loader::updateMembers(int levelNumber, std::vector < std::unique_ptr<AnimationObject>>& animationObjects,
	std::vector < std::unique_ptr<StaticObject>>& staticObjects)
{
	// add magnet, boom, enemy, flybean, enhance, etc...

	auto image = sf::Image();
	float location_y = 828.f;

	image.loadFromFile("level1.png");

	for (int y = int(image.getSize().y) - 1; y >= 0; y--)
	{
		float location_x = 0.f;
		for (int x = 0; x <int(image.getSize().x); x++)
		{
			sf::Color pixelColor = image.getPixel(x, y);

			if (pixelColor == sf::Color(0, 0, 0))	//black- floor
			{
				sf::Vector2f position(location_x, location_y);
				auto floor = StaticObjectFactory::create("floor", position, levelNumber);
				if (floor)
				{
					staticObjects.emplace_back(std::move(floor));
				}
			}
			else if (pixelColor == sf::Color(200, 191, 231))	//light purple- enhance
			{
				sf::Vector2f position(location_x, location_y);
				auto enhance = StaticObjectFactory::create("enhance", position, levelNumber);
				if (enhance)
				{
					staticObjects.emplace_back(std::move(enhance));
				}
			}
			else if (pixelColor == sf::Color(34, 177, 76))	//green- obstcale
			{
				//I NEED TO BE ABLE TO CHANGE DIFFERENT SPRITES!!!
				sf::Vector2f position(location_x, location_y);
				auto obstcale = StaticObjectFactory::create("obstcale", position, levelNumber);
				//obstcaleType type = obstcale1;
				if (obstcale)
				{
					staticObjects.emplace_back(std::move(obstcale));
				}
			}
			else if (pixelColor == sf::Color(0, 162, 232))	//blue- obstcale FORK BLOCK
			{
				sf::Vector2f position(location_x, location_y);
				auto obstcale = StaticObjectFactory::create("obstcale", position, levelNumber);
				if (obstcale)
				{
					staticObjects.emplace_back(std::move(obstcale));
				}
			}
			else if (pixelColor == sf::Color(163, 73, 164))	//purple- obstcale
			{
				sf::Vector2f position(location_x, location_y);
				auto obstcale = StaticObjectFactory::create("obstcale", position, levelNumber);
				if (obstcale)
				{
					staticObjects.emplace_back(std::move(obstcale));
				}
			}
			else if (pixelColor == sf::Color(234, 63, 247))	//pink- jelly
			{
				sf::Vector2f position(location_x, location_y);
				auto jelly = StaticObjectFactory::create("jelly", position, levelNumber);
				if (jelly)
				{
					staticObjects.emplace_back(std::move(jelly));
				}
			}
			else if (pixelColor == sf::Color(255,127,39))	//orange- boost
			{
				sf::Vector2f position(location_x, location_y);
				auto boost = StaticObjectFactory::create("boost", position, levelNumber);
				if (boost)
				{
					staticObjects.emplace_back(std::move(boost));
				}
			}
			else if (pixelColor == sf::Color(136, 0,21))	//dark red- flyingGift
			{
				sf::Vector2f position(location_x, location_y);
				auto fly = StaticObjectFactory::create("flyingGift", position, levelNumber);
				if (fly)
				{
					staticObjects.emplace_back(std::move(fly));
				}
			}
			else if (pixelColor == sf::Color(255, 242, 0))	//yellow- coins
			{
				sf::Vector2f position(location_x, location_y);
				auto coin = AnimationObjectFactory::create("coin", position);
				if (coin)
				{
					animationObjects.emplace_back(std::move(coin));
				}
			}
			location_x += 120.f;
		}
		location_y -= 90.f;
	}
}