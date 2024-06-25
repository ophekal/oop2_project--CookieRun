#pragma once
#include <string>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>


// Custom comparator for sf::Color
struct ColorCompare
{
	bool operator()(const sf::Color& lhs, const sf::Color& rhs) const
	{
		// Compare colors based on their RGBA values
		if (lhs.r != rhs.r) return lhs.r < rhs.r;
		if (lhs.g != rhs.g) return lhs.g < rhs.g;
		if (lhs.b != rhs.b) return lhs.b < rhs.b;
		return lhs.a < rhs.a;
	}
};


template <typename T>
class ObjectFactory
{
public:
	using FactoryMap = std::map<sf::Color, std::unique_ptr<T>(*)(const sf::Vector2f&, int), ColorCompare>; 	// POSITION AND LEVEL
	static std::unique_ptr<T> create(const sf::Color& color, const sf::Vector2f& position, int levelNumber);
	static bool registerObject(const sf::Color& color, std::unique_ptr<T>(*f)(const sf::Vector2f&, int));

private:
	static FactoryMap& getMap()
	{
		static FactoryMap m_map;
		return m_map;
	}
};


//-------------------------------------------functions-----------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
template<typename T>
std::unique_ptr<T> ObjectFactory<T>::create(const sf::Color& color, const sf::Vector2f& position, int levelNumber)
{
	auto it = getMap().find(color);
	if (it == getMap().end())
	{
		return nullptr;
	}
	return it->second(position, levelNumber);
}

//---------------------------------------------------------------------------------------------------------------
template<typename T>
bool ObjectFactory<T>::registerObject(const sf::Color& color, std::unique_ptr<T>(*f)(const sf::Vector2f&, int))
{
	getMap().emplace(color, f);
	return true;
}
