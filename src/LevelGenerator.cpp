
#include "LevelGenerator.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include "Macros.h"


//------------------------------------------------------------------------
LevelGenerator::LevelGenerator()
{
	readLevelParts();
}

//------------------------------------------------------------------------
LevelGenerator& LevelGenerator::instance()
{
	static LevelGenerator inst;
	return inst;
}

//------------------------------------------------------------------------
void LevelGenerator::readLevelParts()
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
		throw levelPartImage.loadFromFile(line);
		readPart(levelPartImage);
	}
}

//-------------------------------------------------------------------------
void LevelGenerator::readPart(const sf::Image& levelPartImage)
{
	float location_y = 828.f;

	std::vector<LevelObject> levelSection;

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
				location_x += 120.f;
			}		
		}
		location_y -= 90.f;
	}
		
	m_levelPartsVector.emplace_back(levelSection);
}

//-----------------------------------------------------------------------------
// This function checks the what level it needs to create (according to 
// levelNumber). The m_levelPartsVector holds in the first 5 place the secrtions
// for level1, and in the next 5 it hold level2 and so on.
// This allows us to get the range of drawing sections from each level

std::vector<LevelObject> LevelGenerator::getRandomLevel(int levelNumber, sf::Vector2f& flagPosition)
{
	int lowerBound, upperBound;

	switch (levelNumber)
	{
		case 1:
		{
			lowerBound = 0;
			upperBound = 1;
			break;
		}
		case 2:
		{
			lowerBound = 2;
			upperBound = 3;
			break;
		}
		case 3:
		{
			lowerBound = 4;
			upperBound = 5;
			break;
		}
	}

	std::vector<LevelObject> currLevel;
	sf::Vector2f lastObject(0,0);		//save in order to addd the next level in the rigth place


	for (int i = 0; i < NUM_OF_PARTS_PER_LEVEL; i++) 
	{
		int randomIndex = lowerBound + std::rand() % (upperBound - lowerBound + 1);
		setLevelObjectsPosition(lastObject, randomIndex);
		currLevel.emplace_back(m_levelPartsVector[randomIndex]);
	}
	
	setLevelObjectsPosition(lastObject, m_levelPartsVector.size() - 1);
	flagPosition = lastObject;
	currLevel.emplace_back(m_levelPartsVector[m_levelPartsVector.size()]);
		
	return currLevel;
}

//-----------------------------------------------------------------------------
void LevelGenerator::setLevelObjectsPosition(sf::Vector2f& lastObject, int index)
{
	for (int i = 0; i < m_levelPartsVector[index].size(); i++)
	{
		if (i == m_levelPartsVector[index].size() - 1)
		{
			lastObject = m_levelPartsVector[index][i]._pos;
		}

		m_levelPartsVector[index][i]._pos = m_levelPartsVector[index][i]._pos + lastObject;
	}
}