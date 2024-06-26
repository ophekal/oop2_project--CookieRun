
#include <memory>
#include "Factories/EnemyFactory.h"
#include "HandleResources.h"
#include "MovingObject/Enemy.h"
#include <ctime> // For seeding rand()


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
std::unique_ptr<Enemy> EnemyFactory::createEnemy(const sf::Vector2f& position, int levelNumber)
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

	// Seed std::rand once at the start of the program
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		seeded = true;
	}

	// Get a random move strategy
	//auto movement = moveVec[std::rand() % moveVec.size()]();

	return std::make_unique<Enemy>(sprite, 100.f, position, type, moveVec[std::rand() % moveVec.size()]([](playerPosition, staticObjects)));
}




//
////-----------------------------------------------------------------------------------------------------------------------------
//bool EnemyFactory::registerEnemy(const std::string& type, std::unique_ptr<Enemy>(*f)(const sf::Vector2f& position, int level))
//{
//	getMap().emplace(type, f);
//	return true;
//}