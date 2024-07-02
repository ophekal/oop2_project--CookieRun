
#include <memory>
#include "Factories/EnemyFactory.h"
#include "HandleResources.h"
#include "MovingObject/Enemy.h"
#include <ctime>


//-----------------------------------------------------------------------------------------------------------------------------
std::vector<moveFunc>& EnemyFactory::getMoveVec()
{
	static std::vector<moveFunc> m_moveVec;
	return m_moveVec;
}

//-----------------------------------------------------------------------------------------------------------------------------
bool EnemyFactory::registerMove(moveFunc mf)
{
	getMoveVec().emplace_back(mf);
	return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
std::unique_ptr<Enemy> EnemyFactory::createEnemy(float startX, float endX, int levelNumber)
{
	sf::Sprite sprite;
	AnimationType type;
	switch (levelNumber)
	{
	case 1:
		sprite = sf::Sprite(*HandleResources::instance().getLevel1Texture(L1_ENEMY));
		type = ANI_DEVIL_COOKIE;
		break;
	case 2:
		sprite = sf::Sprite(*HandleResources::instance().getLevel2Texture(L2_ENEMY));
		type = ANI_CARROT_COOKIE;
		break;
	case 3:
		sprite = sf::Sprite(*HandleResources::instance().getLevel3Texture(L3_ENEMY));
		type = ANI_ZOMBIE_COOKIE;
		break;
	default:
		throw std::runtime_error("Unknown level number");
	}

	auto& moveVec = getMoveVec();
	if (moveVec.empty())
	{
		throw std::runtime_error("No move strategies registered");
	}

	// Get a random move strategy
	auto movement = moveVec[std::rand() % moveVec.size()]();

	//Get random position
	sf::Vector2f position = getRandomPosition(startX, endX);

	return std::make_unique<Enemy>(sprite, 100.f, position, type, std::move(movement));
}
//-------------------------------------------------------------------------------
sf::Vector2f EnemyFactory::getRandomPosition(float startX, float endX)
{
	// Define the range for the random y-coordinate
	int minY = 180;
	int maxY = PLAYER_INIT_POSITION.y;

	// Generate a random y-coordinate within the specified range
	float randomY = minY + std::rand() % (maxY - minY + 1);

	// Generate a random x-coordinate within the specified range
	float randomX = startX + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (endX - startX)));

	// Create an enemy at a random position
	return sf::Vector2f(randomX, randomY);
}
