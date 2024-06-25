#include "Factories/StaticObjectFactory.h"

//-----------------------------------------------------------------------------------------------------------------------------
std::unique_ptr<StaticObject> StaticObjectFactory::create(const std::string& name, const sf::Vector2f& position, int levelNumber)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
	{
		return nullptr;
	}
	return it->second(position,levelNumber);
}

//-----------------------------------------------------------------------------------------------------------------------------
bool StaticObjectFactory::registerObject(const std::string& type, std::unique_ptr<StaticObject>(*f)(const sf::Vector2f&, int))
{
	getMap().emplace(type, f);
	return true;
}
