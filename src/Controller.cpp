
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "MenuInterfaceCommand/ChoosePlayerCommand.h"
#include "MenuInterfaceCommand/InstructionsCommand.h"
#include "MenuInterfaceCommand/ExitCommand.h"
#include "MenuInterfaceCommand/SettingsCommand.h"
#include "MenuInterfaceCommand/StartGameCommand.h"


//-----------------------------------------------------------------
Controller::Controller()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cookie Run: OvenBreak"), m_menu(m_window),
      m_player(sf::Sprite(*HandleResources::instance().getPlayerTexture(PLAYER_BRAVE)), 350.f, PLAYER_INIT_POSITION)
{
    m_window.setFramerateLimit(60);
}


//------------------------------------------------------------------------
// This function is responsible of handling the different states while the
// window is open

void Controller::run() 
{
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_PLAYER), START_X, CHOOSEPLAYER_Y, BUTTON_SIZE), std::make_unique<ChoosePlayerCommand>(m_window, m_player));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_EXIT), EXIT_X, EXIT_Y, EXIT_SIZE), std::make_unique<ExitCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_SETTINGS), START_X, SETTINGS_Y, BUTTON_SIZE), std::make_unique<SettingsCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_INSTRUCTIONS), START_X, INSTRUCTIONS_Y, BUTTON_SIZE), std::make_unique<InstructionsCommand>(m_window));
    m_menu.addToOptions(Button(*HandleResources::instance().getButtonTexture(B_START), START_X, START_Y, BUTTON_SIZE), std::make_unique<StartGameCommand>(m_window, m_player));

    m_menu.activate();
}


////-----------------------------------------------------------------
//// Changing the state according to the state sent
//
//void Controller::setState(std::unique_ptr<GameState> state)
//{
//    currentState = std::move(state);
//}
//
////------------------------------------------------------------------------
//// this function is responsible of calling the render func of currentState
//
//void Controller::render()
//{
//    if (currentState)
//    {
//        currentState->render(*this);
//    }
//}