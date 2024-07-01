
#include "MenuInterfaceCommand/SoundCommand.h"
#include "HandleResources.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------------------------------------------
SoundCommand::SoundCommand(Button& button)
	:m_soundButton(button) {}

//-------------------------------------------------------------------------------------
void SoundCommand::execute()
{
	if (m_soundOn)
	{
		m_soundOn = false;
		m_soundButton.setButtonTexture(HandleResources::instance().getButtonTexture(B_SOUND_OFF));
	}
	else
	{
		m_soundOn = true;
		m_soundButton.setButtonTexture(HandleResources::instance().getButtonTexture(B_SOUND_ON));
	}

	HandleResources::instance().updateSoundOn(m_soundOn);
}
