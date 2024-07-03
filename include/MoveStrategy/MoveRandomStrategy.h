#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveRandomStrategy : public MoveStrategy
{
public:
	MoveRandomStrategy();
	virtual ~MoveRandomStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, Enemy& enemy) override;

private:
	static bool m_register;
	int m_direction;
	sf::Clock m_clock;
	sf::Time m_timeSinceLastChange;
};
