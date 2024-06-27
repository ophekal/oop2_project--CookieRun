#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include "Macros.h"


struct LevelObject {
	sf::Color _color;
	sf::Vector2f _pos;
	LevelObject(const sf::Color& color, const sf::Vector2f& pos) {
		_color = color;
		_pos = pos;
	}
};

//using level = std::vector<LevelObject>;
using levelPartsVector = std::vector<std::vector<LevelObject>>;




class LevelGenerator
{
public:
	static LevelGenerator& instance();
	std::vector<LevelObject> getRandomLevel(int levelNumber, sf::Vector2f& flagPosition);	///function that sends back a level that has been made randomly

private:
	LevelGenerator();
	void readPart(const sf::Image& levelPartImage);
	void readLevelParts(); //we will have a vector of vectors, this function reads each png picture into a vector and pushesit into the vectors vector
	void setLevelObjectsPosition(sf::Vector2f& lastObject, int index);
	levelPartsVector m_levelPartsVector;
};