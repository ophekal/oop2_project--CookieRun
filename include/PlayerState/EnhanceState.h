//#pragma once
//
//#include "PlayerState/PlayerState.h"
//#include "Animation.h"
//
//class RunState;
//
//class EnhanceState : public PlayerState
//{
//public:
//    EnhanceState();
//    PlayerState* handleEvent(Player& player, KeyboardInput pressed);
//    void update(Player& player, sf::Time deltaTime);
//    void setMembers(RunState& runState);
//
//private:
//    sf::Time m_enhanceDuration= sf::seconds(5);;
//    RunState* m_runState;
//
//};