//
//#include "MovingObject/Player.h"
//#include "PlayerState/BoostState.h"
//#include "PlayerState/RunState.h"
//
//#include <iostream>
//
//BoostState::BoostState()
//{
//}
////--------------------------------------------------------------------------------------
//PlayerState* BoostState::handleEvent(Player& player, KeyboardInput pressed)
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
//void BoostState::update(Player& player, sf::Time deltaTime)
//{
//    player.resetGravity();
//    player.setPosition(player.getPosition().x, player.getPosition().y + (player.getSize().height / 2));
//    player.move(deltaTime.asSeconds());
//
//   // m_animation.update(deltaTime);
//}
//
////--------------------------------------------------------------------------------
//void BoostState::setMembers(RunState& runState)
//{
//    m_runState = &runState;
//}
