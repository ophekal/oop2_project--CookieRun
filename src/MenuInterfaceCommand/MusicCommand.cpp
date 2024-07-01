
#include "MenuInterfaceCommand/MusicCommand.h"
#include "HandleResources.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------------------------------------------
MusicCommand::MusicCommand(Button& button)
	:m_musicButton(button) {}

//-------------------------------------------------------------------------------------
void MusicCommand::execute()
{
	if (m_musicOn)
	{
		m_musicOn = false;
		HandleResources::instance().stopMusic();
		m_musicButton.setButtonTexture(HandleResources::instance().getButtonTexture(B_MUSIC_OFF));
	}
	else
	{
		m_musicOn = true;
		HandleResources::instance().playMusic();
		m_musicButton.setButtonTexture(HandleResources::instance().getButtonTexture(B_MUSIC_ON));
	}
}
