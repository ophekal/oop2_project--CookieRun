#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <map>
#include "Macros.h"
#include "GameObject.h"

using HitFunctionPtr = void (*)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

class HandleCollision
{
public:

	static HandleCollision& instance();
	HitFunctionPtr findCollisionFunction(const std::type_index& class1, const std::type_index& class2);
	void processCollision(GameObject& object1, GameObject& object2);

	
private:
	HandleCollision();
	//void addCollsion(GameObject& object1, GameObject& object2);
	void initializeCollisionMap();
	HitMap m_collisionMap;
};