
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "HandleResources.h"
#include "AnimationObject/AnimationObject.h"

//----------------------------------------------------------------------------------------
InfoBar::InfoBar()
{
    // Access the font from HandleResources
    const sf::Font& font = *HandleResources::instance().getFont();
    float horizontalSpacing = 250.0f; // Adjust as needed for your layout

    // Initialize the m_infoBar with sf::Text objects
    m_infoBar.resize(4);
    std::vector<std::string> labels = {"Level: ", "Energy: ","Coins: ",  "Weapons: " };

    for (size_t i = 0; i < m_infoBar.size(); ++i)
    {
        m_infoBar[i].setFont(font);
        m_infoBar[i].setCharacterSize(30); 
        m_infoBar[i].setFillColor(sf::Color::White);
        m_infoBar[i].setPosition(50.0f + i * horizontalSpacing, 20.0f);
        m_infoBar[i].setString(labels[i]); 
    }

    // Set texture and position for the m_jelly
	m_jelly.setTexture(HandleResources::instance().getGiftTexture(G_JELLY));
    m_jelly.setSize({ 40.0f, 40.0f }); 
	m_jelly.setPosition({ 250,20 });

    // Set texture and position for the m_coin
    const sf::Texture& coinTexture = *HandleResources::instance().getGiftTexture(G_COIN);
    const std::vector<sf::IntRect>& coins = HandleResources::instance().getAnimationData(ANI_COIN);
    m_coin.setTexture(&coinTexture);
    m_coin.setTextureRect(coins[0]);
    m_coin.setSize({ 40.0f, 40.0f }); 
    m_coin.setPosition({500,20 });
}
//-----------------------------------------------------------------------------------------
void InfoBar::draw(sf::RenderWindow& window)
{
    for (const auto& text : m_infoBar)
    {
        window.draw(text);
    }
    window.draw(m_jelly);
    window.draw(m_coin);
}
//----------------------------------------------------------------------------------------
void InfoBar::updateInfoBar(const Player& player, int levelNumber)
{
    m_infoBar[0].setString("Level: " + std::to_string(levelNumber));
    m_infoBar[1].setString("Energy: " + std::to_string(player.getEnergy()));
    m_infoBar[2].setString("Coins: " + std::to_string(player.getCoins()));
    m_infoBar[3].setString("Weapons: " + std::to_string(player.getWeapons()));
}
