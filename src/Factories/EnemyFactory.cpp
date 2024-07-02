
#include <memory>
#include "Factories/EnemyFactory.h"
#include "HandleResources.h"
#include "MovingObject/Enemy.h"
#include <ctime>


//--------------------------------------------------------------------------------------------
std::vector<moveFunc>& EnemyFactory::getMoveVec()
{
	static std::vector<moveFunc> m_moveVec;
	return m_moveVec;
}

//--------------------------------------------------------------------------------------------
bool EnemyFactory::registerMove(moveFunc mf)
{
	getMoveVec().emplace_back(mf);
	return true;
}

//--------------------------------------------------------------------------------------------
// This function is responsible of generating a random enemy according to the level number

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

//--------------------------------------------------------------------------------------------
// This function is responsible of drawing a random position for the enemy

sf::Vector2f EnemyFactory::getRandomPosition(float startX, float endX)
{
	int minY = 180;
	int maxY = PLAYER_INIT_POSITION.y;
	float randomY = minY + std::rand() % (maxY - minY + 1);
	float randomX = startX + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (endX - startX)));
	return sf::Vector2f(randomX, randomY);
}
