#pragma once
#include <string>
#include <map>
#include <memory>
#include "AnimationObject/AnimationObject.h"


using FactoryMap = std::map<std::string, std::unique_ptr<AnimationObject>(*)(const sf::Vector2f&)>;

class AnimationObjectFactory
{
public:
	static std::unique_ptr<AnimationObject> create(const std::string& name, const sf::Vector2f& position);
	static bool registerObject(const std::string& type, std::unique_ptr<AnimationObject>(*f)(const sf::Vector2f&));

private:
	static FactoryMap& getMap()
	{
		static FactoryMap m_map;
		return m_map;
	}
};
