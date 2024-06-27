#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string.h>
#include <vector>
#include "Macros.h"

using levelPartsVector = std::vector<std::vector< std::make_pair(sf::Color, sf::Vector2f)>>;


class LevelGenerator
{
public:
	static LevelGenerator& instance();

	getRandomLevel();	///function that sends back a level that has been made randomly
	readLevels(); //we will have a vector of vectors, this function reads each png picture into a vector and pushesit into the vectors vector


private:
	LevelGenerator();

	levelPartsVector m_levelPartsVector;
};