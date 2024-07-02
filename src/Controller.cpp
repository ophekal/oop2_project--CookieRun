
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "MenuInterfaceCommand/ChoosePlayerCommand.h"
#include "MenuInterfaceCommand/InstructionsCommand.h"
#include "MenuInterfaceCommand/ExitCommand.h"
#include "MenuInterfaceCommand/SettingsCommand.h"
#include "MenuInterfaceCommand/StartGameCommand.h"


//-----------------------------------------------------------------------------------------------------
Controller::Controller()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cookie Run: OvenBreak"), m_menu(m_window),
      m_player(sf::Sprite(*HandleResources::instance().getPlayerTexture(PLAYER_BRAVE)), 350.f, PLAYER_INIT_POSITION)
{
    m_window.setFramerateLimit(60);
    setIcon();

    // play game music
    HandleResources::instance().playMusic();

    // Seed the random number generator once globally
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
}


//-----------------------------------------------------------------------------------------------------
// This function creates the buttons of the menu, and activites the menu

void Controller::run() 
{
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_PLAYER), START_X, CHOOSEPLAYER_Y, BUTTON_SIZE), std::make_unique<ChoosePlayerCommand>(m_window, m_player));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_EXIT), EXIT_X, EXIT_Y, EXIT_SIZE), std::make_unique<ExitCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_SETTINGS), START_X, SETTINGS_Y, BUTTON_SIZE), std::make_unique<SettingsCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_INSTRUCTIONS), START_X, INSTRUCTIONS_Y, BUTTON_SIZE), std::make_unique<InstructionsCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_START), START_X, START_Y, BUTTON_SIZE), std::make_unique<StartGameCommand>(m_window, m_player));

    m_menu.activate();
}

//-----------------------------------------------------------------------------------------------------
// This function sets the icon of the the game in the windows border

void Controller::setIcon()
{
   const sf::Texture* texturePtr = HandleResources::instance().getPlayerTexture(CHOOSE_PLAYER_BRAVE);

    // Create an image from the texture
    sf::Image image = texturePtr->copyToImage();

    // Get the width and height of the texture
    unsigned int width = image.getSize().x;
    unsigned int height = image.getSize().y;

    // Get the raw pixel data of the image
    const sf::Uint8* pixels = image.getPixelsPtr();

    // Set the window's icon using the image's size and pixel data
    m_window.setIcon(width, height, pixels);
}