#pragma once
#include "MenuInterfaceCommand/MenuInterfaceCommand.h"
#include <SFML/Graphics.hpp>
#include <memory>


class BackCommand : public MenuInterfaceCommand
{
public:
	BackCommand() = default;
	void execute() override { return; };
};