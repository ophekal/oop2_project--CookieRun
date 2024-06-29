
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

    // Set texture and position for the m_jelly
    m_weapon.setTexture(HandleResources::instance().getGiftTexture(G_WEAPON));
    m_weapon.setSize({ 40.0f, 40.0f });
    m_weapon.setPosition({ 750,20 });

    // Set texture and position for the m_coin
    const sf::Texture& coinTexture = *HandleResources::instance().getGiftTexture(G_COIN);
    const std::vector<sf::IntRect>& coins = HandleResources::instance().getAnimationData(ANI_COIN);
    m_coin.setTexture(&coinTexture);
    m_coin.setTextureRect(coins[0]);
    m_coin.setSize({ 40.0f, 40.0f }); 
    m_coin.setPosition({500,20 });

    //Set the texture of the gifts
    setGiftTexture();
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
    window.draw(m_weapon);

    // Draw gift shapes with textures
    for (const auto& pair : m_gifts)
    {
        if (pair.first) 
        {
            window.draw(pair.second);
        }
    }

}
//----------------------------------------------------------------------------------------
void InfoBar::updateInfoBar(const Player& player, int levelNumber)
{
    m_infoBar[0].setString("Level: " + std::to_string(levelNumber));
    m_infoBar[1].setString("Energy: " + std::to_string(player.getEnergy()));
    m_infoBar[2].setString("Coins: " + std::to_string(player.getCoins()));
    m_infoBar[3].setString("Weapons: " + std::to_string(player.getWeapons()));

    //check if the gifts are on
    m_gifts[0].first = player.isBoost();
    m_gifts[1].first = player.isEnhance();
    m_gifts[2].first = player.isFlyState();
    m_gifts[3].first = player.isMagnet();
}

//---------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void InfoBar::setGiftTexture()
{
    m_gifts.resize(4);

    m_gifts[0].first = false;
    m_gifts[0].second.setTexture(HandleResources::instance().getGiftTexture(G_BOOST));
    m_gifts[0].second.setSize({40.0f, 40.0f});
    m_gifts[0].second.setPosition({ 1000,20 });

    m_gifts[1].first = false;
    m_gifts[1].second.setTexture(HandleResources::instance().getGiftTexture(G_ENHANCE));
    m_gifts[1].second.setSize({ 40.0f, 40.0f });
    m_gifts[1].second.setPosition({ 1050,20 });

    m_gifts[2].first = false;
    m_gifts[2].second.setTexture(HandleResources::instance().getGiftTexture(G_FLIGHT));
    m_gifts[2].second.setSize({ 40.0f, 40.0f });
    m_gifts[2].second.setPosition({ 1100,20 });

    m_gifts[3].first = false;
    m_gifts[3].second.setTexture(HandleResources::instance().getGiftTexture(G_MAGNET));
    m_gifts[3].second.setSize({ 40.0f, 40.0f });
    m_gifts[3].second.setPosition({ 1150,20 });
}