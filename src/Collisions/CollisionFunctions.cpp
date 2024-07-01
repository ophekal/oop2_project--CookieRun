#include "Collisions/CollisionFunctions.h"
#include "AnimationObject/Coin.h"
#include "MovingObject/Player.h"
#include "MovingObject/Enemy.h"
#include "StaticObject/Boost.h"
#include "StaticObject/Floor.h"
#include "StaticObject/Gift.h"
#include "StaticObject/StaticObstcale.h"
#include "AnimationObject/MovingObstcale.h"
#include "StaticObject/Weapon.h"
#include "StaticObject/Enhance.h"
#include "StaticObject/FlyingGift.h"
#include "StaticObject/JellyBean.h"
#include "StaticObject/Magnet.h"
#include "HandleResources.h"
#include "Macros.h"

//------------------------------------------------------------
void playerCoin(GameObject& player, GameObject& coin)
{
    Player& p = static_cast<Player&>(player);
    Coin& c = static_cast<Coin&>(coin);
    p.setCoins(p.getCoins() + 1);
    HandleResources::instance().playSound(S_COIN);
    c.markForDeletion();
}

//------------------------------------------------------------
void playerJelly(GameObject& player, GameObject& jelly)
{
    Player& p = static_cast<Player&>(player);
    JellyBean& j = static_cast<JellyBean&>(jelly);
    p.setJelly(p.getjelly() + 1);
    j.markForDeletion();
    HandleResources::instance().playSound(S_JELLY);

    if (p.getjelly() == JELLY2ENERGY)
    {
        if (p.getEnergy() < 100)
        {
            p.setEnergy(p.getEnergy() + 1);
            p.setJelly(p.getjelly() - JELLY2ENERGY);
        }
        else if (p.getEnergy() == 100)
        {
            p.setJelly(0);
        }
    }
}

//------------------------------------------------------------
// Handeling the collision of the player and the floor by setting the
// player to stand on top of the floor

void playerFloor(GameObject& player, GameObject& floor)
{
    Player& p = static_cast<Player&>(player);

    // getting the top of the floor's rectangle
    auto floorBounds = floor.getObject().getGlobalBounds();
    auto playerBounds = p.getObject().getGlobalBounds();

    // Check if the player is above the floor
    bool playerAboveFloor = (playerBounds.top + (playerBounds.height / 2) - 5 <= floorBounds.top);
    bool playerCollidingFromBottom = (playerBounds.left < floorBounds.left + floorBounds.width &&
        playerBounds.left + playerBounds.width > floorBounds.left);

    // checking if player collides with floor from the top
    if (playerAboveFloor && playerCollidingFromBottom)
    {
        if (!p.isFlyState())
        {
            std::cout << "collision from above\n";
            // Player is above the floor and colliding from the bottom
            auto newPlayerYPosition = floorBounds.top - (p.getSize().height / 2) + 20;
            p.setPosition(p.getPosition().x, newPlayerYPosition);
            p.setOnGround(true);
            p.resetGravity();
        }

    }
    // if the collision is from the side
    else if (!p.isEnhance())
    {
        std::cout << "collision from the side\n";
        HandleResources::instance().playSound(S_COOKIEDEAD);
        p.markForDeletion();
        return;
    }

}
//------------------------------------------------------------
void playerObstcale(GameObject& player, GameObject& obstcale)
{
    Player& p = static_cast<Player&>(player);

    if (!p.isEnhance())   // if not in enhance the player die when collide with obstcale
    {
        HandleResources::instance().playSound(S_COOKIEDEAD);
        p.markForDeletion();
    }

}

//------------------------------------------------------------
void playerEnhance(GameObject& player, GameObject& enhance)
{
    Player& p = static_cast<Player&>(player);
    Enhance& e = static_cast<Enhance&>(enhance);
    e.markForDeletion();

    // Set the boost duration
    sf::Time enhanceDuration = sf::seconds(5);

    HandleResources::instance().playSound(S_GIFT);

    // Start the boost timer
    p.startEnhanceTimer(enhanceDuration, 1.4f);
}

//------------------------------------------------------------
void playerWeapon(GameObject& player, GameObject& weapon)
{
    Player& p = static_cast<Player&>(player);
    Weapon& w = static_cast<Weapon&>(weapon);
    w.markForDeletion();
    HandleResources::instance().playSound(S_GIFT);
    p.setWeapon(p.getWeapons() + 1);
}

//------------------------------------------------------------
void playerBoost(GameObject& player, GameObject& boost)
{
    Player& p = static_cast<Player&>(player);
    Boost& b = static_cast<Boost&>(boost);
    b.markForDeletion();

    float oldSpeed = p.getSpeed();

    // Increase the player's speed
    float boostedSpeed = oldSpeed * 2.0f; // Boost speed by 50%
    p.setObjectSpeed(boostedSpeed);

    // Set the boost duration (5 seconds)
    sf::Time boostDuration = sf::seconds(5);

    HandleResources::instance().playSound(S_GIFT);

    // Start the boost timer
    p.startBoostTimer(boostDuration, oldSpeed);
}

//------------------------------------------------------------
void playerMagnet(GameObject& player, GameObject& magnet)
{
    Player& p = static_cast<Player&>(player);
    Magnet& m = static_cast<Magnet&>(magnet);
    m.markForDeletion();
    sf::Time magnetDuration = sf::seconds(10);

    HandleResources::instance().playSound(S_GIFT);

    // Start the boost timer
    p.startMagnetTimer(magnetDuration);
}

//------------------------------------------------------------
void playerFlyingGift(GameObject& player, GameObject& flyingGift)
{
    Player& p = static_cast<Player&>(player);
    FlyingGift& f = static_cast<FlyingGift&>(flyingGift);
    f.markForDeletion();
    p.changeToFlyState();

    HandleResources::instance().playSound(S_GIFT);
}

//------------------------------------------------------------
void playerEnemy(GameObject& player, GameObject& enemy)
{
    Player& p = static_cast<Player&>(player);
    Enemy& e = static_cast<Enemy&>(enemy);

    // if player isn't in enhance and collided with enemy
    if (!p.isEnhance())
    {
        HandleResources::instance().playSound(S_COOKIEDEAD);
        std::cout << "enemy kill the player\n";
        p.markForDeletion();
    }
}
//--------------------------------------------------------
void playerMovingObstcale(GameObject& player, GameObject& obstcale)
{
    Player& p = static_cast<Player&>(player);
    MovingObstcale& m = static_cast<MovingObstcale&>(obstcale);

    // checking if player isn't in enhance and if collided with obstcale
    if (!p.isEnhance())
    {
        HandleResources::instance().playSound(S_COOKIEDEAD);
        std::cout << "obstcale kill the player\n";
        p.markForDeletion();
    }
}