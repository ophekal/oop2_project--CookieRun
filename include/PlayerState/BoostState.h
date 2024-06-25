
//#pragma once
//
//#include "PlayerState/PlayerState.h"
//#include "Animation.h"
//
//class RunState;
//
//class BoostState : public PlayerState
//{
//public:
//    BoostState();
//    PlayerState* handleEvent(Player& player, KeyboardInput pressed);
//    void update(Player& player, sf::Time deltaTime);
//    void setMembers(RunState& runState);
//
//private:
//    float m_oldSpeed;
//    sf::Time m_boostDuration = sf::seconds(5);;
//    RunState* m_runState;
//
//};