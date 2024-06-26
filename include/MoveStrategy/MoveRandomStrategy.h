#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveRandomStrategy : public MoveStrategy
{
private:
	static bool m_register;
	int m_direction;

public:
	MoveRandomStrategy();
	virtual ~MoveRandomStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, Enemy& enemy);
};
