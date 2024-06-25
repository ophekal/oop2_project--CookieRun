#pragma once
#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Button;

class MusicCommand : public MenuInterfaceCommand
{
public:
	MusicCommand(Button& button);
	void execute() override;

private:
	Button& m_musicButton;
	bool m_musicOn = true;
};