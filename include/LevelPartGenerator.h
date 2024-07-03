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
	level& getRandomLevel(int levelNumber);	
	level& getLastLevelSection(int levelNumber);

private:
	LevelPartGenerator();
	void readPart(const sf::Image& levelPartImage);
	void readLevelParts();
	levelPartsVector m_levelPartsVector;
	int m_lastIndex; //stores the last index that has be drawn
};