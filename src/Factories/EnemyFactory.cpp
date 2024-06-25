
#include <memory>
#include "Factories/EnemyFactory.h"
#include "MovingObject/Enemy.h"
#include <ctime> // For seeding rand()


// Initialize the random seed once
namespace 
{
	struct RandInitializer 
	{
		RandInitializer() 
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
		}
	} 
	randInitializer;
}


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
//
////-----------------------------------------------------------------------------------------------------------------------------
//bool EnemyFactory::registerEnemy(const std::string& type, std::unique_ptr<Enemy>(*f)(const sf::Vector2f& position, int level))
//{
//	getMap().emplace(type, f);
//	return true;
//}

//-----------------------------------------------------------------------------------------------------------------------------
std::unique_ptr<Enemy> EnemyFactory::createEnemy(const std::string& name, const sf::Vector2f& position, int levelNumber)
{
	return NULL;	//for compile purpouses

//	return std::make_unique<Enemy>(getMoveVec()[std::rand() % getMoveVec().size()]());
}
