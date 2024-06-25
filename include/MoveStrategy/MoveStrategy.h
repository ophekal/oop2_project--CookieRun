
#include <string>
#include <memory>
#pragma once

class MoveStrategy
{
public:
	virtual ~MoveStrategy() {}
	virtual void move() = 0;
};