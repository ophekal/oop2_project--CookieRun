#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveSmartStrategy : public MoveStrategy
{
public:
	virtual ~MoveSmartStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, Enemy& enemy) override;

private:
	static bool m_register;

};
