#pragma once
#include <string>
#include <map>
#include <memory>
#include "StaticObject/StaticObject.h"


using FactoryStaticMap = std::map<std::string, std::unique_ptr<StaticObject>(*)(const sf::Vector2f&, int)>;

class StaticObjectFactory
{
public:
	static std::unique_ptr<StaticObject> create(const std::string& name, const sf::Vector2f& position, int levelNumber);
	static bool registerObject(const std::string& type, std::unique_ptr<StaticObject>(*f)(const sf::Vector2f&, int));

private:
	static FactoryStaticMap& getMap()
	{
		static FactoryStaticMap m_map;
		return m_map;
	}
};
