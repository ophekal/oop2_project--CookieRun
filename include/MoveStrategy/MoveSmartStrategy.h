#pragma once
#include "MoveStrategy/MoveStrategy.h"


class MoveSmartStrategy : public MoveStrategy
{
private:
	static bool m_register;
public:
	virtual ~MoveSmartStrategy() {}
	virtual void move(const sf::Vector2f& playerPosition, const std::vector<std::unique_ptr<StaticObject>>& staticObjects, const sf::Vector2f& enemyPosition);

};
