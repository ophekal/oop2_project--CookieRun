#include "Factories/AnimationObjectFactory.h"

//---------------------------------------------------------------------------
std::unique_ptr<AnimationObject> AnimationObjectFactory::create(const std::string& name, const sf::Vector2f& position)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
	{
		return nullptr;
	}
	return it->second(position);
}

//---------------------------------------------------------------------------
bool AnimationObjectFactory::registerObject(const std::string& type, std::unique_ptr<AnimationObject>(*f)(const sf::Vector2f&))
{
	getMap().emplace(type, f);
	return true;
}
