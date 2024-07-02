#pragma once
#include "PlayerState/PlayerState.h"
#include "Animation.h"


class FlyState : public PlayerState
{
public:
    FlyState(std::vector<sf::IntRect>& data, sf::Sprite& sprite, const sf::Time& animationTime);
    std::unique_ptr<PlayerState> handleEvent(Player& player, KeyboardInput pressed) override;
    void update(Player& player, sf::Time deltaTime) override;

private:
    sf::Time m_flyDuration;
    sf::Vector2f m_moveDirection;
    bool m_arriveToTarget = false;

    void handleInput(KeyboardInput pressed);
    void moveTowardsTarget(Player& player, sf::Time deltaTime, const sf::Vector2f& target);
    void freeMovement(Player& player, sf::Time deltaTime);
    void returnToGround(Player& player, sf::Time deltaTime);
    void resetPlayerToGround(Player& player);
    void handleFlightBehavior(Player& player, sf::Time deltaTime);
};