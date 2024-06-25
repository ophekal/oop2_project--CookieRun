#pragma once
#include "StaticObject/StaticObject.h"

class StaticObstcale : public StaticObject
{
public:
	StaticObstcale(const sf::Sprite& sprite, const sf::Vector2f& position);
private:
	static bool m_register;
};


//class StaticObstacle : public StaticObject 
//{
//public:
//    /*enum class obstcaleType 
//    {
//        obstacle1,
//        obstacle2,
//        obstacle3
//    };*/
//
//    StaticObstcale(const sf::Sprite& sprite, const sf::Vector2f& position);
//
//private:
//    static bool m_register;
//   // obstcaleType m_type;
//};