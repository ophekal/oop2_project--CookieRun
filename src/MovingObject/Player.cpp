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
	:MovingObject(sprite, speed, position),m_velocity(0,0),m_gravity(0.35)
{

    // Set the origin to center
	//sf::FloatRect bounds = m_object.getLocalBounds();
	//m_object.setOrigin(bounds.width / 2.f, bounds.height/2.f);
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
//---------------------------------------------------------------------------
void Player::startMagnetTimer(sf::Time duration)
{
	m_isMagnet= true;
	m_giftClock.restart();
	m_magnetDuration = duration;
}
////--------------------------------------------------------------------
//void Player::startEnhanceTimer(sf::Time duration, float scaleFactor)
//{
//	m_isEnhance = true;
//	m_enhanceDuration = duration;
//	m_giftClock.restart();
//
//	// Store the current position before scaling
//	sf::Vector2f originalPosition = m_object.getPosition();
//
//	// Set the origin to bottom-center
//	sf::FloatRect bounds = m_object.getLocalBounds();
//	m_object.setOrigin(bounds.width / 2.f, bounds.height);
//
//	// Apply the scale factor to enhance the player
//	m_object.setScale(m_originalScale * scaleFactor, m_originalScale * scaleFactor);
//
//	// Adjust the position to maintain contact with the ground
//	m_object.setPosition(originalPosition.x, originalPosition.y + (bounds.height /*- m_object.getLocalBounds().height*/));
//}

//------------------------------------------------------------------------
void Player::setPlayer(Players playerType)
{
	m_playerType = playerType;
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getPlayerTexture(m_playerType));
	switch (m_playerType)
	{
	case PLAYER_BRAVE:
	{
		m_currentPlayerState-> updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), sprite);
		break;
	}
	case PLAYER_BRIGHT:
	{
		m_currentPlayerState-> updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_RUN), sprite);
		break;
	}

	default:
		break;
	}
}
//-----------------------------------------------------------------
void Player::movement(sf::Time deltaTime)
{
	std::cout << m_object.getGlobalBounds().width << std::endl;
	//m_onGround = false;

	 // Update player state based on input events
	std::unique_ptr<PlayerState> nextState = m_currentPlayerState->handleEvent(*this, m_keyPressed);

	// Check if the state has changed
	if (nextState)
	{
		m_currentPlayerState = std::move(nextState);
	}
	
	m_currentPlayerState->update(*this, deltaTime);
	//m_onGround = false;

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

//-----------------------------------------------------------------------------
void Player::resetKeyPress() 
{
	m_keyPressed = K_NONE;
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
// This function preformes the cleanup for the next entry into the level.
// it resetting all the members, sets the player to run state and the animation
// according to the player type.

void Player::handleExitFromLevel()
{
	// for the next level
	AnimationType aniType = (m_playerType == PLAYER_BRAVE) ? ANI_COOKIEBRAVE_RUN : ANI_COOKIEBRIGHT_RUN;
	m_currentPlayerState = std::move(std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), m_object, sf::seconds(0.1f)));
	m_currentPlayerState->restartAnimation();
	m_object.setPosition(PLAYER_INIT_POSITION);
	m_onGround = true;
	toBeDeleted = false ;   // for the next time 
	m_energy = 100;
	m_jelly = 0;
	m_weapons = 0;
	m_objectSpeed = 350;
	m_gravity = 0.35;
	m_velocity = { 0,0 };
	m_keyPressed = K_NONE;

    m_isBoosted = false;
	m_isFlyState = false;
	m_isMagnet = false;

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
	m_velocity.x = m_objectSpeed * deltaTime;
	m_velocity.y += m_gravity;
	m_object.move(m_velocity); // was 350 before

	checkInsideWindow();
}
//-------------------------------------------------------------------
//check if the player is in the limit of the window

void Player::checkInsideWindow()
{
	if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y + 60)
	{
		SlideState* currState = dynamic_cast<SlideState*>(m_currentPlayerState.get());
		if (currState == nullptr)   //if we not in slide state
		{
			m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y);
		}
		else if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y + getSize().height)
		{
			m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y + getSize().height + 10);
		}
		setOnGround(true);
		m_velocity.y = 0;  // Reset vertical velocity when hitting the ground
		m_gravity = 0.3;
	}
	else if (m_object.getPosition().y <= 0)
	{
		m_object.setPosition(m_object.getPosition().x,0);
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
	// Check if the player is boosted and the boost duration has expired
	if (m_isMagnet && m_giftClock.getElapsedTime() >= m_magnetDuration)
	{
		m_isMagnet = false;
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
////--------------------------------------------------------------------------------
//void Player::changeEnhanceBack()
//{
//	// Reset the scale to the original
//	m_object.setScale(m_originalScale, m_originalScale);
//
//	// Reset the origin back to the top-left
//	m_object.setOrigin(0, 0);
//
//	m_isEnhance = false;
//}
//------------------------------------------------------------------------------------
void Player::changeToFlyState()
{
	m_giftClock.restart();
	m_onGround = false;
	m_isFlyState = true;
	AnimationType aniType = (m_playerType == PLAYER_BRAVE)? ANI_COOKIEBRAVE_FLY: ANI_COOKIEBRIGHT_FLY;
	m_currentPlayerState = std::move(std::make_unique<FlyState>(HandleResources::instance().getAnimationData(aniType), m_object, sf::seconds(0.3f)));
}
