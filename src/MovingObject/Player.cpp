#include "MovingObject/Player.h"
#include "Macros.h"
#include "HandleResources.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "GameObject.h"
#include "StaticObject/StaticObject.h"


#include <iostream>

//-------------------------------------------------------------------------------------------------------------
Player::Player(const sf::Sprite& sprite, float speed, const sf::Vector2f& position)
	:MovingObject(sprite, speed, position)
	//m_jump(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_JUMP), m_object, sf::seconds(0.3f)),
	//m_slide(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_SLIDE), m_object, sf::seconds(0.1f)),
	//m_fly(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_FLY), m_object, sf::seconds(0.3f)),
	//m_run(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), m_object, sf::seconds(0.1f), m_slide, m_jump),
{
	//m_jump.setMembers(m_run);
	//m_slide.setMembers(m_run);
	//m_fly.setMembers(m_run);
	//m_boost.setMembers(m_run);
	//m_enhance.setMembers(m_run);
	m_currentPlayerState = std::make_unique<RunState>(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), m_object, sf::seconds(0.1f));
	m_currentPlayerState -> restartAnimation();

}
//-------------------------------------------------------------------------------------------------
int Player::getCoins()const
{
	return m_coins;
}
//------------------------------------------------------------------------------------------------
int Player::getWeapons()const
{
	return m_weapons;
}
//-----------------------------------------------------------------------------------------------
int Player::getjelly()const
{
	return m_jelly;
}
//---------------------------------------------------------------------------------------------
void Player::setCoins(int numOfCoins)
{
	m_coins = numOfCoins;
}
//---------------------------------------------------------------------------------------
void Player::setJelly(int numOfJelly)
{
	m_jelly = numOfJelly;
}
//---------------------------------------------------------------------------
void Player::setWeapon(int numOfWeapon)
{
	m_weapons = numOfWeapon;
}

