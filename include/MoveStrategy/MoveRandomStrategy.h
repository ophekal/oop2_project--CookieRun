#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveRandomStrategy : public MoveStrategy
{
private:
	static bool m_register;
public:
	virtual ~MoveRandomStrategy() {}
	virtual void move() override; //add random movement, enemy walks from side to side trying when colliding with object chaninging direction
};
