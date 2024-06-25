
#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "MovingObject/MovingObject.h"
//#include "StaticObject/StaticObject.h"
#include "Animation.h"
#include "Macros.h"


class AnimationObject : public MovingObject
{
public:
	//using GameObject::GameObject; // for compile
	AnimationObject(const sf::Sprite& sprite, float speed, const sf::Time& animationTime, AnimationType type, const sf::Vector2f& position);
	virtual ~AnimationObject() = default;
	//virtual void setPosition(float x, float y);
	virtual void updateAnimation(sf::Time deltaTime) {};
	//virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
	//	const std::unique_ptr<MovingObjects>& mouse,
	//	const std::vector<std::unique_ptr<StaticObjects>>& staticObjects) = 0;
	//void move(sf::Time deltaTime);
	//void setDirection(const sf::Vector2f& direction);
	//bool isMovementValid(const sf::RectangleShape& board, const sf::RectangleShape& newPosition)const;
	//bool positionChange()const;
	//sf::Vector2f getPosition()const;
	//sf::Vector2f getInitPosition()const;
	//void updatePosition(const sf::Vector2f& position);

	//float distance(const sf::Vector2f& v1, const sf::Vector2f& v2);
	//void setObjectSpeed(float speed);
	//virtual void collisionHandling(GameObjects&) = 0;
	//virtual void collisionHandling(Mouse&) = 0;
	//virtual void collisionHandling(Cat&) = 0;
	//virtual void collisionHandling(KillCatGift&) = 0;
	//virtual void collisionHandling(AddLifeGift&) = 0;
	//virtual void collisionHandling(AddTimeGift&) = 0;
	//virtual void collisionHandling(FreezeCatGift&) = 0;
	//virtual void collisionHandling(Key&) = 0;
	//virtual void collisionHandling(Cheese&) = 0;
	//virtual void collisionHandling(Door&) = 0;
	//virtual void collisionHandling(Wall&) = 0;

protected:
	//sf::Vector2f m_position;
	//sf::Vector2f m_initPosition;
	//sf::Vector2f m_direction = { 0,0 };
	//float m_objectSpeed = 80.f;		//each object will update according to the speed we will set it to
	Animation m_spriteSheet;
};