//---------------------------------------------------------------------------
void Player::startBoostTimer(sf::Time duration, float oldSpeed) 
{
	m_isBoosted = true;
	m_giftClock.restart();
	m_boostDuration = duration;
	m_oldSpeed = oldSpeed;
}
//--------------------------------------------------------------------------------------
void Player::startEnhanceTimer(sf::Time duration, float scaleFactor)
{
	m_isEnhance = true;
	m_enhanceDuration = duration;
	m_giftClock.restart();

	// Get the original position
	sf::Vector2f originalPosition = m_object.getPosition();

	// Calculate the original height before scaling
	float originalHeight = m_object.getLocalBounds().height;

	// Apply the scale factor to enhance the player
	m_object.setScale(m_originalScale * scaleFactor, m_originalScale * scaleFactor);

	// Calculate the new height after scaling
	float newHeight = m_object.getGlobalBounds().height;

	// Calculate the height change due to scaling
	float heightChange = newHeight - originalHeight;

	// Since we are using top-left as the origin, adjust the y position by the total height change
	m_object.setPosition(originalPosition.x, originalPosition.y - heightChange);


}
//-----------------------------------------------------------------
void Player::setPlayer(Players playerType)
{
	m_playerType = playerType;
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getPlayerTexture(m_playerType));
	switch (m_playerType)
	{
	case PLAYER_BRAVE:
	{
		//m_jump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_JUMP), sprite);
		//m_slide.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_SLIDE), sprite);
		//m_fly.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_FLY), sprite);
		m_currentPlayerState-> updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), sprite);
		break;
	}
	case PLAYER_BRIGHT:
	{
		//m_jump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_JUMP), sprite);
		//m_slide.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_SLIDE), sprite);
		//m_fly.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_FLY), sprite);
		m_currentPlayerState-> updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_RUN), sprite);
		break;
	}

	default:
		break;
	}
}
////-----------------------------------------------------------------
void Player::movement(sf::Time deltaTime)
{
	
	if(m_currentPlayerState->handleEvent(*this, m_keyPressed))
	{
		m_currentPlayerState = std::move((m_currentPlayerState->handleEvent(*this, m_keyPressed)));
	}
	
	m_currentPlayerState->update(*this, deltaTime);

	m_onGround = false;

}
//-----------------------------------------------------------------------------
void Player::keyPressed(sf::Event::KeyEvent key)
{
	switch (key.code)
	{
	case sf::Keyboard::Up:
	{
		m_keyPressed = K_UP;
		break;
	}
	case sf::Keyboard::Down:
	{
		m_keyPressed = K_DOWN;
		break;
	}
	case sf::Keyboard::Enter:
	{
		m_keyPressed = K_ENTER;
		break;
	}
	default:
	{
		m_keyPressed = K_NONE;
		break;
	}

	}
}
//-----------------------------------------------------------------------------
void Player::keyReleased(sf::Event::KeyEvent key)
{
	switch (key.code)
	{
	case sf::Keyboard::Up:
	case sf::Keyboard::Down:
	case sf::Keyboard::Enter:
		m_keyPressed = K_NONE;
		break;
	default:
		break;
	}
}
//--------------------------------------------------------------------------------
void Player::updateGravity(float movement)
{
	m_gravity += movement;
}
//------------------------------------------------------------------------------
bool Player::onGround()const
{
	return m_onGround;
}
//-------------------------------------------------------------------------------
void Player::setOnGround(bool onGround)
{
	m_onGround = onGround;
}
//-------------------------------------------------------------------------------
void Player::handleExitFromLevel()
{
	// for the next level
	m_currentPlayerState = std::make_unique<RunState>(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), m_object, sf::seconds(0.1f));
	m_currentPlayerState->restartAnimation();
	m_object.setPosition(PLAYER_INIT_POSITION);
	m_onGround = true;
	toBeDeleted = false ;   // for the next time 
	m_energy = 100;
	m_jelly = 0;
	m_weapons = 0;
	m_objectSpeed = 350;
	m_gravity = 0;

    m_isBoosted = false;
	//m_isEnhance = false;

	if (m_isEnhance)
	{
		changeEnhanceBack();
	}
		
}
//--------------------------------------------------------------------------------
bool Player::isDead()const
{
	if (toBeDeleted || m_energy == 0)
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------
void Player::move(float deltaTime)
{
	checkGiftDurations(deltaTime);

	m_object.move({ m_objectSpeed*deltaTime, m_objectSpeed*m_gravity*deltaTime}); // was 350 before

	if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y+60)
	{
		SlideState* currState = dynamic_cast<SlideState*>(m_currentPlayerState.get());
		if (currState == nullptr)   //if we not in slide state
		{
			m_object.setPosition(m_object.getPosition().x, 688);
		}
		else if(m_object.getPosition().y >= PLAYER_INIT_POSITION.y + getSize().height)
		{
			m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y + getSize().height+7);
		}

	}

}
//---------------------------------------------------------------
void Player::checkGiftDurations(float deltaTime)
{
	// Check if the player is boosted and the boost duration has expired
	if (m_isBoosted && m_giftClock.getElapsedTime() >= m_boostDuration)
	{
		// Reset the player's speed
		setObjectSpeed(m_oldSpeed);
		m_isBoosted = false;
	}

	// Check if the enhance duration has expired
	if (m_isEnhance && m_giftClock.getElapsedTime() >= m_enhanceDuration)
	{ 
		changeEnhanceBack();
	}

}
//-----------------------------------------------------------------------------------
void Player::changeEnhanceBack()
{
	// Calculate the original height and scaled height
	float originalHeight = m_object.getLocalBounds().height;
	float scaledHeight = originalHeight * m_object.getScale().y;

	// Calculate the height change due to scaling back to the original scale
	float heightChange = scaledHeight - originalHeight;

	// Get the current position before resetting the scale
	sf::Vector2f currentPosition = m_object.getPosition();

	// Revert the scale to the original
	m_object.setScale(m_originalScale, m_originalScale);

	// Adjust the y position back to maintain the top-left corner position
	// Subtract the heightChange to compensate for scaling down
	m_object.setPosition(currentPosition.x, currentPosition.y + heightChange);

	m_isEnhance = false;

}
//------------------------------------------------------------------------------------
void Player::changeToFlyState()
{
	m_giftClock.restart();
	AnimationType aniType = (m_playerType == PLAYER_BRAVE)? ANI_COOKIEBRAVE_FLY: ANI_COOKIEBRIGHT_FLY;
	m_currentPlayerState =  std::make_unique<FlyState>(HandleResources::instance().getAnimationData(aniType), m_object, sf::seconds(0.3f));
}
