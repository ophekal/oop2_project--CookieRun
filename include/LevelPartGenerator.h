#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include "Macros.h"


using level = std::vector<std::pair<sf::Color, sf::Vector2f>>;
using levelPartsVector = std::vector<level>;


class LevelPartGenerator
{
public:
	static LevelPartGenerator& instance();
	level& getRandomLevel(int levelNumber);//, sf::Vector2f& flagPosition);	///function that sends back a level that has been made randomly
	level& getLastLevelSection();

private:
	LevelPartGenerator();
	void readPart(const sf::Image& levelPartImage);
	void readLevelParts(); //we will have a vector of vectors, this function reads each png picture into a vector and pushesit into the vectors vector
	//void setLevelObjectsPosition(sf::Vector2f& lastObject, int index);
	levelPartsVector m_levelPartsVector;
};