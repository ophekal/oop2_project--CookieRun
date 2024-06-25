#include "Collisions/HandleCollision.h"
#include "AnimationObject/Coin.h"
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"
#include "StaticObject/Boost.h"
#include "StaticObject/Gift.h"
#include "StaticObject/StaticObstcale.h"
#include "StaticObject/Floor.h"
#include "StaticObject/CarrotMissile.h"
#include "StaticObject/Dynamite.h"
#include "StaticObject/Weapon.h"
#include "StaticObject/Enhance.h"
#include "StaticObject/FlyingGift.h"
#include "StaticObject/JellyBean.h"
#include "StaticObject/Magnet.h"
#include "Collisions/CollisionFunctions.h"


//------------------------------------------------------------------------
HandleCollision::HandleCollision()
{
    // Inseret all the possible collisions into the HitMap.
    initializeCollisionMap();
}

//------------------------------------------------------------------------
HandleCollision& HandleCollision::instance()
{
    static HandleCollision inst;
    return inst;
}

//------------------------------------------------------------------------
void HandleCollision::initializeCollisionMap()
{
    m_collisionMap[Key(typeid(Player), typeid(Coin))] = &playerCoin;
    m_collisionMap[Key(typeid(Player), typeid(JellyBean))] = &playerJelly;
    m_collisionMap[Key(typeid(Player), typeid(StaticObstcale))] = &playerObstcale;
    m_collisionMap[Key(typeid(Player), typeid(Floor))] = &playerFloor;
    m_collisionMap[Key(typeid(Player), typeid(Enhance))] = &playerEnhance;
    //m_collisionMap[Key(typeid(Player), typeid(Dynamite))] = &playerDynamite;
   // m_collisionMap[Key(typeid(Player), typeid(Weapon))] = &playerWeapon;
    m_collisionMap[Key(typeid(Player), typeid(Boost))] = &playerBoost;
    //m_collisionMap[Key(typeid(Player), typeid(Magnet))] = &playerMagnet;
    m_collisionMap[Key(typeid(Player), typeid(FlyingGift))] = &playerFlyingGift;
    //m_collisionMap[Key(typeid(Player), typeid(CarrotMissile))] = &playerCarrotMissile;
    //m_collisionMap[Key(typeid(Player), typeid(Enemy))] = &playerEnemy;
    //m_collisionMap[Key(typeid(Enemy), typeid(Gift))] = &enemyGift;
   // m_collisionMap[Key(typeid(Enemy), typeid(Player))] = &enemyPlayer;
   // m_collisionMap[Key(typeid(Enemy), typeid(Dynamite))] = &enemyDynamite;
   // m_collisionMap[Key(typeid(Enemy), typeid(CarrotMissile))] = &enemyCarrotMissile;

    // NEED TO ADDFUNCTION THAT HANDLES ENEMY GETTING HIT BY MISSILE OF DYNAMITE EXPLODING?
}

//------------------------------------------------------------------------
HitFunctionPtr HandleCollision::findCollisionFunction(const std::type_index& class1, const std::type_index& class2)
{
    auto mapEntry = m_collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == m_collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

//------------------------------------------------------------------------
void HandleCollision::processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = findCollisionFunction(typeid(object1), typeid(object2));
    if (!phf)
    {
        return;
       // throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}