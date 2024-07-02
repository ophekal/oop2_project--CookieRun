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
	:MovingObject(sprite, speed, position), m_velocity(0, 0), m_gravity(0.35)
{
	// Set the origin to center
	sf::FloatRect bounds = m_object.getLocalBounds();
	m_object.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	m_currentPlayerState = std::make_unique<RunState>(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), m_object, sf::seconds(0.1f));
	m_currentPlayerState->restartAnimation();
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

	sf::Vector2f originalPosition = m_object.getPosition();
	float originalHeight = m_object.getLocalBounds().height;

	// Apply the scale factor to enhance the player
	m_object.setScale(m_originalScale * scaleFactor, m_originalScale * scaleFactor);
	float newHeight = m_object.getGlobalBounds().height;
	float heightChange = newHeight - originalHeight;

	// Since we are using top-left as the origin, adjust the y position by the total height change
	m_object.setPosition(originalPosition.x, originalPosition.y - (heightChange / 2));//+ 30);
}

//--------------------------------------------------------------------------------------
void Player::startMagnetTimer(sf::Time duration)
{
	m_isMagnet = true;
	m_giftClock.restart();
	m_magnetDuration = duration;
}

//--------------------------------------------------------------------------------------
void Player::setPlayer(Players playerType)
{
	m_playerType = playerType;
	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getPlayerTexture(m_playerType));
	switch (m_playerType)
	{
		case PLAYER_BRAVE:
		{
			m_currentPlayerState->updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), sprite);
			break;
		}
		case PLAYER_BRIGHT:
		{
			m_currentPlayerState->updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_RUN), sprite);
			break;
		}
	}
}

//--------------------------------------------------------------------------------------
// This function is responisble for of updating the players state according to the key
// that has been pressed

void Player::movement(sf::Time deltaTime)
{
	std::unique_ptr<PlayerState> nextState = m_currentPlayerState->handleEvent(*this, m_keyPressed);
	if (nextState)
	{
		m_currentPlayerState = std::move(nextState);
	}
	m_currentPlayerState->update(*this, deltaTime);
}

//--------------------------------------------------------------------------------------
// This function checks what key has been pressed and according to that updates the
// variable m_keyPressed

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

//--------------------------------------------------------------------------------------
// This function updates checks which key has been released and changes m_keyPressed to 
// K_NONE is set to m_keyPressed

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

//--------------------------------------------------------------------------------------
void Player::resetKeyPress()
{
	m_keyPressed = K_NONE;
}

//--------------------------------------------------------------------------------------
void Player::updateGravity(float movement)
{
	m_gravity += movement;
}

//--------------------------------------------------------------------------------------
bool Player::onGround()const
{
	return m_onGround;
}

//--------------------------------------------------------------------------------------
void Player::setOnGround(bool onGround)
{
	m_onGround = onGround;
}

//--------------------------------------------------------------------------------------
// This function preformes all the cleanup and prepears the player for the next level
// entery. It resetts all the members, sets the player to run state and the animation
// to match the player type and state.

void Player::handleExitFromLevel()
{
	AnimationType aniType = (m_playerType == PLAYER_BRAVE) ? ANI_COOKIEBRAVE_RUN : ANI_COOKIEBRIGHT_RUN;
	m_currentPlayerState = std::move(std::make_unique<RunState>(HandleResources::instance().getAnimationData(aniType), m_object, sf::seconds(0.1f)));
	m_currentPlayerState->restartAnimation();
	m_object.setPosition(PLAYER_INIT_POSITION);
	
	m_energy = FULL_ENERGY;
	m_jelly = 0;
	m_weapons = 0;
	m_objectSpeed = 350;
	m_gravity = 0.35;
	m_velocity = { 0,0 };
	m_keyPressed = K_NONE;

	m_onGround = true;
	toBeDeleted = false;
	m_isBoosted = false;
	m_isFlyState = false;
	m_isMagnet = false;

	if (m_isEnhance)
	{
		changeEnhanceBack();
	}
}

//--------------------------------------------------------------------------------------
// This function checks if the player is dead

bool Player::isDead()const
{
	if (toBeDeleted || m_energy <= 0)
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------------
// This function is responsible for moving the player according to his status

void Player::move(float deltaTime)
{
	//checking if the player has a gift that is about to expire
	checkGiftDurations(deltaTime);
	m_velocity.x = m_objectSpeed * deltaTime;

	if (!m_onGround)
	{
		m_velocity.y += m_gravity; // Apply gravity if not on the ground
	}
	else
	{
		m_velocity.y = 0; // Reset vertical velocity when on the ground
	}

	m_object.move(m_velocity);
	checkInsideWindow();

}

//--------------------------------------------------------------------------------------
// This function checks if the player is in the limits of the window

void Player::checkInsideWindow()
{
	if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y +60)
	{
		if (m_keyPressed != K_DOWN && !m_isFlyState)   //if we are not in slide state
		{
			if (!m_isEnhance)
			{
				m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y +20);
			}
		}
		else if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y + getSize().height)
		{
			m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y + getSize().height +20);
		}
		setOnGround(true);
		m_velocity.y = 0;  // Reset vertical velocity when hitting the ground
		m_gravity = 0.3;
	}
	else
	{
		setOnGround(false); // Player is not on the ground
	}

	if (m_object.getPosition().y <= (m_object.getGlobalBounds().height / 2) + 10)
	{
		m_object.setPosition(m_object.getPosition().x, (m_object.getGlobalBounds().height / 2) + 10);
	}
}

