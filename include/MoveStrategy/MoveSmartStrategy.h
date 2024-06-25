#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveSmartStrategy : public MoveStrategy
{
private:
	static bool m_register;
public:
	virtual ~MoveSmartStrategy() {}
	virtual void move() override; //add smart movement
};
