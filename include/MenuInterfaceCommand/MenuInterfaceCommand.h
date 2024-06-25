#pragma once

class MenuInterfaceCommand 
{
public:
    virtual ~MenuInterfaceCommand() = default;
    virtual void execute() = 0;
};