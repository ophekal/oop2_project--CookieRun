
#include "LevelPartGenerator.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include "Macros.h"


//------------------------------------------------------------------------
LevelPartGenerator::LevelPartGenerator()
{
	readLevelParts();
}

//------------------------------------------------------------------------
LevelPartGenerator& LevelPartGenerator::instance()
{
	static LevelPartGenerator inst;
	return inst;
}

//------------------------------------------------------------------------
void LevelPartGenerator::readLevelParts()
{
	// open streams for reading from level parts playlist
	auto line = std::string();
	auto file = std::ifstream("levelSectionsPlaylist.txt");
	if (!file.is_open())
	{
		//throw (std::errror)
	}

	// reading the level parts from the playlist
	while (std::getline(file, line))
	{
		auto levelPartImage = sf::Image();
		levelPartImage.loadFromFile(line);
		readPart(levelPartImage);
	}
}

//-------------------------------------------------------------------------
void LevelPartGenerator::readPart(const sf::Image& levelPartImage)
{
	float location_y = 828.f;
	level levelSection;

	// read the level and insert it into vector
	for (int y = int(levelPartImage.getSize().y) - 1; y >= 0; y--)
	{
		float location_x = 0.f;
		for (int x = 0; x <int(levelPartImage.getSize().x); x++)
		{
			sf::Color pixelColor = levelPartImage.getPixel(x, y);
			if (pixelColor != sf::Color::White)
			{
				sf::Vector2f position(location_x, location_y);
				levelSection.emplace_back(pixelColor,position);
			}		
			location_x += 120.f;
		}
		location_y -= 90.f;
	}
		
	m_levelPartsVector.emplace_back(levelSection);
}

//-----------------------------------------------------------------------------
// This function checks the what level it needs to create (according to 
// levelNumber). The m_levelPartsVector holds in the first 5 place the secrtions
// for level1, and in the next 5 it hold level2 and so on.
// This allows us to draw a random level part and send it back

level& LevelPartGenerator::getRandomLevel(int levelNumber)//, sf::Vector2f& flagPosition)
{
	int lowerBound, upperBound;

	switch (levelNumber)
	{
		case 1:
		{
			lowerBound = 0;
			upperBound = 2;
			break;
		}
		case 2:
		{
			lowerBound = 0;
			upperBound = 0;
			break;
		}
		case 3:
		{
			lowerBound = 0;
			upperBound =0;
			break;
		}
	}
	
	int randomIndex = lowerBound + std::rand() % (upperBound - lowerBound + 1);
		
	return (m_levelPartsVector[randomIndex]);
}

//-----------------------------------------------------------------------------
level& LevelPartGenerator::getLastLevelSection()
{
	return m_levelPartsVector[m_levelPartsVector.size()-1];
}