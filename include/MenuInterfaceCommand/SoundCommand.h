#pragma once
#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Button;

class SoundCommand : public MenuInterfaceCommand
{
public:
	SoundCommand(Button& button);
	void execute() override;

private:
	Button& m_soundButton;
	bool m_soundOn = true;
};