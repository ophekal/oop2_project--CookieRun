
#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
//#include "StaticObject/StaticObject.h"
//#include "Animation.h"
#include "Macros.h"


class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Sprite& sprite, float speed, const sf::Vector2f& position);
	virtual ~MovingObject() = default;
	virtual void setPosition(float x, float y);
	//virtual void updateAnimation(sf::Time deltaTime) {};
	//virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
	//	const std::unique_ptr<MovingObjects>& mouse,
	//	const std::vector<std::unique_ptr<StaticObjects>>& staticObjects) = 0;
	//void move(sf::Time deltaTime);
	//void setDirection(const sf::Vector2f& direction);
	//bool isMovementValid(const sf::RectangleShape& board, const sf::RectangleShape& newPosition)const;
	//bool positionChange()const;
	sf::Vector2f getPosition()const;
	float getSpeed()const;
	//sf::Vector2f getInitPosition()const;

	//float distance(const sf::Vector2f& v1, const sf::Vector2f& v2);
	void setObjectSpeed(float speed);


protected:
	float m_objectSpeed = 80.f;		//each object will update according to the speed we will set it to

};