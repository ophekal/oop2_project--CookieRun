//
//#include "MovingObject/Player.h"
//#include "PlayerState/EnhanceState.h"
//#include "PlayerState/RunState.h"
//
//#include <iostream>
//
//EnhanceState::EnhanceState()
//{
//}
////--------------------------------------------------------------------------------------
//PlayerState* EnhanceState::handleEvent(Player& player, KeyboardInput pressed)
//{
//    if (pressed == K_NONE)
//    {
//        return m_runState;
//    }
//    else if (pressed == K_DOWN)
//    {
//        return this;
//    }
//
//    return this;
//}
////---------------------------------------------------------------------------------------
//void EnhanceState::update(Player& player, sf::Time deltaTime)
//{
//    player.resetGravity();
//    player.setPosition(player.getPosition().x, player.getPosition().y + (player.getSize().height / 2));
//    player.move(deltaTime.asSeconds());
//
//    // m_animation.update(deltaTime);
//}
//
////--------------------------------------------------------------------------------
//void EnhanceState::setMembers(RunState& runState)
//{
//    m_runState = &runState;
//}