//--------------------------------------------------------------------------------------
// This function is responsible of checing if the gift durations have expired

void Player::checkGiftDurations(float deltaTime)
{
	if (m_isBoosted && m_giftClock.getElapsedTime() >= m_boostDuration)
	{
		setObjectSpeed(m_oldSpeed);
		m_isBoosted = false;
	}

	if (m_isEnhance && m_giftClock.getElapsedTime() >= m_enhanceDuration)
	{
		changeEnhanceBack();
	}

	if (m_isMagnet && m_giftClock.getElapsedTime() >= m_magnetDuration)
	{
		m_isMagnet = false;
	}
}

//--------------------------------------------------------------------------------------
// This function performs all the calculations in order to set the scale back to its
// original state once leaving Enhance mode

void Player::changeEnhanceBack()
{
	// Calculate the original height and scaled height
	float originalHeight = m_object.getLocalBounds().height;
	float scaledHeight = originalHeight * m_object.getScale().y;
	float heightChange = scaledHeight - originalHeight;

	// Get the current position before resetting the scale
	sf::Vector2f currentPosition = m_object.getPosition();

	// Revert the scale to the original
	m_object.setScale(m_originalScale, m_originalScale);

	// Adjust the y position back to maintain the top-left corner position
	// Subtract the heightChange to compensate for scaling down
	m_object.setPosition(currentPosition.x, currentPosition.y + (heightChange / 2)- 30);

	m_isEnhance = false;

}

//--------------------------------------------------------------------------------------
void Player::changeToFlyState()
{
	m_giftClock.restart();
	m_onGround = false;
	m_isFlyState = true;
	AnimationType aniType = (m_playerType == PLAYER_BRAVE) ? ANI_COOKIEBRAVE_FLY : ANI_COOKIEBRIGHT_FLY;
	m_currentPlayerState = std::move(std::make_unique<FlyState>(HandleResources::instance().getAnimationData(aniType), m_object, sf::seconds(0.3f)));
}

//--------------------------------------------------------------------------------------
float Player::getGravity()const 
{ 
	return m_gravity; 
}

//--------------------------------------------------------------------------------------
int Player::getEnergy()const 
{ 
	return m_energy; 
}

//--------------------------------------------------------------------------------------
KeyboardInput Player::getKeyPressed()const 
{ 
	return m_keyPressed;
}

//--------------------------------------------------------------------------------------
sf::Vector2f Player::getVelocity()const
{ 
	return m_velocity;
}

//--------------------------------------------------------------------------------------
const sf::Clock& Player::getGiftClock()const 
{
	return m_giftClock; 
}

//--------------------------------------------------------------------------------------
Players Player::getPlayerType()const
{ 
	return m_playerType; 
}

//--------------------------------------------------------------------------------------
sf::Sprite& Player::getPlayerSpriteForAnimation()
{ 
	return m_object; 
}

//--------------------------------------------------------------------------------------
void Player::setGravity(float gravity) 
{ 
	m_gravity = gravity; 
}

//--------------------------------------------------------------------------------------
void Player::setEnergy(int energy) 
{ 
	m_energy = energy; 
}

//--------------------------------------------------------------------------------------
void Player::setIsFlyState(bool fly) 
{ 
	m_isFlyState = fly; 
}

//--------------------------------------------------------------------------------------
void Player::move(const sf::Vector2f& position) 
{ 
	m_object.move(position); 
}

//--------------------------------------------------------------------------------------
bool Player::isEnhance()const 
{ 
	return m_isEnhance; 
}

//--------------------------------------------------------------------------------------
bool Player::isBoost()const 
{ 
	return m_isBoosted; 
}

//--------------------------------------------------------------------------------------
bool Player::isMagnet()const 
{ 
	return m_isMagnet; 
}

//--------------------------------------------------------------------------------------
bool Player::isFlyState()const 
{ 
	return m_isFlyState; 
}

//--------------------------------------------------------------------------------------
void Player::resetGravity() 
{ 
	m_gravity = 0; 
}

//--------------------------------------------------------------------------------------
void Player::setVelocityY(float y) 
{ 
	m_velocity.y = y; 
};
