
#include "InfoBar.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "HandleResources.h"
#include "AnimationObject/AnimationObject.h"

//----------------------------------------------------------------------------------------
InfoBar::InfoBar()
{
    const sf::Font& font = *HandleResources::instance().getFont();
    float horizontalSpacing = 250.0f; 

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

    setInfoBarIcons();
    setGiftTexture();
}

//----------------------------------------------------------------------------------------
// This function is responsible for drawing the information and game status

void InfoBar::draw(sf::RenderWindow& window)
{
    // Draw text in the m_infoBar vector
    for (const auto& text : m_infoBar)
    {
        window.draw(text);
    }

    // Draw each icon in the m_infoBarIcons vector
    for (const auto& icon : m_infoBarIcons)
    {
        window.draw(icon);
    }

    // Draw the gifts that the player took, the ones who's boolean value is true  
    for (const auto& pair : m_gifts)
    {
        if (pair.first) 
        {
            window.draw(pair.second);
        }
    }

}

//----------------------------------------------------------------------------------------
// This function prints the status of the game and updates the boolean value inside the 
// m_gifts pair-vector that indicates with gift the player has

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

//-----------------------------------------------------------------------------------------
// This function is responsible for setting the icons for the power-ups in the infobar

 void InfoBar::setInfoBarIcons()
{
    // Initialize the m_infoBarIcons vector with the appropriate size
    m_infoBarIcons.resize(3);
    m_infoBarIcons[G_JELLY].setTexture(HandleResources::instance().getGiftTexture(G_JELLY));
    m_infoBarIcons[G_COIN].setTexture(HandleResources::instance().getGiftTexture(G_COIN));
    m_infoBarIcons[G_WEAPON].setTexture(HandleResources::instance().getGiftTexture(G_WEAPON));

    // Get animation data for coins
    const std::vector<sf::IntRect>& coins = HandleResources::instance().getAnimationData(ANI_COIN);

    // Set size and position for each icon
    for (size_t i = 0; i < m_infoBarIcons.size(); ++i)
    {
        m_infoBarIcons[i].setSize(ICON_SIZE);
        m_infoBarIcons[i].setPosition({ 250.0f + (i * 250.0f), 20.0f });

        // Apply animation texture rect for the last icon (assuming coins are the last)
        if (GIFTTEXTURE(i) == G_COIN)
        {
            m_infoBarIcons[i].setTextureRect(coins[0]);
        }
    }
}


 //-----------------------------------------------------------------------------------------
 // This function is responsible for creating the icons for the power-ups in the infobar

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